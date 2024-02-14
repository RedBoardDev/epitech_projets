/*
** EPITECH PROJECT, 2021
** MY_PRINT_COMBN
** File description:
** displays all number composed by n differents digits numbers
*/

int print_putchar1(int i, int j, int k, int l)
{
    my_putchar(i);
    my_putchar(j);
    my_putchar(k);
    return  l + 1;
}

int quote_spaces2(int k, int l, int n)
{
    if (l < n) {
        my_putchar(',');
        my_putchar(' ');
        return  k + 1;
    }
    return  k;
}

void my_print_combn(int n)
{
    int	i;
    int	j;
    int	k;
    int l;

    l = 0;
    i = '0';
    while (i <= '7' && l < n) {
        j = i + 1;
        while (j <= '8' && l < n) {
            k = j + 1;
            while (k <= '9' && l < n) {
                l = print_putchar1(i, j, k, l);
                k = quote_spaces2(k, l, n);
        }
            j = j + 1;
    }
        i = i + 1;
    }
    return  (0);
}
