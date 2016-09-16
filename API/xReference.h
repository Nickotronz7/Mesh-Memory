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
    int operator= (int& ref_num, int num) const;
    bool operator != (const xReference& refer) const;

    int getSize() const;
    void setSize(int size);
    xType getType() const;
    void setType(xType type);

private:
    float ID;
    int size;
    xType type;

};

template <class xType>
xReference<xType>::xReference()
{
    this->ID;
    this->size;
    this->type;
}

template  <class xType>
int xReference<xType>::getSize() const
{
    return size;
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



#endif //MESH_MEMORY_XREFERENCE_H
