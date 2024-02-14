/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** pwd.c
*/

#include "../../include/ftp.h"

void cmd_pwd(t_ftp *ftp, char *command, int i)
{
    char buff[1024];

    getcwd(buff, sizeof(buff));
    send_response(ftp->clients[i].cmd_socket, "257 \"%s\" created.\r\n", buff);
}
