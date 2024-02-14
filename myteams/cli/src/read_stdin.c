/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** read_stdin.c
*/

#include "../includes/cli.h"

bool read_stdin_data(client_t *client, char *buffer)
{
    char tmp[1024] = { 0 };

    if (FD_ISSET(0, &client->stdinfs)) {
        if (fgets(buffer, 1024, stdin) == NULL)
            exit(0);
        strncpy(tmp, buffer, strlen(buffer) - 1);
        sprintf(buffer, "%s", tmp);
        client->sending = strdup(buffer);
    }
    return true;
}
