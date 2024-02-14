/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** my_putchar.c
*/

#include "my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putcharerror(char c)
{
    write(2, &c, 1);
}
