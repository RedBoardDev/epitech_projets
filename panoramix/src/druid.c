/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** druid.c
*/

#include "../include/panoramix.h"

void *druid_main_function(void *panoramix_void)
{
    panoramix_t *panoramix = (panoramix_t *)panoramix_void;

    druid_thread_start();
    while (panoramix->druid->nb_refill > 0) {
        sem_wait(&panoramix->druid->sem_wait_villager);
        panoramix->druid->pot = panoramix->druid->pot_size;
        panoramix->druid->nb_refill -= 1;
        druid_refill_pot(panoramix->druid->nb_refill);
        sem_post(&panoramix->druid->sem_wait_druid);
    }
    druid_runs_out();
    return 0;
}
