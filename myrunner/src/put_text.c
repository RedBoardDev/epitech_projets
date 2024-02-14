/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** put_text.c
*/

#include "../include/my_runner.h"
#include "../include/my.h"

void put_score(int nbr, init_sfml_t *init_sfml)
{
    sfText *text = sfText_create();
    sfVector2f vector = {30, 20};
    sfFont *font  = sfFont_createFromFile("ressources/fonts/text_text.ttf");
    sfColor color = {215, 215, 215, 255};

    sfText_setFont(text, font);
    sfText_setString(text, my_strcat(my_itoa(nbr), " m"));
    sfText_setCharacterSize(text, 44);
    sfText_setPosition(text, vector);
    sfText_setColor(text, color);
    sfRenderWindow_drawText(init_sfml->window, text, NULL);
}
