/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** maps.c
*/

#include "../include/sokoban.h"
#include "../include/structure.h"

void put_block(init_sfml_t *init_sfml, sfVector2f pos, game_object_t obj)
{
    sfSprite *sprite;

    sprite = sfSprite_copy(obj.sprite);
    sfSprite_setPosition(obj.sprite, pos);
    sfSprite_setTextureRect(obj.sprite, obj.rect);
    sfSprite_setPosition(obj.sprite, pos);
    sfRenderWindow_drawSprite(init_sfml->window, sprite, NULL);
}

void set_block_img(init_sfml_t *init_sfml, game_object_t *obj,
sfVector2i pos_map, char c)
{
    sfSprite *sprite;
    sfVector2f pos = {800, 900};

    pos.x = 800 + (65 * pos_map.x);
    pos.y = 300 + (65 * pos_map.y);
    switch (c) {
    case '#':
        put_block(init_sfml, pos, obj[5]);
        break;
    case 'X':
        put_block(init_sfml, pos, obj[4]);
        break;
    case 'O':
        put_block(init_sfml, pos, obj[7]);
        break;
    case 'P':
        obj[8].pos.x = 800 + (65 * pos_map.x);
        obj[8].pos.y = 300 + (65 * pos_map.y);
        draw_sprite(init_sfml, &obj[8]);
        break;
    case 32:
        put_block(init_sfml, pos, obj[6]);
        break;
    }
}
