/*
** EPITECH PROJECT, 2021
** corewar-
** File description:
** linked_lists.c
*/

#include "../include/asm.h"

int size_linked_list(instr_node_t *list)
{
    int len = 0;

    while (list != NULL) {
        ++len;
        list = list->next;
    }
    return (len);
}

static void verif_register(char *arg)
{
    int len_nb = my_strlen(arg) - 1;
    char *nb = malloc(sizeof(char) * my_strlen(arg) + 1);
    for (int i = 1; arg[i]; ++i) {
        nb[i - 1] = arg[i];
    }
    nb[len_nb] = '\0';
    int n = my_getnbr(nb);
    if (n > 16 || n < 1)
        exit(84);
}

enum type_instr check_args_type(char **args, int i, instr_node_t *node)
{
    enum type_instr type_binary;
    int type_decimal = 0;

    if (args[i][0] == 'r') {
        verif_register(args[i]);
        type_decimal = 1;
        type_binary = TYPE_REG;
    } else if (args[i][0] == '%') {
        type_decimal = 2;
        type_binary = TYPE_DIR;
    } else {
        type_decimal = 4;
        type_binary = TYPE_IND;
    }
    if ((op_tab[node->instruction - 1].type[i - 1] & type_decimal)
    != type_decimal)
        exit(84);
    return (type_binary);
}
