/**
 * Created by Nickotronz7
 */

#include <iostream>
#include "../Mesh Mem Client/client.h"
#include "../API/Mesh_Mem_API.h"
#include "../API/xReference.h"
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>
#include <uuid/uuid.h>

//using namespace rapidjson;
using namespace std;

int main()
{

    /*
    int Max_Size = 1024;
    char json[] = "{\n"
            "    \"Nicko\": \"Guapo\", \n"
            "    \"glossary\": {\n"
            "        \"title\": \"example glossary\",\n"
            "\t\t\"GlossDiv\": {\n"
            "            \"title\": \"S\",\n"
            "\t\t\t\"GlossList\": {\n"
            "                \"GlossEntry\": {\n"
            "                    \"ID\": \"SGML\",\n"
            "\t\t\t\t\t\"SortAs\": \"SGML\",\n"
            "\t\t\t\t\t\"GlossTerm\": \"Standard Generalized Markup Language\",\n"
            "\t\t\t\t\t\"Acronym\": \"SGML\",\n"
            "\t\t\t\t\t\"Abbrev\": \"ISO 8879:1986\",\n"
            "\t\t\t\t\t\"GlossDef\": {\n"
            "                        \"para\": \"A meta-markup language, used to create markup languages such as DocBook.\",\n"
            "\t\t\t\t\t\t\"GlossSeeAlso\": [\"GML\", \"XML\"]\n"
            "                    },\n"
            "\t\t\t\t\t\"GlossSee\": \"markup\"\n"
            "                }\n"
            "            }\n"
            "        }\n"
            "    }\n"
            "}";
    Document document;
    char buffer[sizeof(json)];
    memcpy(buffer,json,sizeof(json));
    document.Parse(json);
    cout << document["Nicko"].GetString() << endl;
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);
    document.Accept(writer);
    puts(sb.GetString());
     */
    //server();
    //client();



    char* hostIP = "127.0.0.1";
    int hostPort = 1011;


    //char* token = initialize(hostIP, hostPort);

    /*
    uuid_t id;
    uuid_generate(id);

    char *string = new char[100];
    uuid_unparse(id, string);

    cout << string << endl;
    */

    return 0;
}