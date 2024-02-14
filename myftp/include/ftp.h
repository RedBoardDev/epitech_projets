/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myftp-thomas.ott
** File description:
** ftp.h
*/

#ifndef FTP_H
    #define FTP_H

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

    #define NBR_CMD 18

    //utils
    bool isnumeric(const char *s);
    void free_memory(t_ftp *ftp, t_command *command);
    char *replace_char(char *str, char find, char replace);
    void send_response(int socket, char *format, char *buffer);

    //init_args
    int init_ftp_struct(int argc, char **argv, t_ftp *ftp);

    //command_handler
    void check_command(t_ftp *ftp,
    char *command, int i, t_command *command_struct);

    //server
    int server(int argc, char **argv, bool mode);

    //socket
    int check_mode(t_ftp *ftp, int i);
    void close_data_socket(t_ftp *ftp, int i);
    void close_client_socket(t_ftp *ftp, int i);

    //init_server
    void init_clients(t_ftp *ftp);
    t_command *init_cmd_struct(void);
    void init_server_socket(t_ftp *ftp);

    //connexion
    int check_if_logged(t_client client);
    void read_connexion(t_ftp *ftp, fd_set readfds, t_command *command);

    //command/*
    void cmd_user(t_ftp *ftp, char *command, int i);
    void cmd_pwd(t_ftp *ftp, char *command, int i);
    void cmd_type(t_ftp *ftp, char *command, int i);
    void cmd_pasv(t_ftp *ftp, char *command, int i);
    void cmd_list(t_ftp *ftp, char *command, int i);
    void cmd_syst(t_ftp *ftp, char *command, int i);
    void cmd_quit(t_ftp *ftp, char *command, int i);
    void cmd_pass(t_ftp *ftp, char *command, int i);
    void cmd_feat(t_ftp *ftp, char *command, int i);
    void cmd_cdup(t_ftp *ftp, char *command, int i);
    void cmd_cwd(t_ftp *ftp, char *command, int i);
    void cmd_noop(t_ftp *ftp, char *command, int i);
    void cmd_dele(t_ftp *ftp, char *command, int i);
    void cmd_help(t_ftp *ftp, char *command, int i);
    void cmd_retr(t_ftp *ftp, char *command, int i);
    void cmd_stor(t_ftp *ftp, char *command, int i);
    void cmd_port(t_ftp *ftp, char *command, int i);
    void cmd_stop(t_ftp *ftp, char *command, int i);

    //my_str_to_word_array
    void free_str_to_word_array(char **tab);
    char **my_str_to_word_array(char const *str, char *separator);

    // my_strcat
    char *my_strcat(char *dest , char const *src);

#endif
