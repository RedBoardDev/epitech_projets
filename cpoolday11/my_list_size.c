/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday11-thomas.ott
** File description:
** my_list_size.c
*/

#include <stdio.h>
#include "include/mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int i = 0;

    while (begin) {
        begin = begin->next;
        ++i;
    }
    return i;
}
