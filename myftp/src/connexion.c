/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** connexion.c
*/

#include "../include/ftp.h"

void read_connexion2(t_ftp *ftp, fd_set readfds,
t_command *command_struct, int i)
{
    int size_read = 0;
    char *command = NULL;
    char *buffer = malloc(sizeof(char) * 1024);

    while ((size_read =
    read(ftp->clients[i].cmd_socket, buffer, 1024)) > 0) {
        buffer[size_read] = '\0';
        command = (command != NULL ?
        my_strcat(command, buffer) : strdup(buffer));
        if (command[strlen(command) - 1] == '\n'
        && command[strlen(command) - 2] == '\r') break;
    }
    if (size_read == 0) {
        getpeername(ftp->clients[i].cmd_socket,
        (struct sockaddr *)&ftp->server.address,
        (socklen_t *)&ftp->addrlen);
        close_client_socket(ftp, i);
    } else
        check_command(ftp, command, i, command_struct);
}

void read_connexion(t_ftp *ftp, fd_set readfds, t_command *command_struct)
{
    for (int i = 0; i < ftp->max_clients; ++i)
        if (FD_ISSET(ftp->clients[i].cmd_socket , &readfds))
            read_connexion2(ftp, readfds, command_struct, i);
}
