/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** pass.c
*/

#include "../../include/ftp.h"

void cmd_pass(t_ftp *ftp, char *command, int i)
{
    char **cmd_arg = my_str_to_word_array(command, "\t\n\r ");

    if (ftp->clients[i].logged == true) {
        send_response(ftp->clients[i].cmd_socket,
        "%s\r\n", "230 Already logged in.\n");
        return free_str_to_word_array(cmd_arg);
    }
    if (ftp->clients[i].username != NULL) {
        if (!strcmp("Anonymous", ftp->clients[i].username)) {
            send_response(ftp->clients[i].cmd_socket,
            "%s\r\n", "230 User logged in, proceed.");
            ftp->clients[i].logged = true;
        } else
            send_response(ftp->clients[i].cmd_socket,
            "%s\r\n", "530 Login incorrect.");
    } else
        send_response(ftp->clients[i].cmd_socket,
        "%s\r\n", "332 Need account for login.");
    free_str_to_word_array(cmd_arg);
}
