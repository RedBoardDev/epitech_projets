/*
** EPITECH PROJECT, 2021
** MY_STRSTR
** File description:
** MY_STRSTR
*/

char *my_strstr(char *str, char const *to_find)
{
    if (str[0] != '\0') {
        for (int i = 0; to_find[i] != '\0'; ++i) {
            if (to_find[i] != str[i])
                return (my_strstr(str + 1, to_find));
	}
        return (str);
    }
    else
        return(0);
}