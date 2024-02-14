/*
** EPITECH PROJECT, 2022
** perso
** File description:
** header
*/

#ifndef HEADER_H_
    #define HEADER_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include "struct.h"

    #define REG 1
    #define DIR 2
    #define IND 3

    #define PC REG_NUMBER - 1

typedef struct process_s {
    int prog_size;
    int magic;
    char *name;
    char *comment;
    int *reg;
    int carry;
    struct process_s *next;
    char *prog;
    int to_exec;
    int current;
    int delta_pc;
    int pos;
    int load_adresse;
}process_t;

typedef struct process_id_name_s {
    int id;
    char *name;
    char is_dead;
    char this_cycle;
    struct process_id_name_s *next;
}process_id_name_t;

typedef struct things_s {
    process_t *all_process;
    process_id_name_t *id_name;
    char *arena;
    int nb_champ;
    int cycle_to_die;
    int nb_live;
    int next_check;
    int nb_alive;
}things_t;

    #include "corewar.h"
    #include "op.h"

int main(int argc, char *argv[]);
int main_flags(int argc, char *argv[]);
int find_flags(int argc, char *argv[], flags_t **flags);
void flag_h(void);
int flag_dump(int argc, char *argv[], flags_t *flags, int nbr_flags);
int flag_n(int argc, char *argv[], flags_t *flags, int nbr_flags);
int flag_a(int argc, char *argv[], flags_t *flags, int nbr_flags);
int flag_name(int argc, char *argv[], flags_t *flags, int nbr_flags);
void init_struct(debug_t *debug);
void reinit_struct(debug_t *debug);
int check_debug(debug_t *debug);
int check_cur_debug(debug_t *debug);
int func(int argc, char *argv[], flags_t **flags, debug_t *debug);
int find_flags(int argc, char *argv[], flags_t **flags);
void init_flags(flags_t **flags, int i);
int my_putstr(char *str);
int my_strcmp(char *str, char *cmp);
int my_str_is_int(char *str);
void main_vm(flags_t **flags);
char *get_name_from_id(int id, process_id_name_t *id_name);
void add_process_two(process_t *temp, process_t **all_process,
header_t header_tmp, flags_t *flags);
void add_process(int id, process_t **all_process, header_t header_tmp,
flags_t *flags);
void add_id_name(char const *name, int id, process_id_name_t **id_name,
flags_t *flags);
op_t get_op(int op);
void get_args(int **args, int i, process_t *process, things_t *things);
int get_arg_type(int i, int args_type);
void do_the_thing(int **args, op_t op, process_t *process, things_t *things);

#endif
