//
// Created by nickotronz7 on 16/09/16.
//

#include "xReference.h"
#include <rapidjson/document.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <zconf.h>

using namespace rapidjson;

char* initialize(char* host_name, int host_port)
{
//////////////////////////////////////////////////
    /*
    char json[] = " { \"token\" : \"NULL\" } ";
    char buffer[sizeof(json)];
    memcpy(buffer,json,sizeof(json));
    buffer[sizeof(json) - 1 ] = 0;
     */
//////////////////////////////////////////////////

    struct sockaddr_in my_addr;

    char buffer[1024];
    int bytecount;
    int buffer_len=0;

    int hsock;
    int * p_int;
    int err;

    hsock = socket(AF_INET, SOCK_STREAM, 0);
    if(hsock == -1)
    {
        printf("Error initializing socket %d\n",errno);
        initialize(host_name, host_port);
    }

    p_int = (int*)malloc(sizeof(int));
    *p_int = 1;

    if( (setsockopt(hsock, SOL_SOCKET, SO_REUSEADDR, (char*)p_int, sizeof(int)) == -1 )||
        (setsockopt(hsock, SOL_SOCKET, SO_KEEPALIVE, (char*)p_int, sizeof(int)) == -1 ) )
    {
        printf("Error setting options %d\n",errno);
        free(p_int);
        initialize(host_name, host_port);
    }
    free(p_int);

    my_addr.sin_family = AF_INET ;
    my_addr.sin_port = htons(host_port);

    memset(&(my_addr.sin_zero), 0, 8);
    my_addr.sin_addr.s_addr = inet_addr(host_name);

    if( connect( hsock, (struct sockaddr*)&my_addr, sizeof(my_addr)) == -1 )
    {
        if((err = errno) != EINPROGRESS)
        {
            fprintf(stderr, "Error connecting socket %d\n", errno);
            initialize(host_name, host_port);
        }
    }

    if ((bytecount = recv(hsock, buffer, buffer_len, 0)) == -1)
    {
        fprintf(stderr, "Error reciving data %d\n", errno);
        initialize(host_name, host_port);
    }else{
        char* token = &buffer[0];
        return token;
    }
    close(hsock);
}

template <typename xType>
xReference<xType> xMalloc(int size, xType type)
{

}

template <typename xType>
xReference<xType> xMalloc(int size, xType type, void* value)
{

}

template <typename xType>
void xAssing(xReference<xType> reference, void* value)
{

}

template <typename xType>
void xFree(xReference<xType> toFree)
{

}