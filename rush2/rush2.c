/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-rush2-younes.boufrioua
** File description:
** rush2.c
*/

const float english[] = {8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015,
6.094, 6.966, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987,
6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074};
const float french[] = {7.636, 0.901, 3.260, 3.669, 14.715, 1.066, 0.866,
0.737, 7.529, 0.613, 0.074, 5.456, 2.968, 7.095, 5.796, 2.521, 1.362, 6.693,
9.948, 7.224, 6.311, 1.838, 0.049, 0.427, 0.128, 0.326};
const float german[] = {6.516, 1.886, 2.732, 5.076, 16.396, 1.656, 3.009,
4.577, 6.550, 0.268, 1.417, 3.437, 2.534, 9.776, 2.594, 0.670, 0.018, 7.003,
7.270, 6.154, 4.166, 0.846, 1.921, 0.034, 0.039, 1.134};
const float spanish[] = {11.525, 2.15, 4.019, 5.010, 12.181, 0.692, 1.768,
0.703, 6.247, 0.493, 0.011, 4.967, 3.157, 6.712, 8.683, 2.510, 0.877, 6.871,
7.977, 4.632, 2.927, 1.138, 0.017, 0.215, 1.008, 0.467};

int my_put_float(float nb)
{
    float nbr = (int) nb;
    int entier = nbr;
    float deci = (nb - entier) * 100;

    deci = deci + 0.0001;
    my_put_nbr(entier);
    my_putchar('.');
    if ((int) deci < 10)
        my_put_nbr(0);
    my_put_nbr((int) deci);
    return 0;
}

float cal_stat(char *str, int nbr)
{
    float stat;

    if (nbr == 0)
        return 0;
    stat = ((float) 100 / my_strlen_char(str)) * nbr;
    return stat;
}

float language(int argc, char *argv[], char *argv1, int tr)
{
    int result = 0;

    for (int cr = 0; cr < my_strlen(argv[1]); ++cr) {
        if (argv[1][cr] == argv1[0] || (argv[1][cr] == argv1[0] - 32 &&
        check_is_letter(argv1[0] - 32)) || (argv[1][cr] == argv1[0] + 32 ))
            result += 1;
    }
    if (tr) {
        my_putchar(argv1[0]);
        my_putchar(':');
        my_put_nbr(result);
        my_putchar(' ');
        my_putchar('(');
        my_put_float(cal_stat(argv[1], result));
        my_putchar('%');
        my_putchar(')');
        my_putchar('\n');
    }
    return cal_stat(argv[1], result);
}

int check_lang(int argc, char *argv[])
{
    int t[4] = {0, 0, 0, 0};
    float g[4] = {0, 0, 0, 0};
    char *char_select[1];

    for (int i = 0; i < 26; ++i) {
        char_select[0] = i + 97;
        if (language(argc, argv, char_select, 0) >= english[i])
            g[0] += language(argc, argv, char_select, 0) - english[i];
        if (language(argc, argv, char_select, 0) > french[i])
            g[1] += language(argc, argv, char_select, 0) - french[i];
        if (language(argc, argv, char_select, 0) >= spanish[i])
            g[3] += language(argc, argv, char_select, 0) - spanish[i];
        if (language(argc, argv, char_select, 0) >= german[i])
            g[2] += language(argc, argv, char_select, 0) - german[i];
        (g[0] < g[1] && g[0] < g[2]) ? (g[0] < g[3] ? t[0] += 1 : t[0]) : t[0];
        (g[1] < g[0] && g[1] < g[2]) ? (g[1] < g[3] ? t[1] += 1 : t[1]) : t[1];
        (g[2] < g[1] && g[2] < g[0]) ? (g[2] < g[3] ? t[2] += 1 : t[2]) : t[2];
        (g[3] < g[1] && g[3] < g[0]) ? (g[3] < g[2] ? t[3] += 1 : t[3]) : t[3];
    }
    print_langague(t[0], t[1], t[2], t[3]);
}

void print_langague(int e, int f, int g, int s)
{
    if (e > f && e > g) {
    if (e > s)
        my_putstr("=> English");
    }
    if (f > e && f > g) {
        if (f > s)
            my_putstr("=> French");
    }
    if (g > f && g > e) {
        if (g > s)
            my_putstr("=> German");
    }
    if (s > f && s > e) {
        if (s > g)
            my_putstr("=> Spanish");
    }
}
