/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** use_successed.c
*/

#include "../../includes/cli.h"
#include "../../../libs/myteams/logging_client.h"

void use_function_successed(client_t *client)
{
    printf("%s\n", (client->data));
}
