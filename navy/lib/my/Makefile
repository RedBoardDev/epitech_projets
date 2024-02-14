##
## EPITECH PROJECT, 2021
## B-CPE-100-MLH-1-1-cpoolday10-martin.d-herouville
## File description:
## Makefile lib
##

SRC	=	my_putchar.c	\
		my_put_nbr.c	\
		my_atoi.c	\
		my_putstr.c	\
		is.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		cp my.h ../../include/
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ..

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	all fclean
