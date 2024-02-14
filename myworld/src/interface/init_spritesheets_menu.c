/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** init_spritesheets_menu.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void init_spritesheets_menu(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_one_sprite("assets/img/menu/background.png", &spritesheet[S_BACKGROUND],
    begin,
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {1, 1}, {0, 0, 1920, 1080}});
    set_one_sprite("assets/img/menu/back_to_menu.png",
    &spritesheet[S_BACK_MENU], begin, (init_sprite_t){{1400, (HEIGHT / 4) * 3},
    {0.2, 0.2}, {0, 0, 1170, 541}});
    set_one_sprite("assets/img/menu/exit.png", &spritesheet[S_EXIT], begin,
    (init_sprite_t){{1400, (HEIGHT / 4) * 3}, {0.2, 0.2}, {0, 0, 1170, 541}});
    set_one_sprite("assets/img/menu/create_map.png", &spritesheet[S_CREATE_MAP],
    begin, (init_sprite_t){{1400, HEIGHT / 4}, {0.2, 0.2}, {0, 0, 1783, 541}});
    set_one_sprite("assets/img/menu/load_map.png", &spritesheet[S_LOAD_MAP],
    begin, (init_sprite_t){{1400, HEIGHT / 2}, {0.2, 0.2}, {0, 0, 1783, 541}});
    set_one_sprite("assets/img/menu/hauteur.png", &spritesheet[S_HAUTEUR],
    begin, (init_sprite_t){{1400, (HEIGHT / 4) * 2.3}, {0.2, 0.2},
    {0, 0, 2000, 541}});
    set_one_sprite("assets/img/menu/largeur.png", &spritesheet[S_LARGEUR],
    begin, (init_sprite_t){{1400, (HEIGHT / 4) * 1.7}, {0.2, 0.2},
    {0, 0, 2000, 541}});
    set_one_sprite("assets/img/shutdown.png", &spritesheet[S_SHUTDOWN], begin,
    (init_sprite_t){{WIDTH - 40, 40}, {0.1, 0.1}, {0, 0, 541, 541}});
}
