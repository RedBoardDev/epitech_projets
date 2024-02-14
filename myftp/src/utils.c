/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** utils.c
*/

#include "../include/ftp.h"

bool isnumeric(const char *s)
{
    while (*s) {
        if (*s < '0' || *s > '9')
            return false;
        ++s;
    }
    return true;
}

void send_response(int socket, char *format, char *buffer)
{
    dprintf(socket, format, buffer);
}

char *replace_char(char *str, char find, char replace)
{
    char *current_pos = strchr(str, find);
    while (current_pos) {
        *current_pos = replace;
        current_pos = strchr(current_pos, find);
    }
    return str;
}

// void free_memory(t_ftp *ftp, t_command *command)
// {
//     for (int i = 0; i < 1024; ++i) {
//         close_data_socket(ftp, i);
//         close_client_socket(ftp, i);
//     }
//     for (int i = 0; i < NBR_CMD; ++i) {
//         free(command[i].function);
//         free(command[i].name);
//     }
//     free(command);
// }
