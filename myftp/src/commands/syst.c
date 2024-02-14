/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** syst.c
*/

#include "../../include/ftp.h"

void cmd_syst(t_ftp *ftp, char *command, int i)
{
    send_response(ftp->clients[i].cmd_socket, "%s\r\n", "215 UNIX Type: L8");
}
