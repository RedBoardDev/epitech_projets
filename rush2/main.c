/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-rush2-younes.boufrioua
** File description:
** main.c
*/

int check_is_letter(char str)
{
    if ((str < 'A' || str > 'Z') && (str < 'a' || str > 'z'))
        return 0;
    return 1;
}

int my_strlen_char(char const *str)
{
    int i = 0;
    int b = 0;
    while (str[i] != '\0') {
        if (check_is_letter(str[i]))
            b += 1;
        i += 1;
    }
    return (b);
}

int pre_main(int argc, char *argv[], int tr)
{
    int i;

    for (i = 2; i < argc; ++i)
        language(argc, argv, argv[i], 1);
    check_lang(argc, argv);
}

int main(int argc, char *argv[])
{
    pre_main(argc, argv, 1);
}
