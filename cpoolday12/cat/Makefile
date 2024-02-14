##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	cat.c \

NAME	=	cat

OBJ	=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re :	fclean all 
