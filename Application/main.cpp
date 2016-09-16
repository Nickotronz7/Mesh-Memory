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

template <class xType> class Example
{
public:
    xType producto(xType x, xType y);
    xType add(xType x, xType y);
};

template <class xType> xType Example<xType>::producto(xType x, xType y)
{
    return x*y;
}

template <class xType> xType Example<xType>::add(xType x, xType y)
{
    return x+y;
}
int main()
{

    Example<int> holint;
    Example<float> holif;

    cout << holint.add(2, 19) << endl;
    cout << holif.add(3.14, 2.17) << endl;
    cout << holint.producto(2, 19) << endl;
    cout << holif.producto(3.14, 2.17) << endl;


    server();

    return 0;
}