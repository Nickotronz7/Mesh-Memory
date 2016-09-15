// Hello World example
// This example shows basic usage of DOM-style API.

#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON
#include <cstdio>
#include <iostream>
#include "Servidor/server.h"

using namespace rapidjson;
using namespace std;

int main(int, char*[]) {

    server();

    return 0;
}