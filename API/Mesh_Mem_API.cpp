//
// Created by nickotronz7 on 16/09/16.
//

#include "xReference.h"
#include <rapidjson/document.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <zconf.h>
#include "Mesh_Mem_API.h"

using namespace rapidjson;

char* hostIP = "127.0.0.1";
int hostPort = 1011;

//char* token = initialize(hostIP, hostPort);

/**
 * Se hace un contacto con el manager para asi conseguir un token
 * para todas la comunicaciones posteriores
 * @param host_name
 * @param host_port
 * @return token
 */
char* initialize(char* host_name, int host_port)
{

    struct sockaddr_in my_addr;

    char buffer[1024];
    int bytecount;
    int buffer_len=0;

    int hsock;
    int * p_int;
    int err;

    /**
     * Abre el socket
     */
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

    /**
     * Establece una coneccion con el manager
     */
    if( connect( hsock, (struct sockaddr*)&my_addr, sizeof(my_addr)) == -1 )
    {
        if((err = errno) != EINPROGRESS)
        {
            fprintf(stderr, "Error connecting socket %d\n", errno);
            initialize(host_name, host_port);
        }
    }

    /**
     * Recive el token para las demas comunicacciones
     */
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

/**
 *
 * @param size
 * @param type
 * @return xReference instance que contiene el ID, size, type
 */
template <typename xType>
xReference<xType> xMalloc(int size, xType type)
{
    xReference<xType> Ref();
    Ref().setSize(size);
    Ref().setType(type);
    return Ref();
}

/**
 * Igual que la anterior pero recibe el value que es un apuntador
 * hacia el valor a copiar
 * @param size
 * @param type
 * @param value
 * @return xReference instance que contiene el ID, size, type
 */
template <typename xType>
xReference<xType> xMalloc(int size, xType type, void* value)
{
    xReference<xType> Ref();
    Ref().setSize(size);
    Ref().setType(type);
    free(value);
    return Ref();
}

/**
 * Asigna el valor al espacio apuntado por reference y lo libera despues de eso
 * @param reference
 * @param value
 */
template <typename xType>
void xAssing(xReference<xType> reference, void* value)
{
    const char json[] = "{ \"Reference\" : \"reference\", \"Value\" : value }";
    char buffer[1024];
    memcpy(buffer, json, sizeof(json));
}

/**
 * Contacta al Manager para liberar el espacio de memoria indicado
 * @param toFree
 */
template <typename xType>
void xFree(xReference<xType> toFree)
{

}