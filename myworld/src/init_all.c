/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** init_all.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include "../include/myworld.h"

void init_screens(beginning_t *begin, bool init_map_bool)
{
    begin->text.largeur_b = false;
    begin->text.hauteur_b = false;
    begin->text.filename_save_b = false;
    begin->text.largeur = "";
    begin->text.hauteur = "";
    begin->text.filename_save = "";
    begin->screen.main_menu = init_map_bool ? false : true;
    begin->screen.world = init_map_bool ? true : false;
    begin->screen.load_menu = false;
    begin->screen.create_menu = false;
}

void init_guiworld(beginning_t *begin)
{
    begin->guiworld.painter = false;
    begin->guiworld.rotate_360 = false;
    begin->guiworld.toggle_move = false;
    begin->guiworld.toggle_rotate = false;
}

void init_all(beginning_t *begin, map_t *maps, spritesheet_t *spritesheet,
bool init_map_bool)
{
    init_spritesheets(spritesheet, begin);
    spritesheet[S_CREATE_MAP].active = init_map_bool ? false : true;
    spritesheet[S_LOAD_MAP].active = init_map_bool ? false : true;
    spritesheet[S_EXIT].active = init_map_bool ? false : true;
    spritesheet[S_SHUTDOWN].active = init_map_bool ? false : true;
    begin->init_map = false;
    begin->load_map = false;
    begin->get_file = false;
    begin->save_file = false;
    init_screens(begin, init_map_bool);
    init_guiworld(begin);
    init_csfml(begin);
    begin->sound.click = create_sound("assets/sounds/click.ogg");
    begin->sound.launch_maps = create_sound("assets/sounds/launch_map.ogg");
    begin->sound.gngngn = create_sound("assets/sounds/gngngn.ogg");
    begin->sound.volume = 20.00;
    begin->sound.volume_backup = 0.00;
    sfSound_setLoop(begin->sound.gngngn, sfTrue);
}

events_t init_all_events(void)
{
    return ((events_t){.left = false, .right = false, .up = false,
    .down = false, .page_up = false, .page_down = false, .z = false, .s = false,
    .q = false, .d = false, .p = false, .m = false, .escape = false,
    .space = false, .ctrl = false, .tab = false, .enter = false, .mouse =
    {.left = false, .left_released = false, .right = false, .move_x = 0,
    .move_y = 0, .pos = {0, 0}}, .mouse_wheel = {.up = false, .down = false,
    .click = false}});
}

map_t init_maps_begin(sfVector2i size)
{
    return ((map_t){.map_2d = NULL, .backup_2d = NULL, .map_3d = NULL,
    .backup_3d = NULL, .size = size, .angle = {0, 0}, .pos = {POS_X, POS_Y},
    .zoom = ZOOM, .radius = 50, .painter = false});
}
