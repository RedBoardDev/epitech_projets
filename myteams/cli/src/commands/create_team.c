/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** create_team.c
*/

#include "../../includes/cli.h"
#include "../../../libs/myteams/logging_client.h"

void all_team(char *ud, char *nm, char *desc)
{
    client_print_team_created(ud, nm, desc);
    client_event_team_created(ud, nm, desc);
}

void part_print_team_created(client_t *client, char *tiktok)
{
    char ud[1000];char nm[1000];char desc[1000];int j = 0;int sbl = 0;
    for (int i = 0; tiktok[i] != 0; i++) {
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
    desc[j] = 0;all_team(ud, nm, desc);
}

void print_team_created(client_t *client)
{
    char *tiktok = strtok(client->data, "|");
    part_print_team_created(client, tiktok);
}
