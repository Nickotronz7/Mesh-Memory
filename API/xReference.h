//
// Created by nickotronz7 on 16/09/16.
//

#ifndef MESH_MEMORY_XREFERENCE_H
#define MESH_MEMORY_XREFERENCE_H


#include <clocale>

template <class xType> class xReference
{
public:
    xReference();



    int operator * (const xReference& refer) const;
    bool operator == (const xReference& refer) const;
    int operator = (int& ref_num) const;
    bool operator != (const xReference& refer) const;


    float getID() const;
    int getSize() const;
    void setSize(int size);
    xType getType() const;
    void setType(xType type);
    xType getValue() const;

private:
    float ID;
    int size;
    xType type;
    xType value;

};
/*
template <class xType>
xReference<xType>::xReference()
{
    this->ID = NULL;
    this->size = NULL;
    this->type = NULL;
}
*/
template  <class xType>
int xReference<xType>::getSize() const
{
    return size;
}

template <class xType>
xType xReference<xType>::getValue() const
{
    return value;
}

template <class xType>
void xReference<xType>::setSize(int nsize)
{
    this->size = nsize;
}

template <class xType>
xType xReference<xType>::getType() const
{
    return type;
}

template <class xType>
void xReference<xType>::setType(xType ntype)
{
    this->type = ntype;
}

template <class xType>
float xReference<xType>::getID() const
{
    return ID;
}

#endif //MESH_MEMORY_XREFERENCE_H
