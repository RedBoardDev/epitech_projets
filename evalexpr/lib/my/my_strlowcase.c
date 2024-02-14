/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_strlowcase.c
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return (str);
}

/*int main(void)
{
    char str[] = "HELLO WORLD!";

    my_putstr(str);
    my_putchar('\n');
    my_putstr(my_strlowcase(str));
    return (0);
}*/
