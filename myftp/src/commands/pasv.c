/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** pasv.c
*/

#include "../../include/ftp.h"

void init_client_socket(t_ftp *ftp, int i)
{
    int oui = true;
    ftp->clients[i].data_socket = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(ftp->clients[i].data_socket,
    SOL_SOCKET, SO_REUSEADDR, &oui, sizeof(oui));
    ftp->clients[i].address.sin_family = AF_INET;
    ftp->clients[i].address.sin_addr.s_addr = INADDR_ANY;
    ftp->clients[i].address.sin_port = htons(60000 + i);
    bind(ftp->clients[i].data_socket,
    (struct sockaddr *)&ftp->clients[i].address,
    sizeof(ftp->clients[i].address));
}

void cmd_pasv(t_ftp *ftp, char *command, int i)
{
    init_client_socket(ftp, i);
    listen(ftp->clients[i].data_socket, 10);
    dprintf(ftp->clients[i].cmd_socket,
    "227 Entering Passive Mode (%s,%u,%u)\r\n", "127,0,0,1",
    ntohs(ftp->clients[i].address.sin_port) / 256,
    ntohs(ftp->clients[i].address.sin_port) % 256);
    ftp->clients[i].data_mode = mode_passive;
}
