/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** panoramix.c
*/

#include "../include/panoramix.h"

static int create_druid(panoramix_t *panoramix)
{
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

    panoramix->druid = malloc(sizeof(druid_t));
    panoramix->druid->refill = mutex;
    panoramix->druid->pot = panoramix->arguments.pot_size;
    panoramix->druid->pot_size = panoramix->arguments.pot_size;
    panoramix->druid->nb_refill = panoramix->arguments.nb_refill;
    if (pthread_create(&panoramix->druid->thread,
        NULL, druid_main_function, panoramix) != 0)
        return 84;
    return 0;
}

static int create_villagers(panoramix_t *panoramix)
{
    panoramix->villager = malloc(sizeof(villager_t) *
        panoramix->arguments.nb_villagers);
    for (int i = 0; i < panoramix->arguments.nb_villagers; ++i) {
        panoramix->villager[i].id = i;
        panoramix->villager[i].nb_fights = panoramix->arguments.nb_fights;
        panoramix->villager[i].druid = panoramix->druid;
        if (pthread_create(&panoramix->villager[i].thread, NULL,
            villager_main_function, &panoramix->villager[i]) != 0)
            return 84;
    }
    return 0;
}

static int threads_join(panoramix_t *panoramix)
{
    if (pthread_join(panoramix->druid->thread, NULL) != 0)
        return 84;
    for (int i = 0; i < panoramix->arguments.nb_villagers; ++i) {
        if (pthread_join(panoramix->villager[i].thread, NULL) != 0)
            return 84;
    }
    return 0;
}

int panoramix_fct(panoramix_t *panoramix)
{
    if (create_druid(panoramix) == 84)
        return 84;
    sem_init(&panoramix->druid->sem_wait_druid, 0, 0);
    sem_init(&panoramix->druid->sem_wait_villager, 0, 0);
    if (create_villagers(panoramix) == 84)
        return 84;
    if (threads_join(panoramix) == 84)
        return 84;
    sem_destroy(&panoramix->druid->sem_wait_druid);
    sem_destroy(&panoramix->druid->sem_wait_villager);
    pthread_mutex_destroy(&panoramix->druid->refill);
    return 0;
}
