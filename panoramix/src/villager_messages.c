/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** villager_dialog.c
*/

#include <stdio.h>

void villager_thread_start(int id)
{
    printf("Villager %d: Going into battle!\n", id);
}

void villager_drink_potion(int id, int nb_servings_left)
{
    printf("Villager %d: I need a drink... I see %d servings left.\n",
    id, nb_servings_left);
}

void villager_call_druid_for_refill(int id)
{
    printf("Villager %d: Hey Pano wake up! We need more potion.\n", id);
}

void villager_fighting(int id, int fight_left)
{
    printf("Villager %d: Take that roman scum! Only %d left.\n",
    id, fight_left);
}

void villager_done_fight(int id)
{
    printf("Villager %d: I'm going to sleep now.\n", id);
}
