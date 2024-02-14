/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** quit.c
*/

#include "../../include/ftp.h"

void cmd_quit(t_ftp *ftp, char *command, int i)
{
    send_response(ftp->clients[i].cmd_socket,
    "%s\r\n", "221 Service closing control connection.");
    close_client_socket(ftp, i);
    if (ftp->test_mode == true) exit(0);
}
