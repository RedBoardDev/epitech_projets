/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** server.c
*/

#include "../include/ftp.h"

void register_client_cmd_socket(t_ftp *ftp, int new_socket)
{
    for (int i = 0; i < ftp->max_clients; ++i) {
        if (ftp->clients[i].cmd_socket == 0) {
            ftp->clients[i].cmd_socket = new_socket;
            break;
        }
    }
}

void set_client(t_ftp *ftp, fd_set *readfds)
{
    int sd = 0;
    FD_ZERO(readfds);
    FD_SET(ftp->server.socket, readfds);
    int max_sd = ftp->server.socket;
    for (int i = 0 ; i < ftp->max_clients ; ++i) {
        sd = ftp->clients[i].cmd_socket;
        if (sd > 0)
            FD_SET(sd, readfds);
        if (sd > max_sd)
            max_sd = sd;
    }
    select(max_sd + 1, readfds, NULL, NULL, NULL);
}

void server_loop(t_ftp *ftp, t_command *command)
{
    fd_set readfds;
    int new_socket = 0;

    set_client(ftp, &readfds);
    if (FD_ISSET(ftp->server.socket, &readfds)) {
        new_socket = accept(ftp->server.socket,
        (struct sockaddr *)&ftp->server.address, (socklen_t *)&ftp->addrlen);
        printf("New connection , socket fd is %d , ip is : %s , port : %d\n",
        new_socket, inet_ntoa(ftp->server.address.sin_addr),
        ntohs(ftp->server.address.sin_port));
        register_client_cmd_socket(ftp, new_socket);
        send_response(new_socket, "%s\r\n", "220 Welcome");
    }
    read_connexion(ftp, readfds, command);
}

int server(int argc, char **argv, bool mode)
{
    t_ftp ftp;
    t_command *command = init_cmd_struct();

    ftp.test_mode = mode;
    if (init_ftp_struct(argc, argv, &ftp) == 84)
        return 84;
    init_clients(&ftp);
    init_server_socket(&ftp);
    printf("Listener on port %d \n", ftp.server.port);
    listen(ftp.server.socket, 10);
    ftp.addrlen = sizeof(ftp.server.address);
    printf("Waiting for connections ...");
    while (1)
        server_loop(&ftp, command);
    return 0;
}
