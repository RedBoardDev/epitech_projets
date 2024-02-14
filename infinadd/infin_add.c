/*
** EPITECH PROJECT, 2021
** InfinAdd
** File description:
** Main
*/

#include "function.h"

void function_print(int tmp, char *result)
{
    if (tmp == 1) {
        my_putstr("1");
        my_putstr(result);
    } else
        putstr_number(result);
}

char *add_calcul(char *av1, char *av2)
{
    char *result;
    int tmp = 0;
    //char *buffer;

    if (compare_len(my_strlen(av1), my_strlen(av2)) == 1) {
        result = malloc(sizeof(char) * my_strlen(av2) + 1);
//        buffer = malloc(sizeof(char) * my_strlen(av2) + 1);
        av1 = my_memset(result, av1, my_strlen(av2) + 1);
        result[my_strlen(av2)] = '\0';
    } else {
        result = malloc(sizeof(char) * my_strlen(av1) + 1);
        //      buffer = malloc(sizeof(char) * my_strlen(av1) + 1);
        av2 = my_memset(result, av2, my_strlen(av1) + 1);
        result[my_strlen(av1)] = '\0';
    }
    for (int i = my_strlen(result) - 1, j = my_strlen(result) - 1; 0 <=
    i; --i, --j) {
        tmp += av1[i] - 48 + av2[j] - 48;
        result[i] = (tmp % 10) + 48;
        tmp /= 10;
    }
    function_print(tmp, result);
    free(result);
    //free(buffer);
    return (0);
}
