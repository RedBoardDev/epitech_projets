##
## EPITECH PROJECT, 2021
## lib_workshop
## File description:
## Makefile
##

SRC	=	main.c	\

NAME	=	101pong

BIN	=	vgcore*	\
		a.out	\

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -g -lm

clean:
	rm -f $(BIN)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
