/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "char.h"

typedef struct
{
    Class   base;
    char     x;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->x = va_arg((*args), int);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

static char *Char_str(CharClass *this)
{
    char *str = malloc(sizeof(char) * (11));
    sprintf(str, "<Char (%c)>", this->x);

    return (str);
}

static Object *Char_add(CharClass *p1, CharClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    Object *out;
    char x = p1->x + p2->x;

    out = malloc(Char->__size__);
    memcpy(out, Char, Char->__size__);

    ((CharClass *)(out))->x = x;
    return (out);
}

static Object *Char_sub(CharClass *p1, CharClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    Object *out;
    char x = p1->x - p2->x;

    out = malloc(Char->__size__);
    memcpy(out, Char, Char->__size__);

    ((CharClass *)(out))->x = x;
    return (out);
}

static Object *Char_mul(CharClass *p1, CharClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    Object *out;
    char x = p1->x * p2->x;

    out = malloc(Char->__size__);
    memcpy(out, Char, Char->__size__);

    ((CharClass *)(out))->x = x;
    return (out);
}

static Object *Char_div(CharClass *p1, CharClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    if (p2->x == 0)
        raise("divide by 0");
    Object *out;
    char x = p1->x / p2->x;

    out = malloc(Char->__size__);
    memcpy(out, Char, Char->__size__);

    ((CharClass *)(out))->x = x;
    return (out);
}

static bool Char_eq(CharClass *p1, CharClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    return (p1->x == p2->x);
}

static bool Char_lt(CharClass *p1, CharClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    return (p1->x < p2->x);
}

static bool Char_gt(CharClass *p1, CharClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    return (p1->x > p2->x);
}

// Create additional functions here

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Char_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Char_sub,    /* Implement this method for exercice 03 */
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt,
    },
    .x = 0
};

const Class   *Char = (const Class *)&_description;
