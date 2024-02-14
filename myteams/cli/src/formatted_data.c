/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** formatted_data.c
*/

#include "../includes/cli.h"

static void data_move1(client_t *client, char *new_cmd, int *j, int *i)
{
    new_cmd[*j] = 34;
    ++*j;
    while (client->sending[*i] != 34) {
        new_cmd[*j] = client->sending[*i];
        ++*j;
        ++*i;
    }
    new_cmd[*j] = 34;
    ++*j;
}

static void data_pass_space(const char *sending, int *i)
{
    while (sending[*i] == ' ')
        ++*i;
}

static void copy_data_while_not_stop(client_t *client,
char *new_cmd, int *j, int *i)
{
    while (client->sending[*i] != '\0' && client->sending[*i] != ' '
    && client->sending[*i] != 34) {
        new_cmd[*j] = client->sending[*i];
        ++*j;
        ++*i;
    }
}

void prepare_data(client_t *client)
{
    int j = 0;int i = 0;
    bool cote = false;
    char *new_cmd = malloc(sizeof(char) * strlen(client->sending) + 3);

    copy_data_while_not_stop(client, new_cmd, &j, &i);
    for (; client->sending[i] != '\0'; ++i) {
        data_pass_space(client->sending, &i);
        if (!cote && client->sending[i] == 34) {
            cote = true;
            ++i;
        }
        if (cote) {
            data_move1(client, new_cmd, &j, &i);
            cote = false;
        }
    }
    new_cmd[j] = 0;
    free(client->sending);
    client->sending = strdup(new_cmd);
    free(new_cmd);
}
