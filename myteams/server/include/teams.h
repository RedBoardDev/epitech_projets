/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-teams-thomas.ott
** File description:
** teams.h
*/

#ifndef TEAMS_H
    #define TEAMS_H

    #include <fcntl.h>
    #include <stdbool.h>
    #include "struct.h"
    #include <stdlib.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <stdio.h>
    #include <string.h>
    #include <errno.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/time.h>
    #include "../../libs/myteams/logging_server.h"

    #define NBR_CMD 19
    #define MAX_USERRR 4096

    enum logType {
        LOGT_CHANNEL,
        LOGT_COMMENT,
        LOGT_TEAM,
        LOGT_THREAD,
        LOGT_USER,
        LOGT_PRIVATE_MESSAGE
    };

    //utils
    bool isnumeric(const char *s);
    char *replace_char(char *str, char find, char replace);
    void send_response(int socket, char *format, char *buffer);
    bool check_int_array_contain(int *array, int search_value);

    //command_handler
    command_t *init_cmd_struct(void);
    void handler_command(teams_t *teams,
    char *command, command_t *command_struct);

    //server
    int server(int port);
    int read_saved_data(teams_t *teams, char *filename);

    //socket
    void close_client_socket(teams_t *teams);

    //init_server
    void init_clients(teams_t *teams);
    void init_server_socket(int port, teams_t *teams);

    //connexion
    void read_connexion(teams_t *teams, fd_set readfds, command_t *command);

    //uuid
    char *generate_uuid(void);
    void destroy_uuid(char *uuid);
    bool compare_uuid(char *uuid_str1, char *uuid_str2);

    //event_notification
    void send_event_message_to_all(teams_t *teams, char *format, ...);
    void send_event_message_to_team(teams_t *teams, char *format, ...);

    //command/*
    void cmd_help(teams_t *teams, char **command, int nbr_args);
    void cmd_login(teams_t *teams, char **command, int nbr_args);
    void cmd_logout(teams_t *teams, char **command, int nbr_args);
    void cmd_users(teams_t *teams, char **command, int nbr_args);
    void cmd_user(teams_t *teams, char **command, int nbr_args);
    void cmd_send(teams_t *teams, char **command, int nbr_args);
    void cmd_send(teams_t *teams, char **command, int nbr_args);
    void cmd_messages(teams_t *teams, char **command, int nbr_args);
    void cmd_subscribe(teams_t *teams, char **command, int nbr_args);
    void cmd_subscribed_0(teams_t *teams, char **command, int nbr_args);
    void cmd_subscribed_1(teams_t *teams, char **command, int nbr_args);
    void cmd_unsubscribe(teams_t *teams, char **command, int nbr_args);
    void cmd_use_0(teams_t *teams, char **command, int nbr_args);
    void cmd_use_1(teams_t *teams, char **command, int nbr_args);
    void cmd_use_2(teams_t *teams, char **command, int nbr_args);
    void cmd_use_3(teams_t *teams, char **command, int nbr_args);
    void cmd_create_hub(teams_t *teams, char **command, int nbr_args);
    int cmd_create_channel(teams_t *teams, char **command, char *use_team_uuid);
    int cmd_create_reply(teams_t *teams, char **command, char *use_thread_uuid,
    char *use_team_uuid);
    int cmd_create_team(teams_t *teams, char **command);
    int cmd_create_thread(teams_t *teams,
    char **command, char *use_channel_uuid);
    void cmd_list(teams_t *teams, char **command, int nbr_args);
    void cmd_info(teams_t *teams, char **command, int nbr_args);

    //my_str_to_word_array
    void free_if_not_null(char *str);
    void free_str_to_word_array(char **tab);
    char **my_str_to_word_array(char const *str, char *separator);

    // my_strcat
    char *my_strcat(char *dest , char const *src);

    // -- lib linked list --
    // add_list
    node_t *push_begin(node_t *head, void *data);
    node_t *push_end(node_t *head, void *data);

    //check_exist
    bool check_if_channel_exist(node_t *channel_list, char *channel_name);
    bool check_if_team_exist(node_t *team_list, char *team_name);
    bool check_if_thread_exist(node_t *thread_list, char *thread_name);

    // general_list
    team_t *create_team_node(team_t team_node);
    channel_t *create_channel_node(channel_t channel_node);
    thread_t *create_thread_node(thread_t thread_node);
    comment_t *create_comment_node(comment_t comment);
    private_message_t *create_private_message_node(private_message_t mp);

    // getter_channel
    node_t *get_channel_per_team(node_t *channel_list, char *uuid_team);
    channel_t *get_channel_by_uuid(node_t *channel_list, char *check_uuid);

    // getter_comment
    comment_t get_comment_by_uuid(node_t *comment_list, char *check_uuid);
    node_t *get_comment_per_thread(node_t *comment_list, char *uuid_thread);
    node_t *get_comment_per_user_uuid(node_t *comment_list, char *uuid_user);

    // getter_team
    team_t *get_team_by_uuid(node_t *team_list, char *check_uuid);
    node_t *get_uuid_users_on_team_by_uuid(node_t *team_list, char *check_uuid);
    bool check_actual_team_contain_user_uuid(teams_t *teams, char *check_uuid);

    // getter_thread
    thread_t *get_thread_by_uuid(node_t *thread_list, char *check_uuid);

    // getter_user
    user_t *get_user_by_uuid(node_t *user_list, char *check_uuid);
    bool check_if_user_is_connected(t_client *clients, char *uuid);
    user_t *get_user_by_username(node_t *user_list, char *username);

    // remove_list
    node_t *pop_begin(node_t *head);
    node_t *pop_end(node_t *head);
    void remove_list(node_t *head);

    // uuid_users
    bool check_subscribe_user_on_team(node_t *uuid_users, char *user_uuid);
    node_t *remove_node_by_uuid(node_t *head, char *user_uuid);

    // -- database --
    // read_saved_data
    void split_user_data(char *str, teams_t *teams);
    void split_channel_data(char *str, teams_t *teams);
    void split_thread_data(char *str, teams_t *teams);
    void split_comment_data(char *str, teams_t *teams);

    //write_data
    void write_on_file(teams_t *teams);
    void print_channel_into_file(node_t *channel_list,int file, char *filename);
    void print_thread_into_file(node_t *thread_list,int file, char *filename);
    void print_comment_into_file(node_t *comment_list,int file, char *filename);

    //write_data_2
    void print_user_into_file(node_t *user_list, int file, char *filename);
    void print_team_into_file(node_t *team_list, int file, char *filename);
    void print_private_message_into_file(node_t *pm_list,
    int file, char *filename);

    //get_data
    void split_team_data(char *str, teams_t *teams);
    void split_private_message_data(char *str, teams_t *teams);

#endif
