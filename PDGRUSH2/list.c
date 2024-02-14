/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 05
*/

#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "list.h"
#include "new.h"

typedef struct node_s{
    Object            *value;
    struct node_s   *next;
}   node_t;

typedef node_t *list_t;

typedef struct
{
    Container   base;
    list_t      _list;
    Class       *_type;
}   ListClass;

static bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t new = malloc(sizeof(node_t));

    if (new == NULL)
        return false;
    new->value = elem;
    new->next = (*front_ptr);
    (*front_ptr) = new;
    return true;
}

static void     List_ctor(ListClass *this, va_list *args)
{
    int size = va_arg((*args), int);
    Class *type =  va_arg((*args), Class *);
    Object *temp;
    va_list tmp;
    this->_list = NULL;

    for (int i = 0; i < size; ++i) {
        temp = malloc(type->__size__);
        memcpy(temp, type, type->__size__);
        va_copy(tmp, (*args));
        type->__ctor__(temp, &tmp);
        list_add_elem_at_front(&(this->_list), temp);
    }
    va_end(tmp);
    this->_type = type;
}


static void     List_dtor(ListClass *this)
{
    list_t temp = this->_list;
    list_t temp_next;

    while (temp != NULL) {
        temp_next = temp->next;
        ((Class *)(temp->value))->__dtor__(temp->value);
        free(temp->value);
        free(temp);
        temp = temp_next;
    }
}

static char    *List_str(ListClass *this)
{
    list_t temp = this->_list;
    char *out = malloc(sizeof(char) * 7);
    out[0] = 0; 
    strcat(out, "<List ");
    while (temp != NULL) {
        out = realloc(out, sizeof(char) * (strlen(out) + strlen(str(((Class *)(temp->value)))) + 4));
        strcat(out, str( ((Class *)(temp->value))));
        strcat(out, " | ");
        temp = temp->next;
    }
    out[strlen(out) - 3] = 0;
    strcat(out, ">");
    return out;
}

static size_t   List_len(ListClass *this)
{
    list_t temp = this->_list;
    int len = 0;

    while (temp != NULL) {
        ++len;
        temp = temp->next;
    }
    return len;
}

static Object   *List_getitem(ListClass *this, ...)
{
    list_t temp = this->_list;
    va_list ap;
    va_start(ap, this);
    int position = va_arg(ap, int);
    va_end(ap);
    unsigned int len = 0;

    if (this->_list == NULL || position >= len(((Object *)this)))
        return NULL;
    while (len != position && temp != NULL) {
        ++len;
        temp = temp->next;
    }
    return (temp->value);
}

static void     List_setitem(ListClass *this, ...)
{
    list_t temp = this->_list;
    va_list list;
    va_start(list, this);
    int position = va_arg(list, int);
    unsigned int len = 0;

    if (this->_list == NULL || position >= len(((Object *)this)))
        return;
    while (len != position && temp != NULL) {
        ++len;
        temp = temp->next;
    }
    Object *ObjTemp;
    va_list tmp;

    ObjTemp = malloc(((Class *)(temp->value))->__size__);
    memcpy(ObjTemp, temp->value, ((Class *)(temp->value))->__size__);
    va_copy(tmp, list);
    ((Class *)(temp->value))->__ctor__(ObjTemp, &tmp);

    ((Class *)(temp->value))->__dtor__(temp->value);
    free(temp->value);
    temp->value = ObjTemp;
    va_end(list);
}

static void     List_delitem(ListClass *this, ...)
{
    list_t temp = this->_list;
    va_list ap;
    va_start(ap, this);
    int position = va_arg(ap, int);
    va_end(ap);
    unsigned int len = 0;
    list_t tmp = NULL;

    if (position == 0) {
        this->_list = this->_list->next;
        ((Class *)(temp->value))->__dtor__(temp->value);
        free(temp);
    } else {
        while (len != position -1 && temp != NULL) {
            ++len;
            temp = temp->next;
        }
        if (temp->next->next != NULL)
            tmp = temp->next->next;
        ((Class *)(temp->next->value))->__dtor__(temp->next->value);
        free(temp->next);
        temp->next = tmp;
    }
}

static const ListClass   _descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(ListClass),
            .__name__ = "Array",
            .__ctor__ = (ctor_t)&List_ctor,
            .__dtor__ = (dtor_t)&List_dtor,
            .__str__ = (to_string_t)&List_str,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&List_len,
        .__getitem__ = (getitem_t)&List_getitem,
        .__setitem__ = (setitem_t)&List_setitem,
        .__delitem__ = (delitem_t)&List_delitem,
    },
    ._type = NULL,
    ._list = NULL
};

const Class   *List = (const Class *)&_descr;
