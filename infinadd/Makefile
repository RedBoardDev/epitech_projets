##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	infin_add.c \
		utils.c	\
		main.c	\
		infin_sub.c

NAME	=	infin_add

OBJ	=	$(SRC:.c=.o)

$(NAME):	$(OBJ)
		make -C lib/my re
		gcc -o $(NAME) $(OBJ) -lmy -L lib/
		rm *.o

all:	$(NAME)

clean:
	make -C lib/my clean

fclean:	clean
	rm -f $(NAME)

re:	fclean all
