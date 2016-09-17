//
// Created by nickotronz7 on 16/09/16.
//

#ifndef MESH_MEMORY_MESH_MEM_API_H
#define MESH_MEMORY_MESH_MEM_API_H

#include "xReference.h"


template <class xType>
class Mesh_Mem_API
{
public:
    char* initialize(char* host, int port);
    xReference<xType> xMalloc(int size, xType type);
    xReference<xType> xMalloc(int size, xType type, void* value);

    /*
    bool xAssing(xReference reference, void* value);
    bool xFree(xReference toFree);
    */

};


#endif //MESH_MEMORY_MESH_MEM_API_H
