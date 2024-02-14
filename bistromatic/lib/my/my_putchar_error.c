/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_putchar_error.c
*/

#include "my.h"
#include <unistd.h>

void my_putchar_error(char c)
{
    write(2, &c, 1);
}
