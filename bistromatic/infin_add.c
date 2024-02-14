/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** infin_add.c
*/

#include "include/bistromatic.h"
#include "include/my.h"
#include "include/evalexpr.h"
#include "include/structure.h"
#include "include/infin.h"

char *check_calcul_add(char *result, char *av1, char *av2)
{
    int bool = 0;
    int bool_sub = 0;

    av1[0] == '-' ? av1[0] = '0', bool += 1, bool_sub = 1 : bool;
    av2[0] == '-' ? av2[0] = '0', bool += 1 : bool;
    if (bool == 1) {
        if (compare_len_sub(av1, av2) == 1) {
            if (bool_sub == 0) {
                result =  sub_calcul(av2, av1, 0);
                result[0] = '-';
            } else
                result = sub_calcul(av2, av1, 0);
        } else {
            if (bool_sub == 1) {
                result =  sub_calcul(av1, av2, 0);
                result[0] = '-';
            } else
                result =  sub_calcul(av1, av2, 0);
        }
    } else
        result = add_calcul(result, av1, av2);
    return (result);
}

char *add_calcul(char *result, char *av1, char *av2)
{
    int tmp = 0;

    for (int i = my_strlen(av1) - 1; 0 <= i; --i) {
        tmp += av1[i] - 48 + av2[i] - 48;
        result[i + 1] = (tmp % 10) + 48;
        tmp /= 10;
    }
    if (result[0] != '-') {
        if (tmp == 1)
            result[0] = '1';
        else
            result[0] = '0';
    }
    return result;
}