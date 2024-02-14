/*
** EPITECH PROJECT, 2022
** B-AIA-200-MLH-2-1-bsn4s-luca.haumesser
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <string.h>

typedef struct {
    char *info;
    int cur_pos_3;
    int cur_pos_16;
    int cur_pos_28;
    char buf[1024];
    float dir;
    float speed;
} struct_t;

void right_move(struct_t *data);
void left_move(struct_t *data);
void other_move(struct_t *data);
void change_dir(struct_t *data);
int my_putstr(char const *str);
int my_putstr_error(char const *str);
int save_int(char *info, int i);
int find_lidar(char *info, int nbr_lidar);
char *command_f(char *command, ...);
void init_struct(struct_t *data);
int needfourstek(void);
int main(int argc, char const *argv[]);

#endif
