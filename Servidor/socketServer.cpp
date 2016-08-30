//
// Created by nicko on 29/08/16.
//

#include "socketServer.h"

socketServer::socketServer()
{

}


bool socketServer::crear_Socket()
{
    descriptor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (descriptor < 0)
        return false;
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = INADDR_ANY;
    info.sin_port = htons(5822);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));
    return true;
}

bool socketServer::ligar_OS()
{
    if((bind(descriptor, (sockaddr *)&info,(socklen_t)sizeof(info))) < 0)
        return false;

    listen(descriptor, 5);
    return true;
}

void socketServer::run()
{
    if(!crear_Socket())
        throw string("Error al crear el Socket");
    if(!ligar_OS())
        throw string("Error al ligar el OS");

    while (true)
    {
        dataSocket data;
        socklen_t  tam = sizeof(data.info);
        data.descriptor = accept(descriptor, (sockaddr*)&data.info, &tam );
        if (data.descriptor < 0)
        {
            cout << "Error al acceptar al cliente" << endl;
        }else{
            clientsConectados.push_back(data.descriptor);
            pthread_t hilo;
            // Se pasan los parametos asi para evitar cualquier inconveniente
            pthread_create(&hilo, 0, socketServer::controlerClient, (void*)&data);
            pthread_detach(hilo);
        }
    }
    close(descriptor);
}


void* socketServer::controlerClient(void *obj)
{
    dataSocket* data = (dataSocket*)obj;
    while(true)
    {
        //Aqui se guarda lo que se va a recivir
        string mensaje;
        while (1)
        {
            char buffer[10];
            int bytes = recv(data->descriptor, buffer, 10, 0);
            mensaje.append(buffer, bytes);
            if (bytes <= 0)
            {
                close(data->descriptor);
                pthread_exit(NULL);
            }
            if (bytes < 10)
                break;
        }
        cout << mensaje << endl;
        close(data->descriptor);
        pthread_exit(NULL);
    }
}

void socketServer::setMensaje(const char *msj)
{
    for (int i = 0; i < clientsConectados.size(); ++i)
    {
        cout << "bytes enviados" << send(clientsConectados[i],msj,strlen(msj),0);
    }
}