/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** socket.c
*/

#include "../include/ftp.h"

int check_mode(t_ftp *ftp, int i)
{
    if (ftp->clients[i].data_socket == 0 ||
    ftp->clients[i].data_mode == mode_disable) {
        send_response(ftp->clients[i].cmd_socket, "%s\r\n",
        "425 Can't open data connection.");
        return 0;
    }
    return 1;
}

void close_data_socket(t_ftp *ftp, int i)
{
    if (ftp->clients[i].data_socket != 0)
        close(ftp->clients[i].data_socket);
    ftp->clients[i].data_socket = 0;
    memset(&ftp->clients[i].address, 0, sizeof(ftp->clients[i].address));
    ftp->clients[i].data_mode = mode_disable;
}

void close_client_socket(t_ftp *ftp, int i)
{
    if (ftp->clients[i].cmd_socket != 0)
        close(ftp->clients[i].cmd_socket);
    ftp->clients[i].cmd_socket = 0;
    ftp->clients[i].logged = false;
    free(ftp->clients[i].username);
    ftp->clients[i].username = NULL;
}
