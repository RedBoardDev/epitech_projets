/*
** EPITECH PROJECT, 2021
** MY_PRINT_DIGITS
** File description:
** Write all digits
*/

int my_print_digits(void)
{
    int number_ascii;
    number_ascii = 48;
    while   (number_ascii < 58) {
        my_putchar(number_ascii);
        number_ascii++;
    }
    return  (0);
}
