/*
** EPITECH PROJECT, 2021
** corewar-
** File description:
** convert_to_bit_two.c
*/

#include "../include/asm.h"

static int check_all_type_args(enum type_instr type)
{
    if (type != TYPE_REG
    && type != TYPE_DIR
    && type != TYPE_LABEL
    && type != TYPE_IND)
        return (1);
    return (0);
}

unsigned char get_coding_bit(instr_node_t *instr_node)
{
    unsigned char bit = 0;

    for (int i = 0; i < 4; ++i) {
        if (i > instr_node->len - 1) {
            bit <<= 2;
            continue;
        }
        if (check_all_type_args(instr_node->arg_cmd[i].type))
            continue;
        if (instr_node->arg_cmd[i].type == TYPE_REG)
            ARGS_REG(bit);
        if (instr_node->arg_cmd[i].type == TYPE_DIR)
            ARGS_DIR(bit);
        if (instr_node->arg_cmd[i].type == TYPE_LABEL)
            ARGS_DIR(bit);
        if (instr_node->arg_cmd[i].type == TYPE_IND)
            ARGS_IND(bit);
        bit <<= 2;
    }
    return (bit);
}

int get_value_bit(enum type_instr type, unsigned char instruction)
{
    int ret = 0;

    switch (type) {
        case TYPE_LABEL:
            ret = 2;
            break;
        case TYPE_REG:
            ret = 1;
            break;
        case TYPE_DIR:
            ret = (instruction >= 9 && instruction <= 12) ? 2 : 4;
            break;
        case TYPE_IND:
            ret = 2;
            break;
        default:
            break;
    }
    return (ret);
}
