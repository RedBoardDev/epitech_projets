/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** help.c
*/

#include "../../include/ftp.h"

void cmd_help(t_ftp *ftp, char *command, int i)
{
    send_response(ftp->clients[i].cmd_socket, "%s\r\n",
    "214 ta cru j'allais t'aider ptdr ?");
}
