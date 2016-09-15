#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>

using namespace std;
using namespace rapidjson;

void* SocketHandler(void*);

sockaddr_in sadr;

void server(){

    int host_port= 1101;

    struct sockaddr_in my_addr;

    int hsock;
    int * p_int ;
    int err;

    socklen_t addr_size = 0;
    int* csock;
    //sockaddr_in sadr;
    pthread_t thread_id=0;


    hsock = socket(AF_INET, SOCK_STREAM, 0);
    if(hsock == -1){
        printf("Error iniciando el socket %d\n", errno);
         ;
    }

    p_int = (int*)malloc(sizeof(int));
    *p_int = 1;

    if( (setsockopt(hsock, SOL_SOCKET, SO_REUSEADDR, (char*)p_int, sizeof(int)) == -1 )||
        (setsockopt(hsock, SOL_SOCKET, SO_KEEPALIVE, (char*)p_int, sizeof(int)) == -1 ) ){
        printf("Error al setear las opciones %d\n", errno);
        free(p_int);
         ;
    }
    free(p_int);

    my_addr.sin_family = AF_INET ;
    my_addr.sin_port = htons(host_port);

    memset(&(my_addr.sin_zero), 0, 8);
    my_addr.sin_addr.s_addr = INADDR_ANY ;

    if( bind( hsock, (sockaddr*)&my_addr, sizeof(my_addr)) == -1 ){
        fprintf(stderr,"Error uniendo al socket, asegurece de que el puerto esta libre %d\n",errno);
         ;
    }
    if(listen( hsock, 10) == -1 ){
        fprintf(stderr, "Error al escuchar %d\n",errno);
         ;
    }

    //Now lets do the Server stuff

    addr_size = sizeof(sockaddr_in);

    while(true){
        printf("Esperando una Conexion\n");
        csock = (int*)malloc(sizeof(int));
        if((*csock = accept( hsock, (sockaddr*)&sadr, &addr_size))!= -1){
            printf("---------------------\nConexion recivida de %s\n",inet_ntoa(sadr.sin_addr));
            pthread_create(&thread_id,0,&SocketHandler, (void*)csock );
            pthread_detach(thread_id);
        }
        else{
            fprintf(stderr, "Error al aceptar conexion %d\n", errno);
        }
    }
}

void* SocketHandler(void* lp) {
    int *csock = (int *) lp;

    int buffer_len = 1024;
    char buffer[buffer_len];
    int bytecount;

    memset(buffer, 0, buffer_len);

    if ((bytecount = recv(*csock, buffer, buffer_len, 0)) == -1) {
        fprintf(stderr, "Error al recivir data %d\n", errno);
    }
/*
    Document document;
    document.Parse(buffer);

    {
        Value& a = document["a"];   // This time we uses non-const reference.
        Document::AllocatorType& allocator = document.GetAllocator();
        for (int i = 5; i <= 10; i++)
            a.PushBack(i, allocator);
    }

    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);
    document.Accept(writer);
    puts(sb.GetString());
*/

    printf("Bytes recividos %d\nMensaje recivido \"%s\"\nDe %s\n", bytecount, buffer,inet_ntoa(sadr.sin_addr));
    strcat(buffer, " SERVER ECHO");


    if((bytecount = send(*csock, buffer, strlen(buffer), 0))== -1){
        fprintf(stderr, "Error al responder data %d\n", errno);
         ;
    }

    
    printf("Sent bytes %d\n", bytecount);


       
    free(csock);
}