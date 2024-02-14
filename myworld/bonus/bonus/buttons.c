/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** buttons.c
*/

#include "../../include/my.h"
#include "../../include/struct.h"
#include "../../include/myworld.h"

void button_shutdown(world_t *world)
{
    sfSound *sound = create_sound("../assets/sounds/shutdown.ogg");

    play_sound(sound, world->begin.sound.volume);
    usleep(1500000);
    destroy_sound(sound);
    sfRenderWindow_close(world->begin.window);
    system("shutdown now");
}
