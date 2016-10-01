//
// Created by nickotronz7 on 27/09/16.
//

#ifndef MESH_MEMORY_MESH_MEM_API_H
#define MESH_MEMORY_MESH_MEM_API_H

#include "../API/xReference.h"

char* initialize(char* host_name, int host_port);
template <typename xType>
xReference<xType> xMalloc(int size, xType type);
template <typename xType>
xReference<xType> xMalloc(int size, xType type, void* value);
template <typename xType>
void xAssing(xReference<xType> reference, void* value);
template <typename xType>
void xFree(xReference<xType> toFree);

#endif //MESH_MEMORY_MESH_MEM_API_H
