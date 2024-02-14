/*
** EPITECH PROJECT, 2021
** MY_STRLEN
** File description:
** returns the number of characters found
*/

int my_strlen(char const *str)
{
    int len = 0;

    while (*str++) {
        ++len;
    }
    return len;
}
