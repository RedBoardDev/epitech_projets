/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** retr.c
*/

#include "../../include/ftp.h"

char *get_file_content(char *filepath)
{
    int fd = 0;
    struct stat stats;
    char *content = NULL;

    if (filepath == NULL) return NULL;
    fd = open(filepath, O_RDONLY);
    if (fd < 0) return NULL;
    if (stat(filepath, &stats) == -1) return NULL;
    content = malloc(sizeof(char) * (stats.st_size + 1));
    if (!content) return NULL;
    if (read(fd, content, stats.st_size) <= 0) return NULL;
    content[stats.st_size] = '\0';
    return content;
}

int retr_send_data(t_ftp *ftp, int i, char *content)
{
    int addrlen = sizeof(ftp->clients[i].address);
    int new_socket = (ftp->clients[i].data_mode == mode_passive ?
        accept(ftp->clients[i].data_socket,
        (struct sockaddr *)&ftp->clients[i].address,
        (socklen_t *)&addrlen) : ftp->clients[i].data_socket);
    if (ftp->clients[i].data_mode == mode_active)
        connect(new_socket, (struct sockaddr *)&ftp->clients[i].address,
    sizeof(ftp->clients[i].address));
    if (new_socket != 0)
        write(new_socket, content, strlen(content));
    close(new_socket);
    return 0;
}

void cmd_retr(t_ftp *ftp, char *command, int i)
{
    char *content = NULL;
    char **cmd_arg = NULL;
    if (!check_mode(ftp, i)) return;
    cmd_arg = my_str_to_word_array(command, "\t\n\r ");
    content = get_file_content(cmd_arg[1]);
    if (content != NULL) {
        send_response(ftp->clients[i].cmd_socket, "%s\r\n",
        "150 File status okay; about to open data connection.");
        retr_send_data(ftp, i, content);
        send_response(ftp->clients[i].cmd_socket, "%s\r\n",
        "226 Closing data connection. Requested file action successful.");
    } else
        send_response(ftp->clients[i].cmd_socket,
        "%s\r\n", "550 File not found");
    close_data_socket(ftp, i);
    free(content);
    free_str_to_word_array(cmd_arg);
}
