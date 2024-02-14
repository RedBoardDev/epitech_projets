/*
** EPITECH PROJECT, 2021
** corewar-
** File description:
** write_to_file.c
*/

#include "../include/asm.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int b = 0;
    int k = 0;
    char *s = malloc(sizeof(char) * (my_strlen(src) + my_strlen(dest) + 1));
    while (dest[k] != '\0') {
        s[k] = dest[k];
        ++k;
    }
    while (dest[i] != '\0')
        ++i;
    while (src[b] != '\0' && src[b] != ' ') {
        s[i] = src[b];
        ++i;
        ++b;
    }
    s[i] = '\0';
    return s;
}

char *cut_file_name(char *file_name)
{
    int len_str = my_strlen(file_name) - 1;
    if (file_name[len_str] != 's')
        return file_name;
    char *n_name = malloc(sizeof(char) * len_str);

    for (int i = 0; i < len_str - 1; ++i)
        n_name[i] = file_name[i];
    n_name[len_str - 1] = '\0';
    return (n_name);
}

int write_to_file(instr_bit_t *instr_bit, header_t *head, int nbr_line,
char *file_name)
{
    int i = 0;
    int fd = 0;
    char *file = NULL;
    char **res = NULL;

    res = my_str_to_word_arrays(file_name, '/');
    while (res[++i]);
    file = cut_file_name(res[i - 1]);
    file = my_strcat(file, ".cor");
    fd = open(file, O_WRONLY | O_CREAT, 0664);
    display_head(head, fd, instr_bit, nbr_line);
    for (int i = 0; i < nbr_line; ++i) {
        for (int r = 0; r < instr_bit[i].len; ++r) {
            if (instr_bit[i].stock_nb[r] != 1)
                instr_bit[i].to_write[r] =
                SWAP_UINT32(instr_bit[i].to_write[r]);
            if (instr_bit[i].stock_nb[r] == 2)
                instr_bit[i].to_write[r] =
                SWIP_UINT32(instr_bit[i].to_write[r]);
            write(fd, &instr_bit[i].to_write[r], instr_bit[i].stock_nb[r]);
        }
    }
    close(fd);
    return (0);
}
