/*
** EPITECH PROJECT, 2021
** corewar-
** File description:
** get_file.c
*/

#include "../include/asm.h"

static int count_args(char **tab_args, int label_i)
{
    int i = 0;

    while (tab_args[i])
        ++i;
    return (i - 1 - label_i);
}

label_node_t *add_node_label(label_node_t *label_node, char *label,
int index, char **res)
{
    label_node_t *tmp = label_node;
    label_node_t *node = malloc(sizeof(label_node_t));
    int l = 0;
    int index_tmp = index;
    node->index = index;
    node->name = malloc(sizeof(char) * my_strlen(label));
    for (int i = 0; label[i + 1]; ++i)
        node->name[i] = label[i];
    while (res[l])
        ++l;
    node->index = index_tmp;
    node->name[my_strlen(label) - 1] = '\0';
    node->next = NULL;
    if (tmp == NULL)
        return (node);
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = node;
    return (label_node);

}

static int parse_args(char **res, instr_node_t **instr_node,
label_node_t **label_node, int *index_instr)
{
    int label_i = 0;
    int y = my_strlen(res[0]);
    if (y - 1 >= 0) {
        if (res[0][y - 1] == ':' && res[1] != NULL) {
            *label_node =
            add_node_label(*label_node, res[0], *index_instr, res);
            label_i = 1;
        }
        if (res[0][y - 1] == ':' && res[1] == NULL) {
            *label_node =
            add_node_label(*label_node, res[0], *index_instr, res);
            label_i = 0;
        }
    }
    for (int i = 0; op_tab[i].nbr_cycles != 0; ++i) {
        if (my_strcmp(op_tab[i].mnemonique, res[label_i]) == 0) {
            if (count_args(res, label_i) == op_tab[i].nbr_args) {
                ++*index_instr;
                *instr_node =
                factory_commands(*instr_node, res, label_i);
                return (1);
            } else
                return (0);
        }
    }
    exit(84);
}

char *remove_comment(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == '#') {
            str[i] = '\0';
            return (str);
        }
    return (str);
}

int get_file(char *filepath, header_t *header, instr_node_t **instr_node,
label_node_t **label_node)
{
    FILE *fd;
    int i = 0;
    int name_comment_i = 0;
    int count_instr = 0;
    int index_instr = 0;
    size_t size;
    char *buf = NULL;
    char **res = NULL;

    res = malloc(sizeof(char *) * (1000));
    fd = fopen(filepath, "r");
    while (getline(&buf, &size, fd) != -1) {
        if (buf[0] == '#')
            continue;
        buf = remove_comment(buf);
        res = my_str_to_word_array(buf);
        if (my_strcmp(res[0], ".name") == 0)
            name_comment_i += error_handling_begin_name(header, buf, i);
        else if (my_strcmp(res[0], ".comment") == 0)
            name_comment_i += error_handling_begin_comment(header, buf, i);
        else
            count_instr = parse_args(res, instr_node, label_node, &index_instr);
        ++i;
    }
    if (count_instr < 1 || name_comment_i != 2)
        return (84);
    free(res);
    fclose(fd);
    convert_to_bit(*instr_node, *label_node, header, filepath);
    return (0);
}
