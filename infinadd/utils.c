/*
** EPITECH PROJECT, 2021
** B-CPE-101-MLH-1-1-infinadd-thomas.ott
** File description:
** utils.c
*/

#include "function.h"

char *my_memset(char *buffer, char *av, int size)
{
    int i = 0;
    while (i < size) {
        buffer[i++] = '0';
    }
    buffer[i - 1] = '\0';
    for (int i = my_strlen(av), y = my_strlen(buffer); 0 <= i; --i, --y) {
        buffer[y] = av[i];
    }
    return (buffer);
}

int compare_len(int av1, int av2)
{
    if (av1 < av2)
        return 1;
    else
        return 0;
}

int compare_len_sub(char *av1, char *av2)
{
    int i = 0;
    int j = 0;

    if (av1[0] == '0')
        i++;
    if (av2[0] == '0')
        j++;
    while (av1[i] && av2[j]) {
        if (av1[i] + '0' == av2[j] + '0') {
            i++;
            j++;
        } else
            return (av1[i] + 0 > av2[j] + 0);
    }
    return 0;
}

void my_swap_char(char *a, char *b)
{
    char temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int putstr_number(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (i == 0 && str[i] == 48)
            i = i;
        else
            my_putchar(str[i]);
        i++;
    }
    return (0);
}
