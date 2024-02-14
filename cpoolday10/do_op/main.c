/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday10-thomas.ott
** File description:
** main.c
*/

int switch_be_like(int a, int b, char op)
{
    int result = 0;
    switch(op)
   {
   case '+' : printf("+"); result = a + b ;break;
   case '-' : printf("-"); result = a - b ;break;
   case '*' : printf("*"); result = a * b ;break;
   case '%' : printf('%'); result = a % b ;break;
   case '/' : printf("/"); result = a / b ;break;
   default : printf("bitcoin mek\n");
   }
   my_put_nbr(result);
}

int main(int argc, char **argv)
{
    int i = 1; // start 1 because 0 == ./a.out
    int nb_one = 0;
    int nb_two = 0;
    char op;
    char *

    nb_one = my_getnbr(argv[1]);
    nb_two = my_getnbr(argv[3]);
    op = argv[2][0]; // gestion error here
    switch_be_like(nb_one, nb_two, op);
}