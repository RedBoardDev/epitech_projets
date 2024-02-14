/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-thomas.ott
** File description:
** connexion.c
*/

#include "../include/teams.h"

void read_connexion_next(teams_t *teams, fd_set *readfds,
command_t *command_struct)
{
    int size_read = 0;
    char command[10000];

    if (FD_ISSET(teams->clients[teams->iterator].socket , readfds)) {
        if ((size_read = read(teams->clients[teams->iterator].socket,
        command, 10000 - 1)) == 0) {
            getpeername(teams->clients[teams->iterator].socket,
            (struct sockaddr *)&teams->server.address,
            (socklen_t *)&teams->addrlen);
            close_client_socket(teams);
        } else {
            command[size_read] = '\0';
            handler_command(teams, command, command_struct);
        }
    }
}

void read_connexion(teams_t *teams, fd_set readfds, command_t *command_struct)
{
    for (int i = 0; i < MAX_USERRR; ++i) {
        teams->iterator = i;
        read_connexion_next(teams, &readfds, command_struct);
    }
}
