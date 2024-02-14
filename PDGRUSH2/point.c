/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg((*args), int);
    this->y = va_arg((*args), int);
}

static void Point_dtor(PointClass *this)
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

static char *Point_str(PointClass *this)
{
    char *str = malloc(sizeof(char) * (8 + get_int_size(this->x) + 2 +
get_int_size(this->y) + 3));
    sprintf(str, "<Point (%d, %d)>", this->x, this->y);

    return (str);
}

static Object *Point_add(PointClass *p1, PointClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    Object *out; 
    int x = p1->x + p2->x;
    int y = p1->y + p2->y;

    out = malloc(Point->__size__);
    memcpy(out, Point, Point->__size__);

    ((PointClass *)(out))->x = x;
    ((PointClass *)(out))->y = y;
    return (out);
}

static Object *Point_sub(PointClass *p1, PointClass *p2)
{
    if (p1 == NULL || p2 == NULL)
        raise("error");
    Object *out; 
    int x = p1->x - p2->x;
    int y = p1->y - p2->y;

    out = malloc(Point->__size__);
    memcpy(out, Point, Point->__size__);

    ((PointClass *)(out))->x = x;
    ((PointClass *)(out))->y = y;
    return (out);
}

// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&Point_add,    /* Implement this method for exercice 03 */
        .__sub__ = (binary_operator_t)&Point_sub,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
