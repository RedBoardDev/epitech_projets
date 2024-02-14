/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 01
*/

#include "object.h"
#include "raise.h"
#include "new.h"
#include "player.h"
#include <stdarg.h>

Object *new(const Class *class, ...)
{
    void *out = malloc(class->__size__);

    va_list list;
    va_start(list, class);

    memcpy(out, class, class->__size__);
    if (class->__ctor__ != NULL)
        class->__ctor__(out, &list);
    va_end(list);
    return out;
}


Object  *va_new(const Class *class, va_list* ap)
{
    void *out = malloc(class->__size__);
    va_list tmp;

    memcpy(out, class, class->__size__);
    va_copy(tmp, (*ap));
    if (class->__ctor__ != NULL)
        class->__ctor__(out, &tmp);
    va_end(tmp);
    return out;
}

void delete(Object *ptr)
{
    if (((Class *)(ptr))->__dtor__ != NULL) {
        ((Class *)(ptr))->__dtor__(ptr);
    }
    free(ptr);
}
