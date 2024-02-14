/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** druid_messages.c
*/

#include <stdio.h>

void druid_thread_start(void)
{
    printf("Druid: I'm ready... but sleepy...\n");
}

void druid_refill_pot(int refills)
{
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only "
        "make %d more refills after this one.\n", refills);
}

void druid_runs_out(void)
{
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
}
