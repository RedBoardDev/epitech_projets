/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main_corewar.c
*/

#include "../include/corewar.h"
#include "../include/preprocessor.h"
#include "../include/op.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

header_t read_infos(flags_t *flags)
{
    int fd = open(flags->prog_name, O_RDONLY);
    header_t header;
    read(fd, &header, sizeof(header_t));
    header.prog_size = rev_int(header.prog_size);
    header.magic = rev_int(header.magic);
    close(fd);
    return header;
}

void init_things(flags_t **flags, int nb_ch, things_t *things)
{
    things->all_process = malloc(sizeof(process_t));
    things->id_name = malloc(sizeof(process_id_name_t));
    things->arena = malloc(sizeof(char) * MEM_SIZE);
    things->nb_champ = 0;
    things->cycle_to_die = CYCLE_TO_DIE;
    things->nb_live = 0;
    things->next_check = CYCLE_TO_DIE;
    things->nb_alive = 0;
}

things_t *init_champion(flags_t **flags, int nb_ch)
{
    things_t *things = malloc(sizeof(things_t));
    header_t header_tmp;

    init_things(flags, nb_ch, things);
    for (int i = 0; i < MEM_SIZE; ++i)
        things->arena[i] = 0;
    things->all_process = NULL;
    for (int i = 0; i < nb_ch; ++i) {
        header_tmp = read_infos(flags[i]);
        add_process(i, &things->all_process, header_tmp, flags[i]);
        add_id_name(header_tmp.prog_name, i, &things->id_name, flags[i]);
        things->nb_champ += 1;
    }
    return things;
}