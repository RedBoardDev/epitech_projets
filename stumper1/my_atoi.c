/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-pushswap-thomas.ott
** File description:
** my_atoi.c
*/

int my_atoi(char const *src)
{
    int buff = 0;

    for (int i = 0; src[i] != '\0'; ++i) {
        buff *= 10;
        buff += src[i] - '0';
    }
    return (buff);
}
