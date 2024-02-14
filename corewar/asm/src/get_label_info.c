/*
** EPITECH PROJECT, 2021
** corewar-
** File description:
** get_label_info.c
*/

#include "../include/asm.h"

int get_label_value(instr_bit_t *instr_bit, label_node_t *label_node_tmp,
int nbr_line)
{
    int count_bit = 0;

    if (nbr_line - 1 < label_node_tmp->index) {
        for (int r = nbr_line - 1; r < label_node_tmp->index; ++r)
            for (int f = 0; f < instr_bit[r].len; ++f) {
                count_bit += instr_bit[r].stock_nb[f];
            }
    } else {
        for (int r = nbr_line - 2; r >= label_node_tmp->index; --r)
            for (int f = 0; f < instr_bit[r].len; ++f) {
                count_bit -= instr_bit[r].stock_nb[f];
            }
    }
    return (count_bit);
}

static label_node_t *get_label_index(label_node_t *label_node, char *label_name)
{
    int i = 0;

    while (label_node != NULL) {
        if (my_strcmp(label_node->name, label_name) == 0) {
            return (label_node);
        }
        ++i;
        label_node = label_node->next;
    }
    exit(84);
}

int set_label_value(instr_bit_t *instr_bit, label_node_t *label_node,
instr_node_t *instr_node)
{
    label_node_t *label_node_tmp = NULL;
    int nbr_line = 0;

    while (instr_node != NULL) {
        for (int i = 0; i < instr_node->len - 1; ++i) {
            if (instr_node->arg_cmd[i].value == TYPE_LABEL) {
                label_node_tmp =
                get_label_index(label_node, instr_node->arg_cmd[i].label);
                instr_bit[nbr_line].to_write[
                i + instr_bit[nbr_line].len -(instr_node->len - 1)] =
                get_label_value(instr_bit, label_node_tmp, nbr_line + 1);
            }
        }
        ++nbr_line;
        instr_node = instr_node->next;
    }
    return (0);
}
