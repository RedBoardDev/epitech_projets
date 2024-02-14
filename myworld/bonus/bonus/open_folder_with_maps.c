/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-martin.d-herouville
** File description:
** load_list.c
*/

#include <sys/types.h>
#include <dirent.h>
#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void set_load_button(char *filename, load_button_t *load_button, beginning_t *begin,
sfVector2f pos)
{
    sfIntRect rect = {0, 0, 3620, 541};
    sfVector2f scale = {0.2, 0.2};

    load_button->pos = pos;
    load_button->rect = rect;
    load_button->sprite = sfSprite_create();
    load_button->texture = sfTexture_createFromFile(filename, NULL);
    sfSprite_setScale(load_button->sprite, scale);
    sfSprite_setTexture(load_button->sprite, load_button->texture, sfFalse);
    sfSprite_setTextureRect(load_button->sprite, load_button->rect);
    sfSprite_setPosition(load_button->sprite, load_button->pos);
    sfSprite_setOrigin(load_button->sprite, (sfVector2f){rect.width
    / 2, rect.height / 2});
}

int fc_count_file(void)
{
    DIR *dp;
    int len = 0;
    struct dirent *dirp;
    struct stat stats;
    load_button_t *load_button;

    if (stat("../maps", &stats) == -1)
        return (0);
    dp = opendir("../maps");
    if (dp == NULL) {
        closedir(dp);
        return (0);
    }
    dirp = readdir(dp);
    while (dirp != NULL) {
        if (dirp->d_name[0] != '.' && !my_strcmp(".myw", &dirp->d_name[my_strlen(dirp->d_name) - 4]))
            len++;
        dirp = readdir(dp);
    }
    closedir(dp);
    return (len);
}

load_button_t *init_open_folder_maps(beginning_t *begin)
{
    DIR *dp;
    int i = 0;
    int len = fc_count_file();
    struct dirent *dirp;
    sfVector2f pos = {500, 130};
    load_button_t *load_button;

    dp = opendir("../maps");
    if (len == 0 || dp == NULL) {
        load_button = malloc(sizeof(load_button_t) * 1);
        load_button[0].count = 0;
        closedir(dp);
        return (load_button);
    }
    load_button = malloc(sizeof(load_button_t) * len);
    dirp = readdir(dp);
    while (dirp != NULL) {
        if (dirp->d_name[0] != '.' && !my_strcmp(".myw", &dirp->d_name[my_strlen(dirp->d_name) - 4])) {
            load_button[i].name_file = my_strdup(dirp->d_name);
            load_button[i].mouse_on = false;
            pos.y = 130 + (150 * i);
            load_button[i].count = len;
            set_load_button("../assets/img/menu/maps_list.png", &load_button[i], begin, pos);
            ++i;
        }
        dirp = readdir(dp);
    }
    closedir(dp);
    return (load_button);
}
