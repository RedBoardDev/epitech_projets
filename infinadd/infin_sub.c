/*
** EPITECH PROJECT, 2021
** B-CPE-101-MLH-1-1-infinadd-thomas.ott
** File description:
** infin_sous.c
*/

#include "function.h"

char *sub_calcul(char *av1, char *av2, int bool_sub)
{
    char *result;
    int tmp = 0;
    char *buffer;

    if (compare_len(my_strlen(av1), my_strlen(av2)) == 1) {
        result = malloc(sizeof(char) * my_strlen(av2) + 1);
        buffer = malloc(sizeof(char) * my_strlen(av2) + 1);
        av1 = my_memset(buffer, av1, my_strlen(av2) + 1);
        result[my_strlen(av2)] = '\0';
    } else {
        result = malloc(sizeof(char) * my_strlen(av1) + 1);
        buffer = malloc(sizeof(char) * my_strlen(av1) + 1);
        av2 = my_memset(buffer, av2, my_strlen(av1) + 1);
        result[my_strlen(av1)] = '\0';
    }
    if (bool_sub == 1)
        my_swap_char(av1, av2);
    for (int i = my_strlen(buffer) - 1, j = my_strlen(buffer) - 1; 0 <=
    i; --i, --j) {
        tmp += (av1[i] - 48) - (av2[j] - 48);
        result[i] = (tmp % 10) + 48;
        tmp /= 10;
    }
    putstr_number(result);
    free(result);
    free(buffer);
    return (0);
}
