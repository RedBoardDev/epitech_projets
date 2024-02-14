/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** error_handling.h
*/

#ifndef ERROR_HANDLING_H_
    #define ERROR_HANDLING_H_

#include "bistromatic.h"
#include "my.h"

void all_error(char *buff, char *av1, char *av2, int size);
int mathematic_error(char *buff, char *av2);
void while_mathematic_error(int k, char *av2, char *buff, int i);
int two_identical_digits(char *av1);
int even_nbr(int var_test);
int error_parenthesis(char *buff, char *av2);
int my_two_arg_check(char *av1, char *av2);
int invalid_character(char *buff, char *av1, char *av2);
int invalid_character_condition_av1(char c, char *av1, int i);
int invalid_character_condition_av2(char c, char *av2, int i);
int operator_in_base(char *av1);
int two_identical_operators(char *av2);

#endif