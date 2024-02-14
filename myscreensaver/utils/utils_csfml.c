/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** utils_csfml.c
*/

#include "../include/screensaver.h"
#include "../include/structur.h"

void events(sfRenderWindow *window)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        else if (event.type == sfEvtKeyPressed && sfKeyEscape == event.key.code)
            sfRenderWindow_close(window);
    }
}

int clear_window(sfUint8 *fm, sfColor c)
{
    sfVector2i pts_a = {0, 0};
    sfVector2i pts_b = {WIDTH, HEIGHT};
    for (int i = pts_a.x; i <= pts_b.x; ++i) {
        for (int y = pts_a.y; y <= pts_b.y; ++y) {
            my_put_pixel(i, y, fm, c);
        }
    }
}

sfColor my_rgb(sfColor color)
{
    !color.b && 255 == color.r ? 255 == ++color.g ? --color.r : 0 :
    !color.b && 255 == color.g ? !--color.r ? ++color.b : 0 :
    !color.r && 255 == color.g ? 255 == ++color.b ? --color.g : 0 :
    !color.r && 255 == color.b ? !--color.g ? ++color.r : 0 :
    !color.g && 255 == color.b ? 255 == ++color.r ? --color.b : 0 :
    !color.g && 255 == color.r ? !--color.b ? ++color.g : 0 : 0;
    return (color);
}

sfUint8 *framebuffer_create(int w, int h)
{
    return (malloc(sizeof(sfUint8) * (w * h * 4)));
}

void function_sfml_whil(init_sfml_t init_sfml, sfColor c)
{
    sfRenderWindow_clear(init_sfml.window, c);
    sfSprite_setTexture(init_sfml.sprite, init_sfml.texture, sfFalse);
    sfTexture_updateFromPixels(init_sfml.texture, init_sfml.framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(init_sfml.window, init_sfml.sprite, NULL);
    sfRenderWindow_display(init_sfml.window);
}
