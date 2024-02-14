/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** Do the same thing as the _strstr function.
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int j = 0;
    char *pointer;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == to_find[0])
            pointer = &str[i];
        if (str[i] == to_find[j]) {
            ++j;
        }
        if (j == my_strlen(to_find))
            break;
    }
    if (j == my_strlen(to_find))
        return (pointer);
    else
        return (0);
}

/*int main(void)
{
    char *str = "Bitcoin- Thomas says all day";
    char *to_find = "z";

    my_putstr(my_strstr(str, to_find));
    return (0);
}*/
