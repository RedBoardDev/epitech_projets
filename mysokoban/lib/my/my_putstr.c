/*
** EPITECH PROJECT, 2021
** MY_PUTSTR
** File description:
** displays one-by-one the caracters of a string
*/

#include "my.h"

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return (0);
}
