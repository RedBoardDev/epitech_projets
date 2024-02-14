/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** list.c
*/

#include "../../include/ftp.h"

void list_error(t_ftp *ftp, int i, int new_socket)
{
    send_response(ftp->clients[i].cmd_socket, "%s\r\n", "400 Error");
    close(new_socket);
}

void forked_list(t_ftp *ftp, char *command, int i)
{
    FILE *fp;
    char path[4096];
    int new_socket = 0;
    int addrlen = sizeof(ftp->clients[i].address);

    new_socket = (ftp->clients[i].data_mode == mode_passive ?
    accept(ftp->clients[i].data_socket,
    (struct sockaddr *)&ftp->clients[i].address,
    (socklen_t *)&addrlen) : ftp->clients[i].data_socket);
    if (ftp->clients[i].data_mode == mode_active)
        connect(new_socket, (struct sockaddr *)&ftp->clients[i].address,
    sizeof(ftp->clients[i].address));
    fp = popen("/bin/ls -l .", "r");
    if (fp == NULL)
        return list_error(ftp, i, new_socket);
    while (fgets(path, sizeof(path), fp) != NULL)
        send_response(new_socket, "%s", path);
    close(new_socket);
    pclose(fp);
}

void cmd_list(t_ftp *ftp, char *command, int i)
{
    if (!check_mode(ftp, i)) return;
    send_response(ftp->clients[i].cmd_socket, "%s\r\n",
    "150 File status okay; about to open data connection.");
    forked_list(ftp, command, i);
    close_data_socket(ftp, i);
    send_response(ftp->clients[i].cmd_socket, "%s\r\n",
    "226 Closing data connection. Requested file action successful.");
}
