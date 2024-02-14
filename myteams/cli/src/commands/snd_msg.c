/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** snd_msg.c
*/

#include "../../includes/cli.h"
#include "../../../libs/myteams/logging_client.h"

void send_cmd(client_t *client)
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
    client_event_private_message_received(uuid, name);
}

void part_messages_cmd(client_t *client, char *tiktok)
{
    char ud[1000];char nm[1000];char desc[1000];int j = 0;int sbl = 0;
    for (int i = 0; tiktok[i] != 0; i++) {
        if (client->data[i] == '|')messages_cmd(client);
        if (sbl == 2) {desc[j] = tiktok[i];j++;
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
    desc[j] = 0;client_private_message_print_messages(ud, atoi(nm), desc);
}

void messages_cmd(client_t *client)
{
    char *tiktok = strtok(client->data, "|");
    while (tiktok != NULL) {
        part_messages_cmd(client, tiktok);
        tiktok = strtok(NULL, "|");
    }
}
