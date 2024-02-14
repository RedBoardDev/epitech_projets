/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** command_handler.c
*/

#include "../include/ftp.h"

int check_if_logged(t_client client)
{
    if (client.logged)
        return 0;
    send_response(client.cmd_socket, "530 %s\r\n", "Not logged in.");
    return 84;
}

void check_command(t_ftp *ftp, char *command, int i, t_command *command_struct)
{
    char **cmd_array = my_str_to_word_array(command, "\t\n\r ");

    if (!cmd_array || cmd_array[0] == NULL || cmd_array[0][0] == '\0') {
        send_response(ftp->clients[i].cmd_socket,
        "%s\r\n", "500 Wrong command");
        free_str_to_word_array(cmd_array);
        return;
    }
    for (int r = 0; r < NBR_CMD; r++) {
        if (strcmp(command_struct[r].name, cmd_array[0]) == 0) {
            return (command_struct[r].need_login ?
            (check_if_logged(ftp->clients[i]) == 0 ?
            (*command_struct[r].function)(ftp, command, i) : 84) :
            (*command_struct[r].function)(ftp, command, i));
        }
    }
    send_response(ftp->clients[i].cmd_socket, "%s\r\n", "500 Wrong command");
    free_str_to_word_array(cmd_array);
}
