/*
** EPITECH PROJECT, 2021
** bistomatic
** File description:
** infin_sub.c
*/

#include "include/bistromatic.h"
#include "include/my.h"
#include "include/evalexpr.h"
#include "include/structure.h"
#include "include/infin.h"

char *check_calcul_sub(char *result, char *av1, char *av2)
{
    int tmp = 0;
    int bool = 0;
    int bool_sub = 0;
    if (av1[0] == '-') {
        av1[0] = '0';
        bool += 1;
        bool_sub = 1;
    }
    if (av2[0] == '-') {
        av2[0] = '0';
        bool += 1;
    }
    if (av2[1] == '-') {
        av2[1] = '0';
        bool += 1;
    }
    if (bool == 1) {
        if (compare_len_sub(av1, av2) == 1) {
            if (bool_sub == 0) {
                result =  add_calcul(result, av1, av2);
            } else {
                result = add_calcul(result, av1, av2);
                result[0] = '-';
            }
        } else {
            if (bool_sub == 1) {
                result = add_calcul(result, av1, av2);
                if (result[1] != '0')
                    result[0] = '-';
                else
                    result[1] = '-';
            } else {
                result =  add_calcul(result, av1, av2);
            }
        }
    } else {
        if (compare_len_sub(av1, av2) == 1) {
            result =  sub_calcul(av1, av2, 1);
            if (result[1] != '0')
                result[0] = '-';
            else {
                result[1] = '-';
                result[0] = '0';
            }
        } else {
            result =  sub_calcul(av1, av2, 0);
            if (bool == 2)
                result[0] = '-';
        }
    }
    return (result);
}

char *sub_calcul(char *av1, char *av2, int bool_sub)
{
    char *result = malloc(sizeof(char) * my_strlen(av1) + 2);
    int tmp = 0;
    int carry = 0;
    int av1_temp = 0;
    int av2_temp = 0;
    int i = my_strlen(av1);

    if (compare_len_sub(av1, av2) == 1) {
        my_swap_char(&av1, &av2);
    }
    for (; 0 <= i; --i) {
        if (av1[i] - carry < av2[i]) {
            av1_temp = (av1[i] - 48) + 10;
            tmp = (av1_temp - carry) - ((av2[i] - 48));
            carry = 1;
        } else {
            tmp = (av1[i] - carry) - av2[i];
            carry = 0;
        }
        if (bool_sub)
            result[i + 1] = tmp + 48;
        else
            result[i] = tmp + 48;
    }
    if (bool_sub)
        result[my_strlen(av1) + 1] = '\0';
    else
        result[my_strlen(av1)] = '\0';
    return (result);
}
