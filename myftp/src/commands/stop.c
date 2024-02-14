/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** cdup.c
*/

#include "../../include/ftp.h"

void cmd_stop(t_ftp *ftp, char *command, int i)
{
    send_response(ftp->clients[i].cmd_socket,
    "%s\r\n", "221 Service closing control connection.");
    close_client_socket(ftp, i);
    close(ftp->server.socket);
    exit(0);
}
