/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** key.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void events_key_pressed_arrows(beginning_t *begin, sfEvent event,
events_t *all_events)
{
    if (sfKeyRight == event.key.code)
        all_events->right = true;
    if (sfKeyLeft == event.key.code)
        all_events->left = true;
    if (sfKeyUp == event.key.code)
        all_events->up = true;
    if (sfKeyDown == event.key.code)
        all_events->down = true;
    if (sfKeyPageUp == event.key.code)
        all_events->page_up = true;
    if (sfKeyPageDown == event.key.code)
        all_events->page_down = true;
    if (sfKeyTab == event.key.code)
        all_events->tab = true;
}

void events_key_pressed_letters(beginning_t *begin, sfEvent event,
events_t *all_events)
{
    if (sfKeyZ == event.key.code)
        all_events->z = true;
    if (sfKeyS == event.key.code)
        all_events->s = true;
    if (sfKeyQ == event.key.code)
        all_events->q = true;
    if (sfKeyD == event.key.code)
        all_events->d = true;
    if (sfKeyP == event.key.code)
        all_events->p = true;
    if (sfKeyM == event.key.code)
        all_events->m = true;
    if (sfKeySpace == event.key.code)
        all_events->space = true;
    if (sfKeySpace == event.key.code)
        all_events->space = true;
}

void events_key_pressed_not_letters(beginning_t *begin, sfEvent event,
events_t *all_events)
{
    if (sfKeyEscape == event.key.code) {
        stop_sound(begin->sound.gngngn);
        if (begin->screen.world) {
            begin->screen.world = false;
            begin->screen.main_menu = true;
        } else
            sfRenderWindow_close(begin->window);
    }
    if (sfKeyLControl == event.key.code || sfKeyRControl == event.key.code)
        all_events->ctrl = true;
    if (sfKeyBackspace == event.key.code) {
        if (begin->text.hauteur_b)
            begin->text.hauteur[my_strlen(begin->text.hauteur) - 1] = '\0';
        if (begin->text.largeur_b)
            begin->text.largeur[my_strlen(begin->text.largeur) - 1] = '\0';
        if (begin->text.filename_save_b)
            begin->text.filename_save[my_strlen(begin->text.filename_save) - 1]
            = '\0';
    }
    if (sfKeyEnter == event.key.code)
        all_events->enter = true;
}

void events_key_pressed(beginning_t *begin, sfEvent event, events_t *all_events)
{
    events_key_pressed_not_letters(begin, event, all_events);
    events_key_pressed_arrows(begin, event, all_events);
    events_key_pressed_letters(begin, event, all_events);
}
