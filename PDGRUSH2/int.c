/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "int.h"

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg((*args), int);
}

static void Int_dtor(IntClass *this)
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

static char *Int_str(IntClass *this)
{
    char *str = malloc(sizeof(char) * (6 + get_int_size(this->x) + 3));
    sprintf(str, "<Int (%d)>", this->x);

    return (str);
}

static Object *Int_add(IntClass *p1, IntClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    Object *out;
    int x = p1->x + p2->x;

    out = malloc(Int->__size__);
    memcpy(out, Int, Int->__size__);

    ((IntClass *)(out))->x = x;
    return (out);
}

static Object *Int_sub(IntClass *p1, IntClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    Object *out;
    int x = p1->x - p2->x;

    out = malloc(Int->__size__);
    memcpy(out, Int, Int->__size__);

    ((IntClass *)(out))->x = x;
    return (out);
}

static Object *Int_mul(IntClass *p1, IntClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    Object *out;
    int x = p1->x * p2->x;

    out = malloc(Int->__size__);
    memcpy(out, Int, Int->__size__);

    ((IntClass *)(out))->x = x;
    return (out);
}

static Object *Int_div(IntClass *p1, IntClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    if (p2->x == 0)
        raise("divide by 0");
    Object *out;
    int x = p1->x / p2->x;

    out = malloc(Int->__size__);
    memcpy(out, Int, Int->__size__);

    ((IntClass *)(out))->x = x;
    return (out);
}

static bool Int_eq(IntClass *p1, IntClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    return (p1->x == p2->x);
}

static bool Int_lt(IntClass *p1, IntClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    return (p1->x < p2->x);
}

static bool Int_gt(IntClass *p1, IntClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    return (p1->x > p2->x);
}

// Create additional functions here

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Int_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Int_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt,
    },
    .x = 0
};

const Class   *Int = (const Class *)&_description;
