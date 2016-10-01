//
// Created by nickotronz7 on 30/09/16.
//

#include "Json.h"
#include <rapidjson/document.h>

using namespace rapidjson;
using namespace std;

Document Json::create()
{
<<<<<<< HEAD
    char json[] = "{\"TipoAcion\" : \"0\", \"token\" : 512}";
    Document document;
    document.Parse(json);
    return document;
=======
    char json[] = "{\"Token\" : \"0\", \"Size\" : \"0\", \"Type\" : \"0\", \"ID\" : \"0\"}";
    Document document;
    document.Parse(json);
}

void Json::edit_mem(Document* json, int n_token, int n_size, string n_type, string n_ID)
{
    json["Token"] = n_token;
    json["Size"] = n_size;
    json["Type"] = n_type;
    json["ID"] = n_ID;
>>>>>>> origin/master
}