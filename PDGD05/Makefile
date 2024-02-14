##
## EPITECH PROJECT, 2021
## Makefile libmy
## File description:
## Makefile libmy
##

SRC	=	string.c	\
		string2.c	\
		string3.c	\
		string4.c	\
		init.c

NAME	=	libstring.a
MYNAME 	=	string.h

OBJ	=	$(SRC:.c=.o)

all:	    $(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	all fclean
