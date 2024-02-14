/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** bistromatic.h
*/

#ifndef BISTROMATIC_H_
    #define BISTROMATIC_H_
    #define OP_OPEN_PARENT_IDX  0
    #define OP_CLOSE_PARENT_IDX 1
    #define OP_PLUS_IDX         2
    #define OP_SUB_IDX          3
    #define OP_NEG_IDX          3
    #define OP_MULT_IDX         4
    #define OP_DIV_IDX          5
    #define OP_MOD_IDX          6

    #define EXIT_USAGE    84
    #define EXIT_BASE     84
    #define EXIT_SIZE_NEG 84
    #define EXIT_MALLOC   84
    #define EXIT_READ     84
    #define EXIT_OPS      84

    #define SYNTAX_ERROR_MSG "syntax error"
    #define ERROR_MSG        "error"

#include "error_handling.h"

char *eval_expr_inf(char *av1, char *av2, char *expr, unsigned int size);
int eval_expr_int(char *str);
int hub_evalexpr(char *av1, char *av2, char *expr, unsigned int size);
char *switch_ope(char ope, char *result, char *av1, char *av2);
int my_putstr(char const *);
int my_strlen(char const *);
int my_atoi(char const *);
static char *get_expr(unsigned int size);
static void check_ops(char const *ops);
static void check_base(char const *b);
char *convert_operators(char *av2, char *expr, int size);
char *extend_convert(char *av2, char *expr, char *dest, int i);
int is_default_op(char c);
char *check_calcul_add(char *result, char *av1, char *av2);
char *check_calcul_sub(char *result, char *av1, char *av2);

#endif
