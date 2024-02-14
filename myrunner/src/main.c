/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** main.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"
#include "../include/my.h"

sfRenderWindow *create_window(char *name) {
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, name,
    sfFullscreen | sfClose, NULL);

    sfWindow_setFramerateLimit((sfWindow *)window, 50);
    return (window);
}

void get_map(init_sfml_t *init_sfml, char *avg)
{
    char *buffer;
    unsigned int fd = 0;
    unsigned int rd = 0;

    buffer = malloc(sizeof(char) * 490);
    init_sfml->map = malloc(sizeof(char *) * 3);
    for (int i = 0; i < 3; ++i)
        init_sfml->map[i] = malloc(sizeof(char) * 163);
    fd = open(avg, O_RDONLY);
    rd = read(fd, buffer, 489);
    for (int j = 0, r = 0; j < 3; ++j) {
        for (int i = 0; i < 163 && buffer[r] != '\0'; ++i, ++r)
            init_sfml->map[j][i] = buffer[r];
    }
}

void print_help(void)
{
    my_putstr("Finite runner created with CSFML.\n\n");
    my_putstr("USAGE\n  ./my_runner arguments\n");
    my_putstr("OPTIONS\n");
    my_putstr("  -i             launch the game in infinity mode.\n");
    my_putstr("  -f map.txt     launch the game in maps mode.\n");
    my_putstr("  -h             print the usage and quit.\n\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("  SPACE_KEY       jump.\n");
    my_putstr("  ESCAPE_KEY      play.\n");
}

int main(int avc, char **avg)
{
    init_sfml_t init_sfml;
    sfClock *clock = sfClock_create();

    if (avc >= 2 && avg[1][0] == '-') {
        if  (avg[1][1] == 'i')
            init_sfml.infini = true;
        else if  (avg[1][1] == 'f') {
            init_sfml.infini = false;
            get_map(&init_sfml, avg[2]);
        } else {
            print_help();
            return (84);
        }
    } else {
        print_help();
        return (84);
    }
    init_sfml.window = create_window("MAIS OUI BIEN SUR");
    init_sfml.framebuffer = framebuffer_create(WIDTH, HEIGHT);
    init_sfml.texture = sfTexture_createFromFile("ressources/img/texture.png",
    NULL);
    init_sfml.clock = sfClock_create();
    if (!init_sfml.window || !init_sfml.framebuffer)
        return (84);
    my_runner(&init_sfml, clock);
    free(init_sfml.framebuffer);
    sfTexture_destroy(init_sfml.texture);
    sfRenderWindow_destroy(init_sfml.window);
    return (0);
}
