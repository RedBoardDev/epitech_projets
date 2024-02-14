/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** noop.c
*/

#include "../../include/ftp.h"

void cmd_noop(t_ftp *ftp, char *command, int i)
{
    send_response(ftp->clients[i].cmd_socket, "%s\r\n",
    "200 Command okay.");
}
