##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

NAME	=	ai

# src file

SRC_DIR	=	src/

SRC_FILES	=	main.c	\

SRC	=	$(addprefix $(SRC_DIR), $(SRC_FILES))

#test units file
SRC_FILES_NO_MAIN	=	$(filter-out main.c, $(SRC_FILES))

SRC_WITHOUT_MAIN	=	$(addprefix $(SRC_DIR), $(SRC_FILES_NO_MAIN))

TESTS_DIR	=	tests/

TESTS_SRC	=	tests.c	\

TESTS_FILE	=	$(addprefix $(TESTS_DIR), $(TESTS_SRC))

# obj compilation and flags
OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

LIB	=	-I./include \
		-L./lib \
		-lmy \

FLAGS = -Wall \
		-Wextra \
		-Werror \

BIN	=	vgcore*	\
		unit_tests-* \

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(BIN)
	rm -f $(OBJ)
	make -C lib/my clean

fclean:	clean
	rm -f $(NAME)
	make -C lib/my fclean

re:	fclean all
	make clean

gcovr:
		gcovr --exclude tests
		gcovr --exclude tests --branches

tests_run:	fclean
			make -C lib/my
			gcc -o unit_tests $(SRC_WITHOUT_MAIN) $(TESTS_FILE) $(LIB) \
			./unit_tests