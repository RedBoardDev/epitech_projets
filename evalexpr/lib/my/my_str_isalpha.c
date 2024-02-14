/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_str_isalpha.c
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z') {
            return (0);
        }
    }
    return (1);
}

/*int main(void)
{
    char *str = "azeAUIEUGB-OZAIqdsf";
    int i = my_str_isalpha(str);
    return (i);
}*/
