/*
** EPITECH PROJECT, 2021
** B-PSU-100-MLH-1-1-bsmyls-thomas.ott
** File description:
** boostrap.c
*/

#include "../include/my_ls.h"
#include "../include/structur.h"
#include "../include/my.h"

void swap_elem(info_file_t *info_file, int index1, int index2)
{
    info_file_t id1 = info_file[index1];
    info_file_t id2 = info_file[index2];

    info_file[index1] = id2;
    info_file[index2] = id1;
}

void sort_t(info_file_t *info_file, arg_main_t arg_main, int *pos_type)
{
    int bool = 1;

    for (int i = 0; i < arg_main.count_file_total; ++i) {
        while (bool) {
            bool = 0;
            for (int i = 0; i < arg_main.count_file_total - 1; ++i)  {
                info_file[i].date_time < info_file[i + 1].date_time ?
                swap_elem(info_file, i, i + 1), bool = 1 : 0;
            }
        }
    }
}

void sort_l(info_file_t *info_file, arg_main_t arg_main, int *pos_type)
{
    int bool = 1;

    for (int i = 0; i < arg_main.count_file_total; ++i) {
        while (bool) {
            bool = 0;
            for (int i = 0; i < arg_main.count_file_total - 1; ++i)  {
                my_strcmp(info_file[i].name, info_file[i + 1].name) > 0 ?
                swap_elem(info_file, i, i + 1), bool = 1 : 0;
            }
        }
    }
}

int main(int argc, char **argv)
{
    struct stat stats;
    info_file_t *info_file;
    flag_t flag;
    int i = 0;
    int *pos_type;
    arg_main_t arg_main;

    arg_main.argc = argc;
    arg_main.argv = argv;
    arg_main.count_file_total = 0;
    arg_main.count_file = 0;
    i = get_flags(argc, argv, &flag);
    arg_main.total = 0;
    pos_type = fc_count_file(&arg_main, i, pos_type);
    info_file = malloc(sizeof(info_file_t) * arg_main.count_file_total);
    get_files(i, &arg_main, info_file, pos_type);
    flag.flag_t == 1 ? sort_t(info_file, arg_main, pos_type) :
    sort_l(info_file, arg_main, pos_type);
    print_info(info_file, flag, pos_type, arg_main);
}
