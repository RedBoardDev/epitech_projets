/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** asm.h
*/

#ifndef ASM_H
    #define ASM_H

    #include <unistd.h>
    #include <stdio.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "op.h"
    #include <stddef.h>

#define MAX_ARGS_NUMBER 4

#define ARGS_REG(x) (x |= 0b01)
#define ARGS_DIR(x) (x |= 0b10)
#define ARGS_IND(x) (x |= 0b11)

#define IS_REG(x) (x & T_REG)
#define IS_DIR(x) (x & T_DIR)
#define IS_IND(x) (x & T_IND)

#define SWAP_UINT32(x) ((x >> 24) & 0xff) | (( x << 8) & 0xff0000) |    \
                        ((x >> 8) & 0xff00) | ((x << 24) & 0xff000000)
#define SWIP_UINT32(x) (x >> 16)

enum type_instr {
    TYPE_LABEL = -2345678,
    TYPE_NONE = 0,
    TYPE_REG = 01,
    TYPE_DIR = 10,
    TYPE_IND = 11
};

typedef struct {
    enum type_instr type;
    int value;
    char *label;
} arg_cmd_t;

typedef struct instr_node_s {
    char **label_args;
    unsigned char instruction;
    int size_bits;
    arg_cmd_t arg_cmd[MAX_ARGS_NUMBER];
    int len;
    struct instr_node_s *next;
    char *command;
} instr_node_t;

typedef struct label_node_s {
    int index;
    char *name;
    struct label_node_s *next;
} label_node_t;

typedef struct {
    int to_write[6];
    int stock_nb[6];
    int len;
} instr_bit_t;

int my_strlen(char const *str);
int get_file(char *filepath, header_t *header, instr_node_t **instr_node,
label_node_t **label_node);
char *my_strdup(char const *src);
int funct_pointeurs(char *str);
int my_getnbr(const char *str);
int my_strcmp(char const *str, char *comp);
char **my_str_to_word_array(char const *str);
int error_handling_begin_name(header_t *header, char *str, int i_line);
int error_handling_begin_comment(header_t *header, char *str, int i_line);
int convert_to_bit(instr_node_t *instr_node, label_node_t *label_node,
header_t *head, char *file_name);
int size_linked_list(instr_node_t *list);
int write_to_file(instr_bit_t *instr_bit, header_t *head, int nbr_line,
char *file_name);
int get_nbr_without_character(const char * str);
char **my_str_to_word_arrays(char const *str, char separator);

int write_to_2bits(int fd, unsigned int c);
int write_to_1bits(int fd, unsigned char c);
int write_to_4bits(int fd, unsigned int c);
int get_value_bit(enum type_instr type, unsigned char instruction);
unsigned char get_coding_bit(instr_node_t *instr_node);
int set_label_value(instr_bit_t *instr_bit, label_node_t *label_node,
instr_node_t *instr_node);
int get_label_value(instr_bit_t *instr_bit, label_node_t *label_node_tmp,
int nbr_line);

instr_node_t *factory_label(int data, char **label, instr_node_t *new_list);
instr_node_t *factory_commands(instr_node_t *instr_node, char **res, int index);
enum type_instr check_args_type(char **args, int i, instr_node_t *node);

void display_head(header_t *head, int fd, instr_bit_t *instr_bit, int nbr_line);

#endif