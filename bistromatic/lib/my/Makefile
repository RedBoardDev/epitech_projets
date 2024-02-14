##
## EPITECH PROJECT, 2021
## B-CPE-100-MLH-1-1-cpoolday10-martin.d-herouville
## File description:
## Makefile lib
##

SRC	=	my_putchar.c	\
		my_put_nbr.c	\
		my_swap.c	\
		my_putstr.c	\
		my_strlen.c	\
		my_atoi.c	\
		my_putchar_error.c	\
		my_putstr_error.c	\
		my_revstr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	cp *.h ../../include/
	ar rc libmy.a *.o
	cp *.a ..

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	all fclean
