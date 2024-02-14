/*
** EPITECH PROJECT, 2021
** MY_PRINT_COMB2
** File description:
** display two two- digit numbers
*/

void my_print_char(int x)
{
    char number1;
    char number2;
    number1 = x/10;
    number2 = x%10;
    my_putchar(number1 + '0');
    my_putchar(number2 + '0');
}

int while_three(int a, int b)
{
    if (b > a) {
        my_print_char(a);
        my_putchar(' ');
        my_print_char(b);
        if (!(a == 98 && b == 99)) {
            my_putchar(',');
            my_putchar(' ');
        }
    }
}

int my_print_comb2(void)
{
    int a;
    int b;
    b = 1;
    while   (a <= 99) {
        b = a + 1;
        while   (b <= 99) {
            while_three(a, b);
            ++b;
        }
        a = a + 1;
        b = 0;
    }
    return  (0);
}
