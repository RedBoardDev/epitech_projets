/*
** EPITECH PROJECT, 2022
** B-NWP-400-MLH-4-1-myteams-luca.haumesser
** File description:
** getter_comment.c
*/

#include "../../include/teams.h"

comment_t get_comment_by_uuid(node_t *comment_list, char *check_uuid)
{
    comment_t *current;

    while (comment_list != NULL) {
        current = comment_list->data;
        if (strcmp(current->uuid, check_uuid) == 0) {
            return *current;
        }
    }
    return *current;

}

node_t *get_comment_per_thread(node_t *comment_list, char *uuid_thread)
{
    comment_t *current;
    node_t *connected_comment_list = NULL;

    while (comment_list != NULL) {
        current = comment_list->data;
        if (strcmp(current->uuid_thread, uuid_thread) == 0) {
            comment_t *comment = malloc(sizeof(comment_t));
            comment->uuid = current->uuid;
            comment->message = current->message;
            comment->uuid_thread = uuid_thread;
            comment->uuid_user = current->uuid_user;
            connected_comment_list =
            push_begin(connected_comment_list, comment);
        }
        comment_list = comment_list->next;
    }
    return connected_comment_list;
}

node_t *get_comment_per_user_uuid(node_t *comment_list, char *uuid_user)
{
    comment_t *current;
    node_t *connected_comment_list = NULL;

    while (comment_list != NULL) {
        current = comment_list->data;
        if (strcmp(current->uuid_user, uuid_user) == 0) {
            comment_t *comment = malloc(sizeof(comment_t));
            comment->uuid = current->uuid;
            comment->message = current->message;
            comment->uuid_thread = uuid_user;
            comment->uuid_user = current->uuid_user;
            connected_comment_list =
            push_begin(connected_comment_list, comment);
        }
        comment_list = comment_list->next;
    }
    return connected_comment_list;
}
