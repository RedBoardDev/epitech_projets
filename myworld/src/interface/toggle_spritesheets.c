/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** toggle_spritesheets.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void toggle_spritesheets_menu(beginning_t *begin, spritesheet_t *spritesheet)
{
    if (begin->screen.main_menu) {
        spritesheet[S_BACKGROUND].active = true;
        spritesheet[S_CREATE_MAP].active = true;
        spritesheet[S_LOAD_MAP].active = true;
        spritesheet[S_EXIT].active = true;
    }
    if (begin->screen.create_menu) {
        spritesheet[S_BACKGROUND].active = true;
        spritesheet[S_CREATE_MAP].active = true;
        spritesheet[S_HAUTEUR].active = true;
        spritesheet[S_LARGEUR].active = true;
        spritesheet[S_BACK_MENU].active = true;
    }
    if (begin->screen.load_menu) {
        spritesheet[S_BACKGROUND].active = true;
        spritesheet[S_BACK_MENU].active = true;
    }
}

void toggle_spritesheets_toggle_world(beginning_t *begin,
spritesheet_t *spritesheet)
{
    if (begin->guiworld.toggle_move) {
        spritesheet[S_ARROW_DOWN].active = true;
        spritesheet[S_ARROW_LEFT].active = true;
        spritesheet[S_ARROW_RIGHT].active = true;
        spritesheet[S_ARROW_UP].active = true;
    }
    if (begin->guiworld.toggle_rotate) {
        spritesheet[S_ROTATE_LEFT].active = true;
        spritesheet[S_ROTATE_RIGHT].active = true;
        spritesheet[S_ROTATE_DOWN].active = true;
        spritesheet[S_ROTATE_UP].active = true;
    }
}

void toggle_spritesheets_world(beginning_t *begin, spritesheet_t *spritesheet)
{
    if (begin->screen.world) {
        toggle_spritesheets_toggle_world(begin, spritesheet);
        spritesheet[S_CHANGE_PAINTER].active = true;
        spritesheet[S_HOME].active = true;
        spritesheet[S_ROTATE_360].active = true;
        spritesheet[S_SAVE].active = true;
        spritesheet[S_TOGGLE_MOVE].active = true;
        spritesheet[S_TOGGLE_ROTATE].active = true;
        if (begin->save_file) {
            spritesheet[S_WINDOW_SAVE].active = true;
            spritesheet[S_SAVE_TEXT_BUTTON].active = true;
            spritesheet[S_SAVE_CANCEL].active = true;
            spritesheet[S_SAVE_SAVE].active = true;
        }
    }
}

void toggle_spritesheets_sound(beginning_t *begin, spritesheet_t *spritesheet)
{
    spritesheet[S_SOUND].active = true;
    if (begin->screen.soundbox) {
        spritesheet[S_SOUND_POTENTIO].active = true;
        spritesheet[S_SOUND_SELECT].active = true;
    }
}
