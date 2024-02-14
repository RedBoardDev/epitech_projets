/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-martin.d-herouville
** File description:
** text.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void put_text_hauteur(beginning_t *begin, events_t *all_events)
{
    sfText *text = sfText_create();
    sfVector2f pos = {1390, (HEIGHT / 4) * 2.18};
    sfColor color = {130, 130, 130, 255};
    sfFont *font  = sfFont_createFromFile("assets/fonts/droid-sans-bold.ttf");

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, pos);
    sfText_setColor(text, color);
    sfText_setString(text, begin->text.hauteur);
    sfRenderWindow_drawText(begin->window, text, NULL);
}

void put_text_largeur(beginning_t *begin, events_t *all_events)
{
    sfText *text = sfText_create();
    sfVector2f pos = {1390, (HEIGHT / 4) * 1.58};
    sfColor color = {130, 130, 130, 255};
    sfFont *font  = sfFont_createFromFile("assets/fonts/droid-sans-bold.ttf");

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, pos);
    sfText_setColor(text, color);
    sfText_setString(text, begin->text.largeur);
    sfRenderWindow_drawText(begin->window, text, NULL);
}

void put_text_save_file(beginning_t *begin, events_t *all_events)
{
    sfText *text = sfText_create();
    sfVector2f pos = {(WIDTH / 2) - 120, (HEIGHT / 2) - 25};
    sfColor color = {130, 130, 130, 255};
    sfFont *font  = sfFont_createFromFile("assets/fonts/droid-sans-bold.ttf");

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setPosition(text, pos);
    sfText_setColor(text, color);
    sfText_setString(text, begin->text.filename_save);
    sfRenderWindow_drawText(begin->window, text, NULL);
}

void put_text_imput(beginning_t *begin, events_t *all_events)
{
    if (begin->screen.create_menu) {
        put_text_largeur(begin, all_events);
        put_text_hauteur(begin, all_events);
    }
    if (begin->screen.world && begin->save_file)
        put_text_save_file(begin, all_events);
}
