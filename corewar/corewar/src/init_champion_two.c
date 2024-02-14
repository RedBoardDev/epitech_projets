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

char *get_name_from_id(int id, process_id_name_t *id_name)
{
    process_id_name_t *temp;

    temp = id_name;
    while (temp != NULL) {
        if (id == temp->id)
            return temp->name;
        temp = temp->next;
    }
}

void add_process(int id, process_t **all_process, header_t header_tmp,
flags_t *flags)
{
    process_t *temp = malloc(sizeof(process_t));
    int fd;
    header_t header;

    temp->carry = 1;
    temp->magic = header_tmp.magic;
    temp->prog_size = header_tmp.prog_size;
    temp->name = malloc(sizeof(char) * my_strlen(header_tmp.prog_name) + 1);
    cp_in_string(header_tmp.prog_name, temp->name);
    temp->comment = malloc(sizeof(char) * my_strlen(header_tmp.comment) + 1);
    cp_in_string(header_tmp.comment, temp->comment);
    temp->reg = malloc(sizeof(int) * (REG_NUMBER));
    for (int i = 0; i < REG_NUMBER; ++i)
        temp->reg[i] = 0;
    temp->reg[0] = (flags->prog_number != -1) ? (flags->prog_number) : (id);
    temp->next = *all_process;
    temp->prog = malloc(sizeof(char) * temp->prog_size);
    temp->current = 0;
    temp->load_adresse = flags->load_address;
    fd = open(flags->prog_name, O_RDONLY);
    read(fd, &header , sizeof(header_t));
    read(fd, temp->prog, temp->prog_size);
    close(fd);
    *all_process = temp;
}

void add_id_name(char const *name, int id, process_id_name_t **id_name,
flags_t *flags)
{
    process_id_name_t *temp = malloc(sizeof(process_id_name_t));

    temp->id = (flags->prog_number != -1) ? (flags->prog_number) : (id);
    temp->name = malloc(sizeof(char) * my_strlen(name) + 1);
    cp_in_string(name, temp->name);
    temp->is_dead = 0;
    temp->this_cycle = 0;
    temp->next = *id_name;
    *id_name = temp;
}