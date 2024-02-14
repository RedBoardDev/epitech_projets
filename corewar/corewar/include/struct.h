/*
** EPITECH PROJECT, 2022
** perso
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct flags_s {
    int nbr_cycle;
    int prog_number;
    int load_address;
    char *prog_name;
} flags_t;

typedef struct debug_s {
    int nbr_prog;
    int nbr_flags;
    int cur_nbr_cycle;
    int cur_prog_number;
    int cur_load_address;
    int cur_prog_name;
    int tot_nbr_cycle;
    int tot_prog_number;
    int tot_load_address;
    int tot_prog_name;
} debug_t;

#endif
