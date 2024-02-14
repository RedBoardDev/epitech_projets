/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** feat.c
*/

#include "../../include/ftp.h"

void cmd_feat(t_ftp *ftp, char *command, int i)
{
    send_response(ftp->clients[i].cmd_socket, "%s\r\n",
    "211 on se fait un feat ?");
}
