/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** print_team.c
*/

#include "../../includes/cli.h"
#include "../../../libs/myteams/logging_client.h"

void part_list_print_team(client_t *client, char *tiktok)
{
    char ud[1000];char nm[1000];char desc[1000];int j = 0;int sbl = 0;
    for (int i = 0; tiktok[i] != 0; i++) {
        if (client->data[i] == '|')list_print_team(client);
        if (sbl == 2) {
            desc[j] = tiktok[i];j++;
        }
        if (sbl == 1 && tiktok[i] == '~') {
            sbl++;nm[j] = 0;j = 0;
        }
        if (sbl == 1) {
            nm[j] = tiktok[i];j++;
        }
        if (sbl == 0 && tiktok[i] == '~') {
            sbl++;ud[j] = 0;j = 0;
        }
        if (sbl == 0) {
            ud[j] = tiktok[i];j++;
        }
    }
    desc[j] = 0;client_print_teams(ud, nm, desc);
}

void list_print_team(client_t *client)
{
    char *tiktok = strtok(client->data, "|");
    while (tiktok != NULL) {
        part_list_print_team(client, tiktok);
        tiktok = strtok(NULL, "|");
    }
}
