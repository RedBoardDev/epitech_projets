/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-thomas.ott
** File description:
** server.c
*/

#include "../include/teams.h"

static void register_client_cmd_socket(teams_t *teams, int new_socket)
{
    for (int i = 0; i < MAX_USERRR; ++i) {
        if (teams->clients[i].socket == 0) {
            teams->clients[i].socket = new_socket;
            break;
        }
    }
}

static void set_client(teams_t *teams, fd_set *readfds, fd_set *writefds)
{
    int sd;

    FD_ZERO(readfds);
    FD_ZERO(writefds);
    FD_SET(teams->server.socket, readfds);
    FD_SET(teams->server.socket, writefds);
    for (int i = 0 ; i < MAX_USERRR ; ++i) {
        sd = teams->clients[i].socket;
        FD_SET(sd, readfds);
        FD_SET(sd, writefds);
    }
    if (select(FD_SETSIZE, readfds, writefds, NULL, NULL) == -1)
        return;
}

static void server_loop(teams_t *teams, command_t *command)
{
    fd_set readfds;
    fd_set writefds;
    int new_socket = 0;

    set_client(teams, &readfds, &writefds);
    read_connexion(teams, readfds, command);
    if (FD_ISSET(teams->server.socket, &readfds)) {
        new_socket = accept(teams->server.socket, (struct sockaddr *)
        &teams->server.address, (socklen_t *)&teams->addrlen);
        if (new_socket < 0) return;
        register_client_cmd_socket(teams, new_socket);
        if (FD_ISSET(new_socket, &writefds))
            send_response(new_socket, "%s\r\n", "101 Welcome");
    }
}

int server(int port)
{
    teams_t teams;
    command_t *command = init_cmd_struct();

    init_server_socket(port, &teams);
    init_clients(&teams);
    if (access("datafile.txt", F_OK) == 0)
        read_saved_data(&teams, "./datafile.txt");
    listen(teams.server.socket, 100);
    teams.addrlen = sizeof(teams.server.address);
    while (1)
        server_loop(&teams, command);
    return 0;
}
