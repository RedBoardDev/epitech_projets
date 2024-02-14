##
## EPITECH PROJECT, 2021
## Makefile libmy
## File description:
## Makefile libmy
##

SRC	=	my_putchar.c 	\
		my_putstr.c 	\
		my_getnbr.c	\

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

re:	all fclean
