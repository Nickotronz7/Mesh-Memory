//
// Created by nickotronz7 on 16/09/16.
//

#include "xReference.h"
#include <rapidjson/document.h>

using namespace rapidjson;

char* initialize(char* host, int port)
{
    const char json[] = " { \"token\" : \"NULL\" } ";
    Document document;
    document.Parse(json);
}

template <typename xType>
xReference<xType> xMalloc(int size, xType type)
{

}

/*void xAssing(xReference reference, void* value)
{

}

void xFree(xReference toFree)
{

}
*/