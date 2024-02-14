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
    int x;
    int y;
    int bigger;
} coords_t;

typedef struct map_s {
    coords_t coords;
    int lenL;
    int size;
    char *data;
} map_t;

#endif /* BSQ_H_ */
