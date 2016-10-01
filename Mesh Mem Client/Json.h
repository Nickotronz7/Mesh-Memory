//
// Created by nickotronz7 on 30/09/16.
//

#ifndef MESH_MEMORY_JSON_H
#define MESH_MEMORY_JSON_H

#include <rapidjson/document.h>

using namespace rapidjson;
using namespace std;

class Json {

public:
    Document create();
    void edit_mem(Document* json, int n_token, int n_size, string n_type, string n_ID);

};


#endif //MESH_MEMORY_JSON_H
