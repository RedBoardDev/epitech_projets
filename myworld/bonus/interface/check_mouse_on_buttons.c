/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** check_mouse_on_buttons.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void check_mouse_on_one_file(beginning_t *begin, events_t *all_events,
load_button_t *load_button, int i)
{
    sfFloatRect collision;

    collision = sfSprite_getGlobalBounds(load_button[i].sprite);
    if (all_events->mouse.pos.x > collision.left &&
    all_events->mouse.pos.x < collision.left + collision.width &&
    all_events->mouse.pos.y > collision.top &&
    all_events->mouse.pos.y < collision.top + collision.height) {
        load_button[i].rect.top = (all_events->mouse.left) ? (1082) : 541;
        load_button[i].mouse_on = true;
    } else {
        load_button[i].rect.top = 0;
        load_button[i].mouse_on = false;
    }
}

void check_one_button(beginning_t *begin, events_t *all_events,
spritesheet_t *spritesheet, int i)
{
    sfFloatRect collision;

    if (spritesheet[i].active) {
        collision = sfSprite_getGlobalBounds(spritesheet[i].sprite);
        if (check_mouse_on_one_button(all_events->mouse.pos, collision)) {
            spritesheet[i].rect.top = (all_events->mouse.left) ? (1082) : 541;
        } else
            spritesheet[i].rect.top = 0;
    }
}

void toggle_all_toggles(beginning_t *begin, spritesheet_t *spritesheet)
{
    if (begin->text.largeur_b)
        spritesheet[S_LARGEUR].rect.top = 541;
    if (begin->text.hauteur_b)
        spritesheet[S_HAUTEUR].rect.top = 541;
    if (begin->text.filename_save_b)
        spritesheet[S_SAVE_TEXT_BUTTON].rect.top = 541;
    if (begin->guiworld.painter)
        spritesheet[S_CHANGE_PAINTER].rect.top = 541;
    if (begin->guiworld.rotate_360)
        spritesheet[S_ROTATE_360].rect.top = 541;
    if (begin->guiworld.toggle_move)
        spritesheet[S_TOGGLE_MOVE].rect.top = 541;
    if (begin->guiworld.toggle_rotate)
        spritesheet[S_TOGGLE_ROTATE].rect.top = 541;
}

void check_mouse_on_all_buttons(beginning_t *begin, events_t *all_events,
spritesheet_t *spritesheet, load_button_t *load_button)
{
    for (int i = 2; i < NBR_SPRITE; ++i)
        check_one_button(begin, all_events, spritesheet, i);
    if (begin->screen.load_menu)
        for (int i = 0; i < load_button[0].count; ++i)
            check_mouse_on_one_file(begin, all_events, load_button, i);
    toggle_all_toggles(begin, spritesheet);
    if (begin->sound.volume) {
        spritesheet[S_SOUND].rect.left = 541;
        spritesheet[S_SOUND_POTENTIO].rect.left = 0;
    } else {
        spritesheet[S_SOUND].rect.left = 0;
        spritesheet[S_SOUND_POTENTIO].rect.left = 3620;
    }
}
