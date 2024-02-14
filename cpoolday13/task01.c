
/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday13-thomas.ott
** File description:
** task01.c
*/
#include <stddef.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

int main()
{ 
    sfVideoMode mode = {800, 600};
    sfRenderWindow* window;
    sfTexture* texture;
    sfSprite* sprite;
    sfShape* shape;
    sfFont* font;
    sfText* text;
    sfEvent event;

    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window) && sfRenderWindow_hasFocus (window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_display(window);
    }
  return (0);
}
