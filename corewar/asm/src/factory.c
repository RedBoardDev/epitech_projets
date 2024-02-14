/*
** EPITECH PROJECT, 2021
** corewar-
** File description:
** factory.c
*/

#include "../include/asm.h"

static int get_pos_instruction(char *instr)
{
    for (int i = 0; op_tab[i].nbr_cycles != 0; ++i) {
        if (my_strcmp(op_tab[i].mnemonique, instr) == 0)
            return (op_tab[i].code);
    }
    return (-1);
}

static void check_number_args(int index, int instr_index)
{
    --instr_index;
    if (index - 1 != op_tab[instr_index].nbr_args)
        exit(84);
}

instr_node_t *factory_commands(instr_node_t *instr_node, char **res, int index)
{
    instr_node_t *tmp = instr_node;
    instr_node_t *node = malloc(sizeof(instr_node_t));
    int i = 0;
    int index_tmp = index;

    while (res[i])
        ++i;
    char **args = malloc(sizeof(char *) * (i + 1));
    for (int i = 0; res[index]; ++index, ++i)
        args[i] = my_strdup(res[index]);
    args[i] = NULL;
    while (args[i])
        ++i;
    if (index_tmp == 1)
        i -= 1;
    node->len = i;
    node->label_args = args;
    node->instruction = get_pos_instruction(node->label_args[0]);
    check_number_args(i, node->instruction);
    for (int i = 0; i < MAX_ARGS_NUMBER; ++i) {
        node->arg_cmd[i].value = -1;
        node->arg_cmd[i].type = TYPE_NONE;
    }
    for (int i = 1; i < node->len; ++i) {
        if (args[i][0] == ':') {
            args[i] += 1;
            node->arg_cmd[i - 1].label = my_strdup(args[i]);
            node->arg_cmd[i - 1].type = TYPE_IND;
            continue;
        }
        if (args[i][1] == ':' && args[i][0] == '%') {
            args[i] += 2;
            node->arg_cmd[i - 1].label = my_strdup(args[i]);
            node->arg_cmd[i - 1].value = TYPE_LABEL;
            node->arg_cmd[i - 1].type = TYPE_DIR;
            continue;
        }
        node->arg_cmd[i - 1].value = get_nbr_without_character(args[i]);
        node->arg_cmd[i - 1].type = check_args_type(args, i, node);
    }

    node->next = NULL;
    if (tmp == NULL)
        return (node);
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
    return (instr_node);
}