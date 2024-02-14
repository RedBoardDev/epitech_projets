/*
** EPITECH PROJECT, 2021
** navy
** File description:
** navy.h
*/

#ifndef NAVY_H_
    #define NAVY_H_

    #define _GNU_SOURCE
    #include <sys/stat.h>
    #include <fcntl.h>
    #include "struct.h"
    #include <sys/types.h>
    #include <unistd.h>
    #include <signal.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>

int navy(int ac, char **av);
int check_if_nbr(char *av);
int mystrlen_custom(char *a);
int error_handling_map(char *buffer);
int error_boats(char *buffer);
int get_map(char **av, players_t *my_map, players_t *enemy_map, game_t *infos);

// print
void print_help(void);
int print_map(players_t *player);
void print_enemy_map(players_t *player);

//inits_var
void init_map(players_t *player_struct);
void init_infos(game_t *infos, char *av);

// beginning
int print_beginning(players_t *my_map, players_t *enemy_map, game_t *infos);
int set_file_map(players_t *player_struct);

// handlers_sig
void init_sig(struct sigaction *sig, void (*funct) (int), bool sigact);
void get_sig_pid(int sig, siginfo_t *info, void *context);
void kill_ft(int enemy_pid, int usr);
void handler_recieve_hit_summary(int sig);

// game
int play(players_t *my_map, players_t *enemy_map, game_t *info);
int wait(players_t *my_map, players_t *enemy_map, game_t *info);
int check_win2(game_t *infos);

//set_map
void modify_map(players_t *enemy_map, bool hit, char *arg);

//set_vector_map
void set_vertical(players_t *player_struct, vector_t *vector_1,
vector_t *vector_2);
void set_horizontal(players_t *player_struct, vector_t *vector_1,
vector_t *vector_2);
void set_vector(vector_t *vector, char buff_1, char buff_2);

#endif
