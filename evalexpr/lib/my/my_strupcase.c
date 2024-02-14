/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_strupcase.c
*/

#include "my.h"

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    return (str);
}

/*int main(void)
{
    char str[] = "Hello world!";

    my_putstr(str);
    my_putchar('\n');
    my_putstr(my_strupcase(str));
    return (0);
}*/
