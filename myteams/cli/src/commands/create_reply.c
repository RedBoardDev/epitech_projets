/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** create_reply.c
*/

#include "../../includes/cli.h"
#include "../../../libs/myteams/logging_client.h"

void part_print_reply_created(client_t *client, char *tiktok)
{
    char udteam[1000];char udchan[1000];char time[1000];int j = 0;int sbl = 0;
    char title[1000];char body[1000];
    for (int i = 0; tiktok[i] != 0; i++) {
        if (client->data[i] == '|')print_reply_created(client);
        if (sbl == 4) {body[j] = tiktok[i];j++;
        }if (sbl == 3 && tiktok[i] == '~') {title[j] = 0;j = 0;++sbl;
        }if (sbl == 3) {title[j] = tiktok[i];j++;
        }if (sbl == 2 && tiktok[i] == '~') {time[j] = 0;j = 0;++sbl;
        }if (sbl == 2) {time[j] = tiktok[i];j++;
        }if (sbl == 1 && tiktok[i] == '~') {udchan[j] = 0;j = 0;sbl++;
        }if (sbl == 1) {udchan[j] = tiktok[i];j++;
        }if (sbl == 0 && tiktok[i] == '~') {udteam[j] = 0;j = 0;sbl++;
        }if (sbl == 0) {udteam[j] = tiktok[i];j++;
        }
    }
    body[j] = 0;
    client_print_reply_created(udteam, udchan, atoi(time), title);
    client_event_thread_reply_received(body, udteam, udchan, title);
}

void print_reply_created(client_t *client)
{
    char *tiktok = strtok(client->data, "|");
    part_print_reply_created(client, tiktok);
}
