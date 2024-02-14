/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** main.c
*/

#include "../includes/cli.h"
#include "../../libs/myteams/logging_client.h"

void catch_sig(int sig)
{
    sig = sig;
    exit(0);
}

int main(int argc, char **argv)
{
    char buffer[1024];

    if (argc != 3) return 84;
    client_t *client = init_client(argv);
    if (client == NULL) return 84;
    signal(SIGINT, catch_sig);
    while (1) {
        select_data(client);
        read_data_socket(client);
        read_stdin_data(client, buffer);
        if (client->sending != NULL)
            prepare_data(client);
        write_data_socket(client);
    }
    close(client->sockfdclient);
    return 0;
}
