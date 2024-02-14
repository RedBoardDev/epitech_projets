/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include <netinet/in.h>

    enum e_mode {
        mode_passive,
        mode_active,
        mode_disable
    };

    typedef struct s_client {
        bool logged;
        char *username;
        int cmd_socket;
        int data_socket;
        int data_mode; // e_mode
        struct sockaddr_in address;
    } t_client;

    typedef struct s_server {
        int stop;
        int port;
        int socket;
        struct sockaddr_in address;
    } t_server;

    typedef struct s_ftp {
        int sd;
        int login;
        int addrlen;
        bool test_mode;
        int max_clients;
        t_server server;
        t_client clients[1024];
    } t_ftp;

    typedef struct s_command {
        char *name;
        int need_login;
        void (*function)(t_ftp *ftp, char *command, int i);
    } t_command;

#endif
