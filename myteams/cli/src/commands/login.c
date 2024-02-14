/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** login.c
*/

#include "../../includes/cli.h"
#include "../../../libs/myteams/logging_client.h"

void print_login_data(client_t *client)
{
    char uuid[10000];char name[10000];
    int i = 0;int j = 0;bool booluuid = false;bool boolname = false;
    booluuid = true;
    for (; client->data[i] != '\0'; ++i) {
        if (boolname) {
            name[j] = client->data[i];++j;
        }
        if (client->data[i] == '~'){
            uuid[j] = 0;booluuid = false;boolname = true;j = 0;
        }
        if (booluuid) {
            uuid[j] = client->data[i];++j;
        }
    }name[j] = 0;
    client_event_logged_in(uuid, name);
}
