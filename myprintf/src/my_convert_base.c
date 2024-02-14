/*
** EPITECH PROJECT, 2021
** B-PSU-100-MLH-1-1-myprintf-thomas.ott
** File description:
** convertor_base.c
*/

#include <string.h>
#include "../include/my.h"

int convert_base(unsigned int nb, char *base)
{
    int len = strlen(base);
    int count = 0;

    if (nb >= len) {
        count += convert_base(nb / len, base);
        count += convert_base(nb % len, base);
    } else
        count += my_putchar(base[nb]);
    return (count);
}
