/**
 * Created by Nickotronz7
 */

#include <gtk-3.0/gtk/gtk.h>
#include <iostream>
#include "../Mesh Mem Client/client.h"
#include "../Mesh Mem Manager/server.h"
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/prettywriter.h>

using namespace rapidjson;

int main()
{
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
    //server();
    //client();

    return 0;
}