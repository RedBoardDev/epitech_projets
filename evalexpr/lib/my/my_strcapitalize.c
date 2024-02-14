/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_strcapitalize.C
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') && str[i - 1] == ' ') {
            str[i] = str[i] - 32;
        }
    }
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] - 32;
    return (str);
}

/*int main(void)
{
    char str[] = "hey, how are you? 42WORds forty-two fifty+one";

    my_putstr(str);
    my_putchar('\n');
    my_putstr(my_strcapitalize(str));
    return (0);
}*/
