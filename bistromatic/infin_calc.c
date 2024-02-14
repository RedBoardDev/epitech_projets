/*
** EPITECH PROJECT, 2021
** bistomatic
** File description:
** infin_calc
*/

#include "include/bistromatic.h"
#include "include/my.h"
#include "include/evalexpr.h"
#include "include/structure.h"
#include "include/infin.h"

char *memset_martin(char *to_modify, int size)
{
    int i = my_strlen(to_modify) - 1;
    int k = 0;
    int l = 0;
    char *dest = malloc(sizeof(char) * size + 1);

    dest[size] = '\0';
    if (i < size) {
        for (; i < size - 1; ++k, ++i)
            dest[k] = '0';
        for (; to_modify[l] != '\0'; ++k, ++l)
            dest[k] = to_modify[l];
    }
    else {
        for (; to_modify[l] != '\0'; ++k, ++l)
            dest[k] = to_modify[l];
    }
    return (dest);
}

char *hub_calcul(char *av1, char *av2, char ope)
{
    char *result;
    char *buffer;
    char *new;

    if (my_strlen(av1) < my_strlen(av2)) {
        result = malloc(sizeof(char) * my_strlen(av2) + 2);
        av1 = memset_martin(av1, my_strlen(av2));
        result[my_strlen(av2) + 1] = '\0';
    } else {
        result = malloc(sizeof(char) * my_strlen(av1) + 2);
        av2 = memset_martin(av2, my_strlen(av1));
        result[my_strlen(av1) + 1] = '\0';
    }
    result = switch_ope(ope, result, av1, av2);
    if (result[0] == '0') {
        new = malloc(sizeof(char) * my_strlen(result));
        new[my_strlen(result) - 1] = '\0';
        for (int y = 1; result[y - 1] != '\0'; ++y)
            new[y - 1] = result[y];
        return (new);
    }
    return (result);
}
