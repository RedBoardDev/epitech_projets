/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "float.h"

typedef struct
{
    Class   base;
    float     x;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->x = va_arg((*args), double);
}

static void Float_dtor(FloatClass *this)
{
    (void)this;
}

static int get_float_size(float a)
{
    return 10;
}

static char *Float_str(FloatClass *this)
{
    char *str = malloc(sizeof(char) * (8 + get_float_size(this->x) + 3));
    sprintf(str, "<Float (%f)>", this->x);

    return (str);
}

static Object *Float_add(FloatClass *p1, FloatClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    Object *out;
    float x = p1->x + p2->x;

    out = malloc(Float->__size__);
    memcpy(out, Float, Float->__size__);

    ((FloatClass *)(out))->x = x;
    return (out);
}

static Object *Float_sub(FloatClass *p1, FloatClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    Object *out;
    float x = p1->x - p2->x;

    out = malloc(Float->__size__);
    memcpy(out, Float, Float->__size__);

    ((FloatClass *)(out))->x = x;
    return (out);
}

static Object *Float_mul(FloatClass *p1, FloatClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    Object *out;
    float x = p1->x * p2->x;

    out = malloc(Float->__size__);
    memcpy(out, Float, Float->__size__);

    ((FloatClass *)(out))->x = x;
    return (out);
}


static Object *Float_div(FloatClass *p1, FloatClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    if (p2->x == 0)
        raise("divide by 0");
    Object *out;
    float x = p1->x / p2->x;

    out = malloc(Float->__size__);
    memcpy(out, Float, Float->__size__);

    ((FloatClass *)(out))->x = x;
    return (out);
}

static bool Float_eq(FloatClass *p1, FloatClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    return (p1->x == p2->x);
}

static bool Float_lt(FloatClass *p1, FloatClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    return (p1->x < p2->x);
}

static bool Float_gt(FloatClass *p1, FloatClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    return (p1->x > p2->x);
}
// Create additional functions here

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Float_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Float_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt,
    },
    .x = 0,
};

const Class   *Float = (const Class *)&_description;
