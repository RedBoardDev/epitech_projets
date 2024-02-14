/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** main_asm.c
*/

#include "../include/asm.h"

static void my_memset(void *header, int c, int size)
{
    char *ptr = header;

    for (int i = 0; i < size; ++i) {
        *ptr = c;
        ++ptr;
    }
}

int main(int argc, char **argv)
{
    int ret_value = 0;
    header_t header;
    instr_node_t *instr_node = NULL;
    label_node_t *label_node = NULL;
    my_memset(&header, 0, sizeof(header_t));

    if (argc != 2)
        return (84);
    if (open(argv[1], O_RDONLY) == -1)
        return (84);
    ret_value = get_file(argv[1], &header, &instr_node, &label_node);
    return (ret_value);
}
