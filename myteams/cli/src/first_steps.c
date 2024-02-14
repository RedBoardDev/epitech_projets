/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** first_steps.c
*/

#include "../includes/cli.h"
#include "../../libs/myteams/logging_client.h"

void part_check_cmd(client_t *client, char *code)
{
    if (strcmp(code, "170") == 0)cclient_print_user(client);
    if (strcmp(code, "171") == 0)cclient_print_team(client);
    if (strcmp(code, "172") == 0)cclient_print_channel(client);
    if (strcmp(code, "173") == 0)cclient_print_thread(client);
    if (strcmp(code, "132") == 0)sub_function(client);
    if (strcmp(code, "133") == 0)subd_function(client);
    if (strcmp(code, "233") == 0)subd_wfunction(client);
    if (strcmp(code, "134") == 0)unsub_function(client);
    if (strcmp(code, "990") == 0)event_login(client);
    if (strcmp(code, "991") == 0)event_logout(client);
    if (strcmp(code, "992") == 0)event_cteam(client);
    if (strcmp(code, "993") == 0)event_cchannel(client);
    if (strcmp(code, "994") == 0)event_thread_created(client);
    if (strcmp(code, "995") == 0)event_reply_created(client);
    if (strcmp(code, "130") == 0)send_cmd(client);
    if (strcmp(code, "131") == 0)messages_cmd(client);
    if (strcmp(code, "800") == 0)client_alr_exist(client);
    if (strcmp(code, "801") == 0)client_unaut(client);
}

void check_cmd(client_t *client)
{
    char code[4] = {client->data[0], client->data[1], client->data[2], 0};
    client->data = (client->data + 4);
    if (strcmp(code, "100") == 0)print_help(client);
    if (strcmp(code, "500") == 0)print_wrong_command(client);
    if (strcmp(code, "110") == 0)print_login_data(client);
    if (strcmp(code, "111") == 0)print_logout_data(client);
    if (strcmp(code, "120") == 0)print_user_list(client);
    if (strcmp(code, "121") == 0)cclient_print_user(client);
    if (strcmp(code, "140") == 0)use_function_successed(client);
    if (strcmp(code, "150") == 0)print_team_created(client);
    if (strcmp(code, "151") == 0)print_channel_created(client);
    if (strcmp(code, "152") == 0)print_thread_created(client);
    if (strcmp(code, "153") == 0)print_reply_created(client);
    if (strcmp(code, "160") == 0)list_print_team(client);
    if (strcmp(code, "161") == 0)list_print_channel(client);
    if (strcmp(code, "162") == 0)list_print_thread(client);
    if (strcmp(code, "163") == 0)list_print_reply(client);
    part_check_cmd(client, code);
}

void read_data_socket(client_t * client)
{
    if (FD_ISSET(client->sockfdclient, &client->readfs)) {
        char buf[100000];
        int rt_read = read(client->sockfdclient, buf, (100000 - 1));
        if (rt_read == 0) exit(84);
        buf[rt_read - 2] = 0;
        client->data = strdup(buf);
        check_cmd(client);
    }
}

void write_data_socket(client_t *client)
{
    if ((client->sending != NULL) && (FD_ISSET(client->sockfdclient,
    &client->writefs))) {
        write(client->sockfdclient, client->sending, strlen(client->sending));
        free(client->sending);
        client->sending = NULL;
    }
}

void select_data(client_t *client)
{
    FD_ZERO(&client->readfs);
    FD_ZERO(&client->writefs);
    FD_SET(client->sockfdclient, &client->readfs);
    FD_SET(client->sockfdclient, &client->writefs);
    if (select(client->sockfdclient + 1, &client->readfs, &client->writefs, NULL
    , &((struct timeval) {0, 100})) == -1)
        perror("select");

    FD_ZERO(&client->stdinfs);
    FD_SET(0, &client->stdinfs);
    select(1, &client->stdinfs, NULL, NULL, &((struct timeval) {0, 100}));
}
