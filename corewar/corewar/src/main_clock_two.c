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
#include <unistd.h>

void special_inst(char inst, process_t *process, things_t *things, op_t op)
{
    if (inst == 1) live(inst, process, things, op);
    if (inst == 9) zjmp(inst, process, things, op);
    if (inst == 12) my_fork(inst, process, things, op);
    if (inst == 15) my_lfork(inst, process, things, op);

}

void exec_inst(char inst, process_t *process, things_t *things)
{
    op_t op = get_op(inst);
    int args_type;
    int **args = malloc(sizeof(int *) * 3);

    for (int i = 0; i < 3; ++i)
        args[i] = malloc(sizeof(int) * 2);
    if (inst != 1 && inst != 9 && inst != 12 && inst != 15) {
        args_type = get_single_byte(process, things);
        process->delta_pc += 1;
        for (int i = 0; i < op.nbr_args; ++i)
            args[i][1] = get_arg_type(i, args_type);
        do_the_thing(args, op, process, things);
    } else
        special_inst(inst, process, things, op);
    process->reg[PC] = process->delta_pc;
    free(args);
}

void treat_inst(char inst, process_t *process, things_t *things)
{
    if (process->current < process->to_exec - 1)
        process->current += 1;
    else {
        process->delta_pc += 1;
        exec_inst(inst, process, things);
        process->current = 0;
    }
}

int get_op_cycle(int op)
{
    for (int i = 0 ; i < 16; ++i)
        if (op == op_tab[i].code) return op_tab[i].nbr_cycles;
}

void decrese_cycle(things_t *things)
{
    if (things->nb_live >= NBR_LIVE) {
        things->nb_live -= NBR_LIVE;
        things->cycle_to_die -= CYCLE_DELTA;
    }
}