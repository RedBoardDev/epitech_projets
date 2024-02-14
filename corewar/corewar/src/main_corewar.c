/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main_corewar.c
*/

#include "../include/corewar.h"
#include "../include/preprocessor.h"
#include "../include/op.h"
#include <stdlib.h>
#include <stdio.h>

op_t get_op(int op)
{
    for (int i = 0 ; i < 16; ++i)
        if (op == op_tab[i].code) return op_tab[i];
}

void get_args(int **args, int i, process_t *process, things_t *things)
{
    if (args[i][1] == 1) {
        args[i][0] = (int)get_single_byte(process, things);
        process->delta_pc += 1;
    }
    if (args[i][1] == 2) {
        args[i][0] = (int)get_two_bytes(process, things);
    }
    if (args[i][1] == 3) {
        args[i][0] = (int)get_four_bytes(process, things);
    }
}

int get_arg_type(int i, int args_type)
{
    if (i == 0) args_type >>= 6;
    if (i == 1) args_type >>= 4;
    if (i == 2) args_type >>= 2;
    args_type = args_type & 3;
    return args_type;
}

void do_the_thing(int **args, op_t op, process_t *process, things_t *things)
{
    if (op.code == 2) ld(args, op, process, things);
    if (op.code == 3) st(args, process, things);
    if (op.code == 4) add(args, op, process, things);
    if (op.code == 5) sub(args, op, process, things);
    if (op.code == 6) and(args, op, process, things);
    if (op.code == 7) or(args, op, process, things);
    if (op.code == 8) xor(args, op, process, things);
    if (op.code == 10) ldi(args, op, process, things);
    if (op.code == 11) sti(args, op, process, things);
    if (op.code == 13) lld(args, op, process, things);
    if (op.code == 14) lldi(args, op, process, things);
    if (op.code == 16) aff(args, op, process, things);
}

void main_vm(flags_t **flags)
{
    int i = 0;
    while (i < 4 && flags[i]) {
        ++i;
    }

    things_t *things = init_champion(flags, i);
    init_arena(things);
    main_clock(things);
}