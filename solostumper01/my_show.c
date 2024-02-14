/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday08-thomas.ott
** File description:
** my_show_word_array.c
*/

#include <stddef.h>
#include "include/shortwords.h"

int my_show_word_array(char *const *tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i++]);
        my_putchar('\n');
    }
    return (0);
}
