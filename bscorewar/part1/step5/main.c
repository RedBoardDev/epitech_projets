/*
** EPITECH PROJECT, 2021
** bscorewar
** File description:
** main.c
*/

#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int nbr;
    char c;
    char str[40];
} maind_t;


void write_step1(void)
{
    char *str = "Hello bambino\n";
    int fd = open("some-text.yolo", O_CREAT | O_WRONLY, 0664);

    write(fd, str, strlen(str));
    close(fd);
}

void write_step2(void)
{
    char *str = "12345678";
    int fd = open("number-as-text.yolo", O_CREAT | O_WRONLY, 0664);

    write(fd, str, strlen(str));
    close(fd);
}

void write_step3(void)
{
    int nbr = 12345678;
    int fd = open("number-as-int.yolo", O_CREAT | O_WRONLY, 0664);

    write(fd, &nbr, 4);
    close(fd);
}

void write_step4(void)
{
    maind_t dfgh = {192837, 'k', "Corewar is swag!!"};
    int fd = open("several-variables.yolo", O_CREAT | O_WRONLY, 0664);

    write(fd, &dfgh, sizeof(dfgh));
    close(fd);
}

void write_step5(void)
{
    char *nbr = "192837";
    char c = 'k';
    char str[40] = "Corewar is swag!!";
    int fd = open("one-structure.yolo", O_CREAT | O_WRONLY, 0664);

    write(fd, &nbr, sizeof(nbr));
    write(fd, &c, sizeof(c));
    write(fd, &str, sizeof(str));
    close(fd);
}

int main(int argc, char **argv)
{
    write_step5();
}
