//
// Created by nicko on 14/09/16.
//

#include<stdio.h>
#include<string.h>    //strlen
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr
#include<unistd.h>    //write

void client()
{
    int sock;
    struct sockaddr_in server;
    char buffer[1024];
    int buffer_len = 1024;

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 1101 );

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
    }

    puts("Connected\n");

    //keep communicating with server
    while(1)
    {
        const char json[] = " { \"hello\" : \"world\", \"t\" : true , \"f\" : false, \"n\": null, \"i\":123, \"pi\": 3.1416, \"a\":[1, 2, 3, 4] } ";
        memcpy(buffer,json,buffer_len);
        //buffer[strlen(buffer)-1]='\0';

        //Send some data
        if( send(sock , buffer , strlen(buffer) , 0) < 0)
        {
            puts("Send failed");
        }

        //Receive a reply from the server
        if( recv(sock , buffer , buffer_len , 0) == -1)
        {
            puts("recv failed");
            break;
        }

        puts("Server reply :");
        puts(buffer);
        break;
    }

    close(sock);
}