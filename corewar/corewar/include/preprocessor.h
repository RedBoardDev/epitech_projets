/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** corewar.h
*/

#ifndef PREPRO_H_
    #define PREPRO_H

    #include "op.h"

int my_strlen(char const *str);
int get_adress_bytes(int adress, things_t *things, process_t *process);
things_t *init_champion(flags_t **flags, int nb_ch);
void print_process(process_t *all_process, process_id_name_t *id_name);
void print_arena(char *arena);
char *get_name_from_id(int id, process_id_name_t *id_name);
void cp_in_string(char const *in, char *out);
void init_arena(things_t *things);
void main_clock(things_t *things);
void sti(int **args, op_t op, process_t *process, things_t *things);
int rev_int(int in);
char get_single_byte(process_t *process, things_t *things);
void live(char inst, process_t *process, things_t *things, op_t op);
int get_four_bytes(process_t *process, things_t *things);
int get_two_bytes(process_t *process, things_t *things);
char get_single_byte(process_t *process, things_t *things);
void ld(int **args, op_t op, process_t *process, things_t *things);
void zjmp(char inst, process_t *process, things_t *things, op_t op);
void my_fork(char inst, process_t *process, things_t *things, op_t op);
void add(int **args, op_t op, process_t *process, things_t *things);
void add_id_name(char const *name, int id, process_id_name_t **id_name,
flags_t *flags);
void st(int **args, process_t *process, things_t *things);
void sub(int **args, op_t op, process_t *process, things_t *things);
void write_four_bytes(int adress, things_t *things, int nb);
void and(int **args, op_t op, process_t *process, things_t *things);
void or(int **args, op_t op, process_t *process, things_t *things);
void xor(int **args, op_t op, process_t *process, things_t *things);
int get_ind_adress_bytes(int adress, things_t *things, process_t *process);
void ldi(int **args, op_t op, process_t *process, things_t *things);
void lld(int **args, op_t op, process_t *process, things_t *things);
void lldi(int **args, op_t op, process_t *process, things_t *things);
void my_lfork(char inst, process_t *process, things_t *things, op_t op);
void aff(int **args, op_t op, process_t *process, things_t *things);
char *get_name_from_id(int id, process_id_name_t *id_name);
void special_inst(char inst, process_t *process, things_t *things, op_t op);
void exec_inst(char inst, process_t *process, things_t *things);
void treat_inst(char inst, process_t *process, things_t *things);
int get_op_cycle(int op);
void decrese_cycle(things_t *things);
int it_is_dead(int id, things_t *things);
void enum_process(things_t *things);
void check_process_life(things_t *things);
void check_cycle(things_t *things, int cycle);
void winner(things_t *things);

#endif //PREPRO_H_