/*
** EPITECH PROJECT, 2021
** B-PSU-100-MLH-1-1-bsmyls-thomas.ott
** File description:
** structur.h
*/

#include <time.h>

#ifndef STRUCTURE_H_
    #define STRUCTURE_H_

typedef struct flag_s {
    int flag_l;
    int flag_R;
    int flag_d;
    int flag_r;
    int flag_t;
} flag_t;

typedef struct info_file_s {
    char *name;
    char **file;
    char type;
    char *path;
    int size;
    char *pw_name;
    char *gr_name;
    int nlink;
    char *mtime;
    char perm[11];
    int pos;
    int date_time;
} info_file_t;

typedef struct arg_main_s {
    int argc;
    char **argv;
    int count_dir;
    int count_file;
    int count_file_total;
    char *path_dir;
    int total;
} arg_main_t;


#endif
