/*
** EPITECH PROJECT, 2022
** need4Stek
** File description:
** main
*/

#include "struct.h"

char *command_f(char *command, ...)
{
    va_list va;
    char buf[2048];
    char *str = NULL;
    size_t len = 0;

    va_start(va, command);
    vsprintf(buf, command, va);
    my_putstr(buf);
    va_end(va);
    getline(&str, &len, stdin);
    return (str);
}

void init_struct(struct_t *data)
{
    data->cur_pos_3 = 0;
    data->cur_pos_16 = 0;
    data->cur_pos_28 = 0;
    data->dir = 0.0;
    data->speed = 0.2;
}

int needfourstek(void)
{
    struct_t data;

    init_struct(&data);
    data.info = command_f("CAR_FORWARD:%f\n", data.speed);
    while (NULL == strstr(data.info, "Track Cleared")) {
        data.speed = 0.2;
        data.info = command_f("GET_INFO_LIDAR\n");
        data.cur_pos_3 = save_int(data.info, find_lidar(data.info, 3));
        data.cur_pos_16 = save_int(data.info, find_lidar(data.info, 16));
        data.cur_pos_28 = save_int(data.info, find_lidar(data.info, 28));
        change_dir(&data);
        data.info = command_f("CAR_FORWARD:%f\n", data.speed);
        data.info = command_f("WHEELS_DIR:%f\n", data.dir);
    }
    usleep(100000);
    return 0;
}

int main(int argc, char const *argv[])
{
    char *str = NULL;
    size_t len = 0;
    char *info;

    command_f("START_SIMULATION\n");
    needfourstek();
    str = NULL;
    len = 0;
    command_f("STOP_SIMULATION\n");
    return 0;
}
