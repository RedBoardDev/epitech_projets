/*
** EPITECH PROJECT, 2021
** my_str_isupper
** File description:
** my_str_isupper.c
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 97 && str[i] <= 122)
            return (1);
    }
    return (0);
}
