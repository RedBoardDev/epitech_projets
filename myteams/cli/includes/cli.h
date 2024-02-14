/*
** EPITECH PROJECT, 2023
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** cli
*/

#ifndef CLI_H_
    #define CLI_H_

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <sys/un.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <netinet/in.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <signal.h>
    #include <assert.h>
    #include <sys/select.h>
    #include <stdbool.h>

typedef struct client_s {
    struct sockaddr_in sckdr;
    int sockfdclient;
    char *data;
    char *sending;
    fd_set readfs;
    fd_set writefs;
    fd_set stdinfs;
} client_t;

// INIT_CLI.C
client_t *init_client(char **argv);

// FIRST_STEPS.C
void read_data_socket(client_t * client);
void write_data_socket(client_t *client);
void select_data(client_t *client);
bool read_stdin_data(client_t *client, char *buffer);

// PREPARE_DATA.C
void prepare_data(client_t *client);

//LOGIN.C
void print_login_data(client_t *client);

//LOGOUT.C
void print_logout_data(client_t *client);

//USERS.C
void print_user_list(client_t *client);
void part_print_user_list(client_t *client, char *tiktok);

// HELP.C
void print_help(client_t *client);

// WRONG_CMD.c
void print_wrong_command(client_t *client);

// USE_SUCCESSED.C
void use_function_successed(client_t *client);

// CREATE_TEAM.C
void print_team_created(client_t *client);
void part_print_team_created(client_t *client, char *tiktok);

// CREATE_CHANNEL.c
void print_channel_created(client_t *client);
void part_print_channel_created(client_t *client, char *tiktok);

// CREATE_THREAD.C
void print_thread_created(client_t *client);
void part_print_thread_created(client_t *client, char *tiktok);

// CREATE REPLY.C
void print_reply_created(client_t *client);
void part_print_reply_created(client_t *client, char *tiktok);

// PRINT TEAM.C
void list_print_team(client_t *client);
void part_list_print_team(client_t *client, char *tiktok);

// PRINT_CHANNEL.C
void list_print_channel(client_t *client);
void part_list_print_channel(client_t *client, char *tiktok);

// PRINT THREADS.C
void list_print_thread(client_t *client);
void part_list_print_thread(client_t *client, char *tiktok);

// PRINT_REPLY.C
void list_print_reply(client_t *client);
void part_list_print_reply(client_t *client, char *tiktok);

// INFO_USER.C
void cclient_print_user(client_t *client);

// INFO_TEAM.C
void cclient_print_team(client_t *client);

// INFO_CHANNEL.C
void cclient_print_channel(client_t *client);

// INFO_THREAD.C
void cclient_print_thread(client_t *client);

// SUB_FUNCTION.C
void sub_function(client_t *client);

// SUBD_FUNCTION.C
void part_subd_function(client_t *client, char *tiktok);
void subd_function(client_t *client);
void part_subd_wfunction(client_t *client, char *tiktok);
void subd_wfunction(client_t *client);

// UNSUB_FUNCTION.C
void unsub_function(client_t *client);

// EVENT_LOG.C
void event_login(client_t *client);
void event_logout(client_t *client);

// EVENT_CREATETEAM.C
void event_cteam(client_t *client);
void part_event_cteam(client_t *client, char *tiktok);

// EVENT_CREATECHANNEL.C
void event_cchannel(client_t *client);
void part_event_cchannel(client_t *client, char *tiktok);

// EVENT_CREATETHREAD.C
void event_thread_created(client_t *client);
void part_event_thread_created(client_t *client, char *tiktok);

// EVENT_CREATEREPLY.C
void event_reply_created(client_t *client);
void part_event_reply_created(client_t *client, char *tiktok);

// SND_MSG.C
void messages_cmd(client_t *client);
void part_messages_cmd(client_t *client, char *tiktok);
void send_cmd(client_t *client);

#endif /* !CLI_H_ */
