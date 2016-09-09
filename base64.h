//
// Created by nicko on 9/09/16.
//

#ifndef MESH_MEMORY_BASE64_H
#define MESH_MEMORY_BASE64_H
#include <string>

using namespace std;

string encode(unsigned char const*, unsigned int len);
string decode(string const& code);

#endif //MESH_MEMORY_BASE64_H
