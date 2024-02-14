/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-martin.d-herouville
** File description:
** inits_spritesheet.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void init_spritesheets_toggle(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_one_sprite("assets/img/interface_world/toggle_move.png",
    &spritesheet[S_TOGGLE_MOVE], begin,
    (init_sprite_t){{680 - 280, 50}, {0.1, 0.1}, {0, 0, 541, 541}});
    set_one_sprite("assets/img/interface_world/toggle_rotate.png",
    &spritesheet[S_TOGGLE_ROTATE], begin,
    (init_sprite_t){{610 - 280, 50}, {0.1, 0.1}, {0, 0, 541, 541}});
    set_one_sprite("assets/img/interface_world/rotate_360.png",
    &spritesheet[S_ROTATE_360], begin,
    (init_sprite_t){{540 - 280, 50}, {0.1, 0.1}, {0, 0, 541, 541}});
    set_one_sprite("assets/img/interface_world/change_painter.png",
    &spritesheet[S_CHANGE_PAINTER], begin,
    (init_sprite_t){{470 - 280, 50}, {0.1, 0.1}, {0, 0, 541, 541}});
    set_one_sprite("assets/img/sound.png", &spritesheet[S_SOUND], begin,
    (init_sprite_t){{WIDTH - 120, 40}, {0.1, 0.1}, {0, 0, 541, 541}});
    set_one_sprite("assets/img/sound_potentio.png",
    &spritesheet[S_SOUND_POTENTIO], begin,
    (init_sprite_t){{WIDTH - 275, 100}, {0.1, 0.1}, {0, 0, 3620, 541}});
    set_one_sprite("assets/img/soundbox_select.png",
    &spritesheet[S_SOUND_SELECT], begin,
    (init_sprite_t){{WIDTH - 312, 100}, {0.06, 0.06}, {0, 0, 541, 541}});
}

void init_spritesheets_rotate(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_one_sprite("assets/img/interface_world/rotate_x_left.png",
    &spritesheet[S_ROTATE_LEFT], begin,
    (init_sprite_t){{WIDTH - 190, HEIGHT - 50}, {0.1, 0.1}, {0, 0, 541, 541}});
    set_one_sprite("assets/img/interface_world/rotate_x_right.png",
    &spritesheet[S_ROTATE_RIGHT], begin,
    (init_sprite_t){{WIDTH - 50, HEIGHT - 50}, {0.1, 0.1}, {0, 0, 541, 541}});
    set_one_sprite("assets/img/interface_world/rotate_y_down.png",
    &spritesheet[S_ROTATE_DOWN], begin,
    (init_sprite_t){{WIDTH - 120, HEIGHT - 50}, {0.1, 0.1}, {0, 0, 541, 541}});
    set_one_sprite("assets/img/interface_world/rotate_y_up.png",
    &spritesheet[S_ROTATE_UP], begin,
    (init_sprite_t){{WIDTH - 120, HEIGHT - 120}, {0.1, 0.1}, {0, 0, 541, 541}});
}

void init_spritesheets_arrows(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_one_sprite("assets/img/interface_world/arrow_down.png",
    &spritesheet[S_ARROW_DOWN], begin, (init_sprite_t){{WIDTH - 120,
    HEIGHT - 50}, {0.1, 0.1}, {0, 0, 541, 541}});
    set_one_sprite("assets/img/interface_world/arrow_left.png",
    &spritesheet[S_ARROW_LEFT], begin,
    (init_sprite_t){{WIDTH - 190, HEIGHT - 50}, {0.1, 0.1}, {0, 0, 541, 541}});
    set_one_sprite("assets/img/interface_world/arrow_right.png",
    &spritesheet[S_ARROW_RIGHT], begin,
    (init_sprite_t){{WIDTH - 50, HEIGHT - 50}, {0.1, 0.1}, {0, 0, 541, 541}});
    set_one_sprite("assets/img/interface_world/arrow_up.png",
    &spritesheet[S_ARROW_UP], begin,
    (init_sprite_t){{WIDTH - 120, HEIGHT - 120}, {0.1, 0.1}, {0, 0, 541, 541}});
}

void init_save_window(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_one_sprite("assets/img/interface_world/window_save.png",
    &spritesheet[S_WINDOW_SAVE], begin,
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {0.25, 0.25}, {0, 0, 3620, 1623}});
    set_one_sprite("assets/img/interface_world/button_name.png",
    &spritesheet[S_SAVE_TEXT_BUTTON], begin,
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {0.15, 0.15}, {0, 0, 3620, 541}});
    set_one_sprite("assets/img/interface_world/cancel.png",
    &spritesheet[S_SAVE_CANCEL], begin,
    (init_sprite_t){{(WIDTH / 2) + 200, (HEIGHT / 2) + 150}, {0.1, 0.1},
    {0, 0, 1170, 541}});
    set_one_sprite("assets/img/interface_world/save_button.png",
    &spritesheet[S_SAVE_SAVE], begin,
    (init_sprite_t){{(WIDTH / 2) + 350, (HEIGHT / 2) + 150}, {0.1, 0.1},
    {0, 0, 1170, 541}});
}

void init_spritesheets(spritesheet_t *spritesheet, beginning_t *begin)
{
    init_save_window(spritesheet, begin);
    init_spritesheets_menu(spritesheet, begin);
    init_spritesheets_arrows(spritesheet, begin);
    init_spritesheets_toggle(spritesheet, begin);
    init_spritesheets_rotate(spritesheet, begin);
    set_one_sprite("assets/img/interface_world/home.png", &spritesheet[S_HOME],
    begin, (init_sprite_t){{330 - 280, 50}, {0.1, 0.1}, {0, 0, 541, 541}});
    set_one_sprite("assets/img/interface_world/save.png", &spritesheet[S_SAVE],
    begin, (init_sprite_t){{400 - 280, 50}, {0.1, 0.1}, {0, 0, 541, 541}});
}
