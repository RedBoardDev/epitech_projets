/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** text.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void events_write_largeur(beginning_t *begin, sfEvent event,
events_t *all_events)
{
    if (event.text.unicode >= 48 && event.text.unicode <= 57 &&
    my_strlen(begin->text.largeur) < 4)
        begin->text.largeur = my_strcat(begin->text.largeur,
        my_itoa(event.text.unicode - 48));
}

void events_write_hauteur(beginning_t *begin, sfEvent event,
events_t *all_events)
{
    if (event.text.unicode >= 48 && event.text.unicode <= 57 &&
    my_strlen(begin->text.hauteur) < 4)
        begin->text.hauteur = my_strcat(begin->text.hauteur,
        my_itoa(event.text.unicode - 48));
}

void events_write_filename(beginning_t *begin, sfEvent event,
events_t *all_events)
{
    char new_letter[2];

    new_letter[0] = event.text.unicode;
    new_letter[1] = '\0';
    if (event.text.unicode >= 32 && event.text.unicode <= 126 &&
    my_strlen(begin->text.filename_save) < 17)
        begin->text.filename_save = my_strcat(begin->text.filename_save,
        new_letter);
}
