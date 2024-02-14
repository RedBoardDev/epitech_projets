/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** cwd.c
*/

#include "../../include/ftp.h"

void cmd_cwd(t_ftp *ftp, char *command, int i)
{
    char **cmd_arg = my_str_to_word_array(command, "\t\n\r ");

    if (cmd_arg != NULL && cmd_arg[1] != NULL) {
        if (chdir(cmd_arg[1]) == 0)
            send_response(ftp->clients[i].cmd_socket, "%s\r\n",
            "250 Requested file action okay, completed.");
        else
            send_response(ftp->clients[i].cmd_socket, "%s\r\n",
            "550 Requested action not taken. Directory not found.");
    } else
        send_response(ftp->clients[i].cmd_socket, "%s\r\n",
        "550 Syntax error in parameters or arguments.");
    free_str_to_word_array(cmd_arg);
}