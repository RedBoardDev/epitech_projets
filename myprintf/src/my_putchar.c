/*
** EPITECH PROJECT, 2021
** my_putchar.c
** File description:
** Test video
*/

#include "../include/my.h"
#include <unistd.h>

int my_putchar(char c)
{
    return (write(1, &c, 1));
}
