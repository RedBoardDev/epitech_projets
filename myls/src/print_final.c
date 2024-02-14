/*
** EPITECH PROJECT, 2021
** B-PSU-100-MLH-1-1-myls-thomas.ott
** File description:
** print_final.c
*/

#include "../include/my_ls.h"
#include "../include/structur.h"
#include "../include/my.h"

void print_l(info_file_t *info_file, int j)
{
    my_putstr(info_file[j].perm);
    my_putstr(" ");
    my_put_nbr(info_file[j].nlink);
    my_putstr(" ");
    my_putstr(info_file[j].pw_name);
    my_putstr(" ");
    my_putstr(info_file[j].gr_name);
    my_putstr(" ");
    my_put_nbr(info_file[j].size);
    my_putstr(" ");
    my_putstr(info_file[j].mtime);
    my_putstr(" ");
    my_putstr(info_file[j].name);
    my_putstr("\n");
}

void print_simple(info_file_t *info_file, int j)
{
    my_putstr(info_file[j].name);
    my_putstr("\n");
}

void print_info(info_file_t *info_file, flag_t flag, int *pos_type,
arg_main_t arg_main)
{
    for (int j = 0; j < arg_main.count_file_total; ++j) {
        for (int i = 0; i < arg_main.count_file; ++i) {
            info_file[j].pos == pos_type[i] ? (flag.flag_l ?
            print_l(info_file, j) : print_simple(info_file, j)) : 0;
        }
    }
    flag.flag_l == 1 && arg_main.count_file_total - arg_main.count_file != 0 ?
    my_putstr("total "), my_put_nbr(arg_main.total / 2), my_putstr("\n") : 0;
    for (int j = 0; j < arg_main.count_file_total; ++j) {
        info_file[j].pos == -1 ? (flag.flag_l ?
        print_l(info_file, j) : print_simple(info_file, j)) : 0;
    }
}
