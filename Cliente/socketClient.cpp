//
// Created by nicko on 30/08/16.
//

#include "socketClient.h"

using namespace std;

socketClient::socketClient()
{

}

bool socketClient::conectar()
{
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (descriptor < 0)
        return false;
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = inet_addr("localhost");
    info.sin_port = ntohs(5822);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));

    if((connect(descriptor,(sockaddr*)&info,(socklen_t)sizeof(info))) < 0)
        return false;
    pthread_t hilo;

    pthread_create(&hilo,0,socketClient::controlerClient,(void *)this);
    pthread_detach(hilo);
    return true;
}

void* socketClient::controlerClient(void *obj)
{

    socketClient *padre = (socketClient*) obj;
    while(true)
    {
        string mensaje;
        while (1)
        {
            char buffer[10];
            int bytes = recv(padre->descriptor, buffer, 10, 0);
            mensaje.append(buffer, bytes);
            if (bytes <= 0)
            {
                close(padre->descriptor);
                pthread_exit(NULL);
            }
            if (bytes < 10)
                break;
        }
        cout << mensaje << endl;
        close(padre->descriptor);
        pthread_exit(NULL);
    }

}

void socketClient::setMensaje(const char *msj)
{
    cout << "bytes enviados " << send(descriptor,msj,strlen(msj),0) << endl;
}