/*
** EPITECH PROJECT, 2021
** B-PSU-100-MLH-1-1-myprintf-thomas.ott
** File description:
** convertor_base.c
*/

#include <string.h>
#include "my.h"

void convert_base(int nb, char *base)
{
    int len = strlen(base);

    nb < 0 ? my_putchar('-'), nb *= (-1) : nb;
    nb >= len ? convert_base(nb / len, base), convert_base(nb % len, base) :
    my_putchar(base[nb]);
}