/*
** EPITECH PROJECT, 2021
** corewar-
** File description:
** convert_to_bit.c
*/

#include "../include/asm.h"

static int set_writting_var(instr_node_t *instr_node, int nbr_args,
instr_bit_t *instr_bit, int i)
{
    if (instr_node->instruction != 1 && instr_node->instruction != 9
    && instr_node->instruction != 12 && instr_node->instruction != 15) {
        instr_bit[i].to_write[nbr_args] = get_coding_bit(instr_node);
        instr_bit[i].stock_nb[nbr_args] = 1;
        ++nbr_args;
    }
    for (int r = 0; r < instr_node->len -1; ++r, ++nbr_args) {
        instr_bit[i].to_write[nbr_args] = instr_node->arg_cmd[r].value;
        instr_bit[i].stock_nb[nbr_args] =
        get_value_bit(instr_node->arg_cmd[r].type, instr_node->instruction);
    }
    return (nbr_args);
}

int convert_to_bit(instr_node_t *instr_node, label_node_t *label_node,
header_t *head, char *file_name)
{
    int i = 0;
    int nbr_args = 0;
    instr_node_t *instr_node_tmp = instr_node;
    instr_bit_t *instr_bit = malloc(sizeof(instr_bit_t) *
    size_linked_list(instr_node));

    while (instr_node != NULL) {
        instr_bit[i].to_write[nbr_args] = instr_node->instruction;
        instr_bit[i].stock_nb[nbr_args] = 1;
        ++nbr_args;
        nbr_args = set_writting_var(instr_node, nbr_args, instr_bit, i);
        instr_bit[i].len = nbr_args;
        nbr_args = 0;
        ++i;
        instr_node = instr_node->next;
    }
    set_label_value(instr_bit, label_node, instr_node_tmp);
    write_to_file(instr_bit, head, i, file_name);
    return (0);
}
