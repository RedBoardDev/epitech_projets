/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** panoramix.h
*/

#ifndef PANORAMIX_H
    #define PANORAMIX_H

    #include <stdlib.h>
    #include <pthread.h>
    #include <semaphore.h>
    #include <stdbool.h>
    #include "structure.h"

    // arguments
    bool verify_arguments(int argc, char const **argv);
    void fill_struct(panoramix_t *panoramix, char const **argv);

    // villager_messages
    void villager_thread_start(int id);
    void villager_drink_potion(int id, int nb_servings_left);
    void villager_call_druid_for_refill(int id);
    void villager_done_fight(int id);
    void villager_fighting(int id, int fight_left);

    // druid_messages
    void druid_thread_start(void);
    void druid_refill_pot(int refills);
    void druid_runs_out(void);

    // panoramix
    int panoramix_fct(panoramix_t *panoramix);

    // druid
    void *druid_main_function(void *panoramix_void);

    // villager
    void *villager_main_function(void *args);

#endif
