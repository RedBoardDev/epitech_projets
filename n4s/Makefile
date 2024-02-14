##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile project
##

SRC		=	main.c	\
			dir_f.c	\
			save_info_print.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	ai

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ)
	cp -f $(NAME) ../n4s_package

debug:
	gcc -o $(NAME) $(SRC) -g

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../n4s_package/$(NAME)

re:	fclean all
