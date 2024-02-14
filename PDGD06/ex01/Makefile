##
## EPITECH PROJECT, 2021
## project
## File description:
## Makefile
##

NAME	=	MyCat

SRC	=	MyCat.cpp

# compilation
OBJ	=	$(SRC:.cpp=.o)

CC	=	g++ -g

# clean file
BIN	=	vgcore*	\
		unit_tests*	\

# flags
FLAGS	=	-g	\

CFLAGS	+=	-Werror	\
			-Wextra	\
			-Wall	\

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(CFLAGS)

clean:
	rm -f $(BIN)
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:		all clean fclean re exec
