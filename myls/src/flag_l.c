/*
** EPITECH PROJECT, 2021
** B-PSU-100-MLH-1-1-myls-thomas.ott
** File description:
** flags_l.c
*/

#include "../include/my_ls.h"
#include "../include/structur.h"
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
#include <string.h>
#include "../include/my.h"
#include <time.h>

char *get_date(char *time)
{
    time = &time[4];
    time[12] = '\0';
    return (time);
}

void set_info(info_file_t *info_file, int i, struct stat stats, char *name)
{
    struct passwd *uid;
    struct group *uid2;

    uid = getpwuid(stats.st_uid);
    uid2 = getgrgid(stats.st_gid);
    info_file[i].size = stats.st_size;
    info_file[i].pw_name = uid->pw_name;
    info_file[i].gr_name = uid2->gr_name;
    info_file[i].name = name;
    info_file[i].nlink = stats.st_nlink;
    info_file[i].mtime = get_date(my_strdup(ctime(&stats.st_mtime)));
    info_file[i].date_time = stats.st_mtime;

}

void set_permission(info_file_t *info_file, int i, struct stat stats)
{
    info_file[i].perm[0] = (S_ISDIR(stats.st_mode) ? 'd' : '-');
    info_file[i].perm[1] = (stats.st_mode & S_IRUSR ? 'r' : '-');
    info_file[i].perm[2] = (stats.st_mode & S_IWUSR ? 'w' : '-');
    info_file[i].perm[3] = (stats.st_mode & S_IXUSR ? 'x' : '-');
    info_file[i].perm[4] = (stats.st_mode & S_IRGRP ? 'r' : '-');
    info_file[i].perm[5] = (stats.st_mode & S_IWGRP ? 'w' : '-');
    info_file[i].perm[6] = (stats.st_mode & S_IXGRP ? 'x' : '-');
    info_file[i].perm[7] = (stats.st_mode & S_IROTH ? 'r' : '-');
    info_file[i].perm[8] = (stats.st_mode & S_IWOTH ? 'w' : '-');
    info_file[i].perm[9] = (stats.st_mode & S_IXOTH ? 'x' : '-');
    info_file[i].perm[9] = (stats.st_mode & S_ISVTX ?
    (info_file[i].perm[9] == 'x' ? 't' : 'T') : info_file[i].perm[9]);
    info_file[i].perm[10] = '\0';
}

void flag_file(info_file_t *info_file, arg_main_t *arg_main, char *file, int i)
{
    struct stat stats;
    struct passwd *uid;
    struct group *uid2;

    info_file[i].pos = i;
    if (stat(file, &stats) == -1)
        exit (84);
    set_permission(info_file, i, stats);
    set_info(info_file, i, stats, file);
}

int flag_dir(info_file_t *info_file, arg_main_t *arg_main, char *dir, int i)
{
    DIR *dp;
    struct stat stats;
    struct dirent *dirp;

    opendir(dir) == NULL ? exit (84) : 0;
    dp = opendir(dir);
    if (dp == NULL)
        return (i);
    for (dirp = readdir(dp); dirp != NULL; dirp = readdir(dp)) {
        if (dirp->d_name[0] != '.') {
            info_file[i].pos = -1;
            stat(my_strcat_2(dir, dirp->d_name), &stats) == -1 ? exit(84) : 0;
            set_permission(info_file, i, stats);
            set_info(info_file, i, stats, dirp->d_name);
            arg_main->total += stats.st_blocks;
            ++i;
        }
    }
    closedir(dp);
    return (i);
}
