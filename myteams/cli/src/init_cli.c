/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** init_cli.c
*/

#include "../includes/cli.h"

client_t *init_client(char **argv)
{
    client_t *client = malloc(sizeof(client_t));
    client->sending = malloc(1000);
    client->sending[0] = 0;
    client->data = NULL;
    client->sockfdclient = socket(PF_INET, SOCK_STREAM, 0);
    if (client->sockfdclient == -1) return NULL;
    client->sckdr.sin_family = AF_INET;
    in_port_t port = atoi(argv[2]);
    client->sckdr.sin_port = htons(port);
    client->sckdr.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(client->sockfdclient, (struct sockaddr *)&client->sckdr,
    sizeof(client->sckdr))) {
        perror("connect");
        return NULL;
    }
    return client;
}
