//
// Created by nicko on 29/08/16.
//

#ifndef MESH_MEMORY_SOCKETSERVER_H
#define MESH_MEMORY_SOCKETSERVER_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <thread>
#include <vector>
#include <unistd.h>

using namespace std;


struct dataSocket
{
    int descriptor;
    sockaddr_in info;
};


class socketServer
{
public:
    socketServer();
    void run();
    void setMensaje(const char* msj);

private:
    int descriptor;
    sockaddr_in info;
    bool crear_Socket();
    bool ligar_OS();
    static void* controlerClient(void* obj);
    vector<int> clientsConectados;
};


#endif //MESH_MEMORY_SOCKETSERVER_H
