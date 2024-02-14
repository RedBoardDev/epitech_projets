/*
** EPITECH PROJECT, 2021
** B-CPE-110-MLH-1-1-bsbsq-thomas.ott
** File description:
** bsq.h
*/

#ifndef BSQ_H_
    #define BSQ_H_

void fs_cat_500_bytes(char const *filepath);

typedef struct coords_s {
    unsigned int x;
    unsigned int y;
    unsigned int bigger;
} coords_t;

typedef struct map_s {
    coords_t coords;
    unsigned int lenL;
    unsigned int size;
    unsigned int len_nb;
    char *data;
} map_t;

int bsq(char *filepath);
int len_ligne(char *data);
void draw_square(map_t *map);
void error_number_column(char *buffer);
void find_square(int x, int y, map_t *map);
int get_map(map_t *map, char *str, int size);
void put_x(map_t *map, int lenL, int i, int j);
int check_char(map_t *map, int i, int j, char c);
int check_square(map_t *map, int x, int y, int len_square);
int error_same_line_size(char *data, int size, unsigned int len_nb);

#endif /* BSQ_H_ */
