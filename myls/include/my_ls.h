/*
** EPITECH PROJECT, 2021
** B-PSU-100-MLH-1-1-bsmyls-thomas.ott
** File description:
** my_ls.h
*/

#include "structur.h"

#ifndef MY_LS_H_
    #define MY_LS_H_

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>

int flag_dir(info_file_t *info_file, arg_main_t *arg_main, char *dir, int i);
void flag_file(info_file_t *info_file, arg_main_t *arg_main, char *file, int i);
void print_info(info_file_t *info_file, flag_t flag, int *pos_type,
arg_main_t arg_main);
int get_flags(int argc, char **argv, flag_t *flag_st);
int get_files(int i, arg_main_t *arg_main,  info_file_t *info_file,
int *pos_tp);
int *fc_count_file(arg_main_t *arg_main, int i, int *pos_type);

#endif