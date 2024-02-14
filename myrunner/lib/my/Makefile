##
## EPITECH PROJECT, 2021
## Makefile libmy
## File description:
## Makefile libmy
##

SRC	=	my_strcat.c 	\
		my_strlen.c 	\
		my_is.c	\
		my_itoa.c	\
		my_putstr.c	\
		my_putchar.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	    $(NAME)

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
