/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** error.c
*/

#include "../../includes/cli.h"
#include "../../../libs/myteams/logging_client.h"

void client_alr_exist(client_t *client)
{
    client_error_already_exist();
}

void client_unaut(client_t *client)
{
    client_error_unauthorized();
}
