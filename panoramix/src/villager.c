/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** villager.c
*/

#include "../include/panoramix.h"

bool check_villager_drink(villager_t *villager)
{
    pthread_mutex_lock(&villager->druid->refill);
    villager_drink_potion(villager->id, villager->druid->pot);
    if (villager->druid->pot < 1) {
        if (villager->druid->nb_refill < 1) {
            pthread_mutex_unlock(&villager->druid->refill);
            return false;
        }
        villager_call_druid_for_refill(villager->id);
        sem_post(&villager->druid->sem_wait_villager);
        sem_wait(&villager->druid->sem_wait_druid);
    }
    villager->druid->pot -= 1;
    pthread_mutex_unlock(&villager->druid->refill);
    return true;
}

void *villager_main_function(void *args)
{
    villager_t *villager = (villager_t *)args;

    villager_thread_start(villager->id);
    while (villager->nb_fights > 0) {
        if (check_villager_drink(villager) == true) {
            villager->nb_fights -= 1;
            villager_fighting(villager->id, villager->nb_fights);
        }
    }
    villager_done_fight(villager->id);
    return 0;
}
