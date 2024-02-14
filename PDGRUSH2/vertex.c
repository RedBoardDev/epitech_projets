/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"

typedef struct
{
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg((*args), int);
    this->y = va_arg((*args), int);
    this->z = va_arg((*args), int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

static int get_int_size(int a)
{
    int out = 0;
    if (a < 0) {
        ++out;
        a *= -1;
    }
    if (a == 0)
        return 1;
    while (a > 0) {
        a /= 10;
        ++out;
    }
    return out;
}

static char *Vertex_str(VertexClass *this)
{
    char *str = malloc(sizeof(char) * (9 + get_int_size(this->x) + 2 +
get_int_size(this->y) + 2 + get_int_size(this->z) + 3));
    sprintf(str, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);

    return (str);
}

static Object *Vertex_add(VertexClass *p1, VertexClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    Object *out; 
    int x = p1->x + p2->x;
    int y = p1->y + p2->y;
    int z = p1->z + p2->z;

    out = malloc(Vertex->__size__);
    memcpy(out, Vertex, Vertex->__size__);

    ((VertexClass *)(out))->x = x;
    ((VertexClass *)(out))->y = y;
    ((VertexClass *)(out))->z = z;
    return (out);
}

static Object *Vertex_sub(VertexClass *p1, VertexClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    Object *out;
    int x = p1->x - p2->x;
    int y = p1->y - p2->y;
    int z = p1->z - p2->z;

    out = malloc(Vertex->__size__);
    memcpy(out, Vertex, Vertex->__size__);

    ((VertexClass *)(out))->x = x;
    ((VertexClass *)(out))->y = y;
    ((VertexClass *)(out))->z = z;
    return (out);
}

// Create additional functions here

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Vertex_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Vertex_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;
