/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** wrong_cmd.c
*/

#include "../../includes/cli.h"
#include "../../../libs/myteams/logging_client.h"

void print_wrong_command(client_t *client)
{
    printf("%s\n", client->data);
}