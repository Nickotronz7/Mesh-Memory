//
// Created by nickotronz7 on 16/09/16.
//

#ifndef MESH_MEMORY_XREFERENCE_H
#define MESH_MEMORY_XREFERENCE_H


#include <clocale>
#include <uuid/uuid.h>
#include <cstdlib>

template <class xType> class xReference
{
public:

    void* operator * (const xReference& reference) const;
    bool operator == (const xReference& reference) const;
    int operator = (int& ref_num) const;
    bool operator != (const xReference& reference) const;


    void getID() const;
    int getSize() const;
    void setSize(int size);
    xType getType() const;
    void setType(xType type);
    void* getValue() const;
    void setID(uuid_t id);

/**
 * ID: Identificador de memoria dentro del Mesh Memory
 * size: tamaño del dato almacenado
 * type: tipo del dato almacenado
 * value: puntero al espacio de memoria que contiene el valor a almacenar
 */
private:
    uuid_t ID;
    int size;
    xType type;
    void* value;

};


/**
 * Retorna el size
 * @return
 */
template  <class xType>
int xReference<xType>::getSize() const
{
    return size;
}

/**
 * Modifica el atributo size
 * @param nsize
 */
template <class xType>
void xReference<xType>::setSize(int nsize)
{
    this->size = nsize;
}

/**
 * Retorna el tipo de dato apuntado por la xReference
 * @return value
 */
template <class xType>
xType xReference<xType>::getType() const
{
    return type;
}

/**
 * Cambia la etiqueta del tipo de dato
 * @param ntype
 */
template <class xType>
void xReference<xType>::setType(xType ntype)
{
    this->type = ntype;
}

/**
 * Retorna el ID del xReference que es lo que dice el lugar donde se almacena
 * @return
 */
template <class xType>
void xReference<xType>::getID() const
{

}

template <class xType>
void* xReference<xType>::getValue() const
{
    return value;
}

template <class xType>
void xReference<xType>::setID(unsigned char *id)
{
    for (int i = 0; i < sizeof(id); ++i)
    {
        this->ID[i] = id[i];
    }
}

#endif //MESH_MEMORY_XREFERENCE_H