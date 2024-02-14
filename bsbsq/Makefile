##
## EPITECH PROJECT, 2021
## lib_workshop
## File description:
## Makefile
##

SRC	=	src/bsq.c	\

NAME	=	bsq

all:	$(NAME)

$(NAME):
	make -C lib/my re
	gcc -o $(NAME) $(SRC) -I./include -L./lib -lmy -g

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean:	clean
	rm -f $(NAME)
	make -C lib/my fclean

re:	fclean all
