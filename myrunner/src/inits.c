/*
** EPITECH PROJECT, 2021
** B-MUL-100-MLH-1-1-myrunner-thomas.ott
** File description:
** inits.c
*/

#include "../include/my_runner.h"
#include "../include/structur.h"

play_data_t init_play_data(void)
{
    play_data_t play_data;

    play_data.score = 0;
    play_data.sprite = 0;
    play_data.start = 0;
    return (play_data);
}

void inits_sounds(sound_ambiant_t *sound_ambiant)
{
    sound_ambiant->main =
    sfMusic_createFromFile("ressources/sounds/jetpack-remix.ogg");
    sound_ambiant->walk =
    sfMusic_createFromFile("ressources/sounds/walk.ogg");
    sound_ambiant->rocket =
    sfMusic_createFromFile("ressources/sounds/rocket.ogg");
    sfMusic_play(sound_ambiant->walk);
    sfMusic_play(sound_ambiant->rocket);
    sfMusic_setLoop(sound_ambiant->main, sfTrue);
    sfMusic_setLoop(sound_ambiant->walk, sfTrue);
    sfMusic_setLoop(sound_ambiant->rocket, sfTrue);
    sfMusic_setVolume(sound_ambiant->main, 70);
    sfMusic_setVolume(sound_ambiant->walk, 0);
    sfMusic_setVolume(sound_ambiant->rocket, 0);
}
