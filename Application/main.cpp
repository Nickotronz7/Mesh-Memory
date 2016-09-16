/**
 * Created by Nickotronz7
 */

#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>
#include <iostream>
#include "../Mesh Mem Manager/server.h"


using namespace std;
using namespace rapidjson;



int main(int, char*[]) {

/*
    Document json;
    json.SetObject();

    rapidjson::Document::AllocatorType& allocator = json.GetAllocator();

    size_t size = allocator.Size();

    json.AddMember("Nickotronz7", true, allocator);
    json.AddMember("ChrisRC7", true, allocator);
    json.AddMember("Ulfrancito", true, allocator);

    Value Descri(kArrayType);
    Value obj(kObjectType);
    Value obj2(kObjectType);
    Value value(kObjectType);

    obj.AddMember("Cantidad", 3, allocator);

    string description = "Son los mejores del mundo";
    value.SetString(description.c_str(), static_cast<SizeType>(description.length()));
    obj.AddMember("Description", value, allocator);

    Descri.PushBack(obj, allocator);

    obj2.AddMember("Prueba", ":D", allocator);
    Descri.PushBack(obj2, allocator);
    json.AddMember("Pruebas", Descri, allocator);

    StringBuffer jsonStr;
    PrettyWriter<StringBuffer> writer(jsonStr);
    json.Accept(writer);

    puts(jsonStr.GetString());
    */

    server();

    return 0;
}