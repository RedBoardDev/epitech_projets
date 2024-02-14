/*
** EPITECH PROJECT, 2021
** B-PSU-100-MLH-1-1-myls-thomas.ott
** File description:
** get_info.c
*/

#include "../include/my_ls.h"
#include "../include/structur.h"
#include "../include/my.h"

int get_flags(int argc, char **argv, flag_t *flag_st)
{
    int i = 1;

    for (; argc > i && argv[i][0] == '-'; ++i) {
        for (int j = 0; argv[i][j] != '\0'; ++j) {
            argv[i][j] == 'l' ? flag_st->flag_l = 1 : 0;
            argv[i][j] == 'R' ? flag_st->flag_R = 1 : 0;
            argv[i][j] == 'd' ? flag_st->flag_d = 1 : 0;
            argv[i][j] == 'r' ? flag_st->flag_r = 1 : 0;
            argv[i][j] == 't' ? flag_st->flag_t = 1 : 0;
        }
    }
    return (i);
}

int get_files(int i, arg_main_t *arg_main,  info_file_t *info_file, int *pos_tp)
{
    DIR *dp;
    struct dirent *dirp;
    struct stat stats;
    int count = 0;
    int i_pos_tp = 0;

    if (i >= arg_main->argc) {
        count += flag_dir(info_file, arg_main, ".", count);
    }
    for (; arg_main->argc > i && arg_main->argv[i][0] != '-'; ++i) {
        if (stat(arg_main->argv[i], &stats) == -1) {
            my_putstr("ls: cannot access '");
            my_putstr(arg_main->argv[i]);
            my_putstr("': No such file or director\n");
        }
        if (S_ISDIR (stats.st_mode)) {
            count += flag_dir(info_file, arg_main, arg_main->argv[i], count);
        } else if (S_ISREG (stats.st_mode)) {
            flag_file(info_file, arg_main, arg_main->argv[i], count);
            pos_tp[i_pos_tp] = count;
            i_pos_tp++;
            ++count;
        }
    }
    return (0);
}

void proint(arg_main_t *arg_main, int i)
{
    my_putstr("ls: cannot open directory '");
    my_putstr(arg_main->argv[i]);
    my_putstr("': Permission denied\n");
}

int test(struct stat stats, arg_main_t *arg_main, int i, DIR *dp)
{
    struct dirent *dirp;

    if (S_ISDIR (stats.st_mode)) {
        dp = opendir(arg_main->argv[i]);
        if (dp == NULL) {
            proint(arg_main, i);
            return (0);
        }
        dirp = readdir(dp);
        while (dirp != NULL) {
            dirp->d_name[0] != '.' ? ++arg_main->count_file_total : 0;
            dirp = readdir(dp);
        }
    } else if (S_ISREG (stats.st_mode)) {
        ++arg_main->count_file_total;
        ++arg_main->count_file;
    }
    return (0);
}

int *fc_count_file(arg_main_t *arg_main, int i, int *pos_type)
{
    DIR *dp;
    struct dirent *dirp;
    struct stat stats;

    if (i >= arg_main->argc) {
        stat(".", &stats);
        dp = opendir(".");
        dirp = readdir(dp);
        while (dirp != NULL) {
            dirp->d_name[0] != '.' ? ++arg_main->count_file_total : 0;
            dirp = readdir(dp);
        }
    }
    for (; arg_main->argc > i && arg_main->argv[i][0] != '-'; ++i) {
        if (stat(arg_main->argv[i], &stats)  == - 1)
            continue;
        test(stats, arg_main, i, dp);
    }
    pos_type = malloc(sizeof(int) * arg_main->count_file + 1);
    return (pos_type);
}
