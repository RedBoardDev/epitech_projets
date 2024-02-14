##
## EPITECH PROJECT, 2021
## Makefile Projet
## File description:
## Makefile
##

SRC	=	src/antman.c	\

# SRC_UNITS	=	tests/test.c	\

NAME	=	antman

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

FLAGS = -Wall -Wextra -Werror

CFFLAGS	=	--coverage -lcriterion

LIB	=	-I./include -L../lib -lmy

LIB_PATH	=	../lib/my

# .c.o:
# 	gcc $(FLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ../lib/my
	$(CC) -o $(NAME) $(OBJ) $(LIB) $(FLAGS)

clean:
	rm -f $(OBJ)
	make -C ../lib/my clean

fclean:	clean
	rm -f $(NAME)
	make -C ../lib/my fclean

re:	fclean all

gcovr:
		gcovr --exclude tests
		gcovr --exclude tests --branches

tests_run:	fclean
		make -C ../lib/my
		gcc -o unit_tests $(SRC_UNITS) $(SRC_TEST) $(LIB) $(CFFLAGS)
		./unit_tests
