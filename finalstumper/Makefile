##
## EPITECH PROJECT, 2021
## B-CPE-101-MLH-1-1-infinadd-martin.d-herouville
## File description:
## Makefile
##

SRC	=	finalstumper.c	\
		function.c

OBJ	=	$(SRC:.c=.o)

NAME	=	rush3

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
