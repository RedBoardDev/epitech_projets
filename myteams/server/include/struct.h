/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-thomas.ott
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include <netinet/in.h>
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <fcntl.h>
    #define MAX_USERRR 4096

    // LINKED LIST - DATA

    typedef struct localisation_s {
        bool isUser;
        bool isTeam;
        bool isChannel;
        bool isThread;
        bool isComment;
    }localisation_t;

    typedef struct private_message_s {
        char *uuid;
        char *uuid_sender;
        char *uuid_receiver;
        char *message;
        time_t message_timestamp;
    } private_message_t;

    typedef struct comment_s {
        char *uuid;
        char *uuid_user;
        char *uuid_thread;
        char *message;
        time_t timestamp;
    } comment_t;

    typedef struct thread_s {
        char *uuid;
        char *uuid_author;
        char *uuid_channel;
        char *name;
        char *body;
        time_t timestamp;
    } thread_t;

    typedef struct channel_s {
        char *uuid;
        char *uuid_team;
        char *name;
        char *description;
    } channel_t;

    typedef struct uuid_users_s {
        char *uuid;
    } uuid_users_t;

    typedef struct node_s {
        void *data;
        struct node_s *next;
    } node_t;

    typedef struct team_s {
        char *uuid;
        node_t *uuid_users;
        char *name;
        char *description;
    } team_t;

    typedef struct user_s {
        char *uuid;
        char *username;
    } user_t;

    typedef struct use_client_s {
        char *use_team_uuid;
        char *use_channel_uuid;
        char *use_thread_uuid;
    } use_client_t;

    typedef struct s_client {
        user_t *user;
        int socket;
        struct sockaddr_in address;
        use_client_t uses;
    } t_client;

    typedef struct s_server {
        int port;
        int socket;
        struct sockaddr_in address;
    } t_server;

    typedef struct teams_s {
        node_t *user;
        node_t *team;
        node_t *channel;
        node_t *thread;
        node_t *comment;
        node_t *private_message;
        int addrlen;
        int iterator;
        t_client clients[MAX_USERRR];
        t_server server;
    } teams_t;

    typedef struct command_s {
        char *name;
        int need_login;
        int nbr_args;
        void (*function)(teams_t *teams, char **command, int nbr_args);
    } command_t;

#endif
