//
// Created by nickotronz7 on 30/09/16.
//

#include "Json.h"
#include <rapidjson/document.h>

using namespace rapidjson;
using namespace std;

Document Json::create()
{
    char json[] = "{\"TipoAcion\" : \"0\", \"token\" : 512}";
    Document document;
    document.Parse(json);
    return document;
}