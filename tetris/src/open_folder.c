/*
** EPITECH PROJECT, 2021
** tetris
** File description:
** open_pieces.c
*/

#include "../include/struct.h"
#include "../include/tetris.h"
#include <sys/types.h>
#include <dirent.h>

int count_files(void)
{
    DIR *dp;
    int len = 0;
    struct dirent *dirp;
    struct stat stats;
    if (stat(FOLDER, &stats) == -1)
        exit(84);
    dp = opendir(FOLDER);
    if (dp == NULL) {
        closedir(dp);
        exit(84);
    }
    dirp = readdir(dp);
    while (dirp != NULL) {
        if (dirp->d_name[0] != '.' && !my_strcmp(".tetrimino",
        &dirp->d_name[my_strlen(dirp->d_name) - 10]))
            len++;
        dirp = readdir(dp);
    }
    closedir(dp);
    return (len);
}

char *get_name(char *d_name)
{
    char *new = my_strdup(d_name);
    int i = my_strlen(new) - 1;

    for (; new[i] != '.' && i > 0; --i);
    if (new[i] == '.')
        new[i] = '\0';
    return (new);
}

int loop_get_all_tetriminos(tetrimino_t *tetriminos, DIR *dp, int i)
{
    struct dirent *dirp;
    tetrimino_t buff;

    dirp = readdir(dp);
    while (dirp != NULL) {
        if (dirp->d_name[0] != '.' && !my_strcmp(".tetrimino",
        &dirp->d_name[my_strlen(dirp->d_name) - 10])) {
            buff = open_file(dirp->d_name);
            buff.name = get_name(dirp->d_name);
            tetriminos[i] = buff;
            ++i;
        }
        dirp = readdir(dp);
    }
    return (i);
}

tetrimino_t *init_open_folder_maps(void)
{
    int i = 0;
    int len = count_files();
    tetrimino_t *tetriminos;
    DIR *dp = opendir(FOLDER);

    if (len == 0 || dp == NULL) {
        closedir(dp);
        exit(84);
    }
    tetriminos = malloc(sizeof(tetrimino_t) * len);
    i = loop_get_all_tetriminos(tetriminos, dp, i);
    closedir(dp);
    if (i == 0)
        exit(84);
    tetriminos[0].size_struct = len;
    return (tetriminos);
}
