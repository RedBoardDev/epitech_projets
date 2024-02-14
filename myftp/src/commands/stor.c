/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** stor.c
*/

#include "../../include/ftp.h"

int stor_get_new_socket(t_ftp *ftp, int i)
{
    int addrlen = sizeof(ftp->clients[i].address);
    int new_socket = (ftp->clients[i].data_mode == mode_passive ?
        accept(ftp->clients[i].data_socket,
        (struct sockaddr *)&ftp->clients[i].address,
        (socklen_t *)&addrlen) : ftp->clients[i].data_socket);
    if (new_socket == -1) return -1;
    if (ftp->clients[i].data_mode == mode_active)
        connect(new_socket, (struct sockaddr *)&ftp->clients[i].address,
    sizeof(ftp->clients[i].address));
    return new_socket;
}

int stor_clean_return(int new_socket, int fd, char *content, int ret)
{
    close(new_socket);
    free(content);
    close(fd);
    return ret;
}

int stor_receive_data(t_ftp *ftp, int i, char *filepath, int new_socket)
{
    int fd;
    ssize_t bytes_read;
    char *content = NULL;

    fd = open(filepath, O_CREAT | O_WRONLY, 0644);
    if (fd < 0) return 84;
    content = malloc(sizeof(char) * (1));
    if (content == NULL) return stor_clean_return(new_socket, fd, content, 84);
    while ((bytes_read = read(new_socket, content, 1)) > 0)
        write(fd, content, bytes_read);
    stor_clean_return(new_socket, fd, content, 84);
    return 0;
}

int check_stor_arg(t_ftp *ftp, int i, char **cmd_arg)
{
    if (cmd_arg == NULL || cmd_arg[1] == NULL) {
        send_response(ftp->clients[i].cmd_socket,
        "%s\r\n", "501 Syntax error in parameters or arguments.");
        free_str_to_word_array(cmd_arg);
        return 84;
    }
    return 0;
}

void cmd_stor(t_ftp *ftp, char *command, int i)
{
    int new_socket = 0;
    char **cmd_arg = NULL;
    if (!check_mode(ftp, i)) return;
    cmd_arg = my_str_to_word_array(command, "\t\n\r ");
    if (check_stor_arg(ftp, i, cmd_arg)) return;
    send_response(ftp->clients[i].cmd_socket, "%s\r\n",
    "150 File status okay; about to open data connection.");
    new_socket = stor_get_new_socket(ftp, i);
    if (new_socket == -1)
        send_response(ftp->clients[i].cmd_socket,
        "%s\r\n", "425 Can't open data connection.");
    else if (stor_receive_data(ftp, i, cmd_arg[1], new_socket) == 84)
        send_response(ftp->clients[i].cmd_socket,
        "%s\r\n", "550 File not found");
    else
        send_response(ftp->clients[i].cmd_socket, "%s\r\n",
        "226 Closing data connection. Requested file action successful.");
    close_data_socket(ftp, i);
    free_str_to_word_array(cmd_arg);
}
