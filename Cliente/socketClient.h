//
// Created by nicko on 30/08/16.
//

#ifndef MESH_MEMORY_SOCKETCLIENT_H
#define MESH_MEMORY_SOCKETCLIENT_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <thread>
#include <unistd.h>
#include <arpa/inet.h>


using namespace std;


class socketClient {

public:
    socketClient();
    void setMensaje(const char* msj);

    bool conectar();
private:
    int descriptor;
    sockaddr_in info;
    static void* controlerClient(void* obj);

};


#endif //MESH_MEMORY_SOCKETCLIENT_H
