/*
** EPITECH PROJECT, 2021
** Graphical
** File description:
** screensaver_main.c
*/

#include "include/screensaver.h"

void screensaver_choose(init_sfml_t init_sfml, char c)
{
    switch (c) {
    case '1':
        screensaver_1(init_sfml);
        break;
    case '2':
        screensaver_2(init_sfml);
        break;
    case '3':
        screensaver_3(init_sfml);
        break;
    case '4':
        screensaver_4(init_sfml);
        break;
    case '5':
        screensaver_5(init_sfml);
        break;
    case '6':
        screensaver_6(init_sfml);
    break;
    default:
        exit(84);
    }
}

sfRenderWindow *create_window(char *name) {
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, name,
    sfFullscreen | sfClose, NULL);

    sfWindow_setFramerateLimit((sfWindow *)window, 60);
    return (window);
}

int my_putstr(char const *str)
{
    while (*str != '\0') {
        write(1, str, 1);
        str++;
    }
    return (0);
}

void print_no_arg(void)
{
    my_putstr("./my_screensaver: bad arguments: 0 given but 1 is required\n");
    my_putstr("retry with -h\n");
    exit(84);
}

void print_h(void)
{
    my_putstr("animation rendering in a CSFML window.\n\nUSAGE\n");
    my_putstr("  ./my_screensaver [OPTIONS] animation_id\n");
    my_putstr("   animation_id ID of the animation to process ");
    my_putstr("(between 1 and 6).\n\nOPTIONS\n");
    my_putstr("-d              ");
    my_putstr("print the description of all the animations and quit.");
    my_putstr("\n-h              ");
    my_putstr("print the usage and quit.\n");
    exit(0);
}

int main(int avc, char **avg)
{
    init_sfml_t init_sfml;

    init_sfml.window = create_window("MAIS OUI BIEN SUR");
    init_sfml.framebuffer = framebuffer_create(WIDTH, HEIGHT);
    init_sfml.texture = sfTexture_create(WIDTH, HEIGHT);
    init_sfml.sprite = sfSprite_create();
    if (!init_sfml.window || !init_sfml.framebuffer)
        return (84);
    if (avc == 1)
        print_no_arg();
    if (avg[1][0] == '-' && avg[1][1] == 'h')
        print_h();
    screensaver_choose(init_sfml, avg[1][0]);
    free(init_sfml.framebuffer);
    sfSprite_destroy(init_sfml.sprite);
    sfTexture_destroy(init_sfml.texture);
    sfRenderWindow_destroy(init_sfml.window);
    return (0);
}
