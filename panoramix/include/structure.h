/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** structure.h
*/

#ifndef STRUCTURE_H
    #define STRUCTURE_H

    typedef struct druid_s {
        int pot;
        int pot_size;
        int nb_refill;
        pthread_t thread;
        pthread_mutex_t refill;
        sem_t sem_wait_villager;
        pthread_mutex_t m_wait_druid;
        sem_t sem_wait_druid;
    } druid_t;

    typedef struct villager_s {
        int id;
        int nb_fights;
        pthread_t thread;
        druid_t *druid;
    } villager_t;

    typedef struct arguments_s {
        int nb_villagers;
        int pot_size;
        int nb_fights;
        int nb_refill;
    } arguments_t;

    typedef struct panoramix_s {
        arguments_t arguments;
        druid_t *druid;
        villager_t *villager;
        bool wait_druid;
    } panoramix_t;

    typedef struct thread_args_s {
        panoramix_t *panoramix;
        int i;
    } thread_args_t;

#endif
