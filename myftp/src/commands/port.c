/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** port.c
*/

#include "../../include/ftp.h"

char *replace_x_char(char *str, char find, char replace, int nbr)
{
    char *current_pos = strchr(str, find);
    while (current_pos && nbr > 0) {
        *current_pos = replace;
        current_pos = strchr(current_pos, find);
        --nbr;
    }
    return str;
}

void cmd_port(t_ftp *ftp, char *command, int i)
{
    char **cmd_arg = NULL;

    command = replace_x_char(command, ',', '.', 3);
    cmd_arg = my_str_to_word_array(command, "\t\n\r, ");

    if (cmd_arg != NULL && cmd_arg[1] != NULL
    && cmd_arg[2] != NULL && cmd_arg[3] != NULL) {
        ftp->clients[i].data_socket = socket(AF_INET, SOCK_STREAM, 0);
        inet_pton(AF_INET, cmd_arg[1], &ftp->clients[i].address.sin_addr);
        ftp->clients[i].address.sin_family = AF_INET;
        ftp->clients[i].address.sin_port =
        htons(atoi(cmd_arg[2]) * 256 + atoi(cmd_arg[3]));
        send_response(ftp->clients[i].cmd_socket, "%s\r\n",
        "200 Command okay.");
        ftp->clients[i].data_mode = mode_active;
    } else
        send_response(ftp->clients[i].cmd_socket, "%s\r\n",
        "501 Syntax error in parameters or arguments.");
    free_str_to_word_array(cmd_arg);
}
