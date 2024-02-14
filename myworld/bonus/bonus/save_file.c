/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** save_file.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"
#include <sys/types.h>
#include <dirent.h>

bool try_open_folder(void)
{
    DIR *dp;
    struct dirent *dirp;

    dp = opendir("../maps");
    if (dp == NULL) {
        closedir(dp);
        return (false);
    } else {
        closedir(dp);
        return (true);
    }
}

void save_file(char *filepath, map_t *maps)
{
    FILE *fp;
    int separator = -1000;

    if (!try_open_folder())
        mkdir("../maps", 0755);
    fp = fopen (filepath, "w");
    fwrite(&maps->size.x, sizeof(int), 1, fp);
    fwrite(&maps->size.y, sizeof(int), 1, fp);
    for (int i = 0; i < maps->size.x; ++i) {
        fwrite(maps->map_3d[i], sizeof(int), maps->size.y, fp);
        fwrite(&separator, sizeof(int), 1, fp);
    }
    fclose(fp);
}
