/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** info_team.c
*/

#include "../../includes/cli.h"
#include "../../../libs/myteams/logging_client.h"

void cclient_print_thread(client_t *client)
{
    char udteam[1000];char udchan[1000];char time[1000];int j = 0;int sbl = 0;
    char title[1000];char body[1000];
    for (int i = 0; client->data[i] != 0; i++) {
        if (sbl == 4) {body[j] = client->data[i];j++;
        }if (sbl == 3 && client->data[i] == '~') {title[j] = 0;j = 0;++sbl;
        }if (sbl == 3) {title[j] = client->data[i];j++;
        }if (sbl == 2 && client->data[i] == '~') {time[j] = 0;j = 0;++sbl;
        }if (sbl == 2) {time[j] = client->data[i];j++;
        }if (sbl == 1 && client->data[i] == '~') {udchan[j] = 0;j = 0;sbl++;
        }if (sbl == 1) {udchan[j] = client->data[i];j++;
        }if (sbl == 0 && client->data[i] == '~') {udteam[j] = 0;j = 0;sbl++;
        }if (sbl == 0) {udteam[j] = client->data[i];j++;
        }
    }
    body[j] = 0;
    client_print_thread(udteam, udchan, atoi(time), title, body);
}
