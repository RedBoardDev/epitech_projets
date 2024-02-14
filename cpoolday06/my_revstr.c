/*
** EPITECH PROJECT, 2021
** MY_REVSTR
** File description:
** MY_REVSTR
*/

int my_strlen(char const *str)
{
    int len;
    len = 0;
    while   (*str++) {
        ++len;
    }
    return  len;
}

char		*my_revstr(char *str)
{
    char  temp;
    int   index;
    int   lenght;

    index = 0;
    lenght = my_strlen(str) - 1;
    while (index <= lenght / 2) {
        temp = str[index];
        str[index] = str[lenght - index];
        str[lenght - index] = temp;
        index += 1;
    }
    return (str);
}
