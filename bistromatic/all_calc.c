/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** all_calc.c
*/

#include "include/bistromatic.h"
#include "include/my.h"
#include "include/evalexpr.h"
#include "include/structure.h"
#include "include/infin.h"

char *switch_ope(char ope, char *result, char *av1, char *av2)
{
    int tmp = 0;

    for (int i = my_strlen(av1); 0 <= i; --i) {
        switch (ope) {
        case '+':
            result = check_calcul_add(result, av1, av2);
            break;
        case '-':
            result = check_calcul_sub(result, av1, av2);
            break;
        case '*':
            exit (EXIT_READ);
            break;
        case '/':
            exit (EXIT_READ);
            break;
        case '%':
            exit (EXIT_READ);
            break;
        default :
            exit (EXIT_READ);
        }
        return (result);
    }
}