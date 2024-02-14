/*
** EPITECH PROJECT, 2021
** MY_GETNBR
** File description:
** returns a number
*/

int my_getnbr(const char *str)
{
    int i;
    int x;
    int sign;

    i = 0;
    x = 0;
    sign = 1;
    while (str[i] == '+' || str[i] == '-') {
        str[i] == '-' ? sign *= -1 : x == x;
        i++;
    }
    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9') {
            x *= 10;
            x += str[i] - '0';
        } else
            return ((x * sign < -32767) || (x * sign > 32767)) ? 0 : x * sign;
        i++;
    }
    return ((x * sign < -32767) || (x * sign > 32767)) ? 0 : x * sign;
}
