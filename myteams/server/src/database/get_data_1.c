/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** get_data_1.c
*/

#include "../../include/struct.h"
#include "../../include/teams.h"

void split_user_data(char *str, teams_t *teams)
{
    char *tok = strtok(str, "~");
    user_t *user = malloc(sizeof(user_t));

    for (int i = 0; tok != NULL; ++i) {
        if (i == 0)
            user->username = strdup(tok);
        if (i == 1) {
            tok[strlen(tok) - 1] = '\0';
            user->uuid = strdup(tok);
        }
        tok = strtok(NULL, "~");
    }
    server_event_user_loaded(user->uuid, user->username);
    teams->user = push_begin(teams->user, user);
}

void split_channel_data(char *str, teams_t *teams)
{
    char *tok = strtok(str, "~");
    channel_t *channel = malloc(sizeof(channel_t));

    for (int i = 0; tok != NULL; ++i) {
        if (i == 0)
            channel->name = strdup(tok);
        if (i == 1)
            channel->description = strdup(tok);
        if (i == 2)
            channel->uuid = strdup(tok);
        if (i == 3) {
            tok[strlen(tok) - 1] = '\0';
            channel->uuid_team = strdup(tok);
        }
        tok = strtok(NULL, "~");
    }
    teams->channel = push_begin(teams->channel, channel);
}

void split_thread_data(char *str, teams_t *teams)
{
    char *tok = strtok(str, "~");
    thread_t *thread = malloc(sizeof(thread_t));
    for (int i = 0; tok != NULL; ++i) {
        if (i == 0)
            thread->name = strdup(tok);
        if (i == 1)
            thread->body = strdup(tok);
        if (i == 2)
            thread->uuid = strdup(tok);
        if (i == 3)
            thread->uuid_author = strdup(tok);
        if (i == 4)
            thread->uuid_channel = strdup(tok);
        if (i == 5) {
            tok[strlen(tok) - 1] = '\0';
            thread->timestamp = atoi(tok);
        }
        tok = strtok(NULL, "~");
    }
    teams->thread = push_begin(teams->thread, thread);
}

void split_comment_data(char *str, teams_t *teams)
{
    char *tok = strtok(str, "~");
    comment_t *comment = malloc(sizeof(comment_t));

    for (int i = 0; tok != NULL; ++i) {
        if (i == 0)
            comment->uuid = strdup(tok);
        if (i == 1)
            comment->uuid_user = strdup(tok);
        if (i == 2)
            comment->uuid_thread = strdup(tok);
        if (i == 3)
            comment->message = strdup(tok);
        if (i == 4) {
            tok[strlen(tok) - 1] = '\0';
            comment->timestamp = atoi(tok);
        }
        tok = strtok(NULL, "~");
    }
    teams->comment = push_begin(teams->comment, comment);
}
