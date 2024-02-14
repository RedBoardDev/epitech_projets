##
## EPITECH PROJECT, 2021
## Makefile libmy
## File description:
## Makefile libmy
##

SRC	=	my_getnbr.c 	\
		my_intlen.c	\
		my_putchar.c	\
		my_strlen.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	    $(NAME)

$(NAME):	$(OBJ)
		cp my.h ../../include/
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ..

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re:	all fclean
