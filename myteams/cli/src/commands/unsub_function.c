/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** unsub_function.c
*/

#include "../../includes/cli.h"
#include "../../../libs/myteams/logging_client.h"

void unsub_function(client_t *client)
{
    char ud[1000];char nm[1000];int j = 0;int sbl = 0;
    for (int i = 0; client->data[i] != 0; i++) {
        if (sbl == 1) {
            nm[j] = client->data[i];j++;
        }
        if (sbl == 0 && client->data[i] == '~') {
            sbl++;ud[j] = 0;j = 0;
        }
        if (sbl == 0) {
            ud[j] = client->data[i];j++;
        }
    }
    nm[j] = 0;
    client_print_unsubscribed(ud, nm);
}