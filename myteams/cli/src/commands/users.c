/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** users.c
*/

#include "../../includes/cli.h"
#include "../../../libs/myteams/logging_client.h"

void part_print_user_list(client_t *client, char *tiktok)
{
    char ud[1000];char nm[1000];char con[1000];int j = 0;int sbl = 0;
    for (int i = 0; tiktok[i] != 0; i++) {
        if (client->data[i] == '|')print_user_list(client);
        if (sbl == 2) {
            con[j] = tiktok[i];j++;
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
    con[j] = 0;client_print_users(ud, nm, strcmp(con, "true") == 0 ? 1 : 0);
}

void print_user_list(client_t *client)
{
    char *tiktok = strtok(client->data, "|");
    while (tiktok != NULL) {
        part_print_user_list(client, tiktok);
        tiktok = strtok(NULL, "|");
    }
}
