##
## EPITECH PROJECT, 2021
## lib_workshop
## File description:
## Makefile
##

NAME	=	my_sokobo

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

FLAGS = -Wall \
		-Wextra \
		-Werror \
		-lncurses \

CFFLAGS	=	--coverage \
			-lcriterion \

CSFML_FLAGS	=	-lcsfml-graphics	\
				-lcsfml-window	\
				-lcsfml-system	\
				-lcsfml-audio	\

BIN	=	vgcore*	\
		unit_tests-* \

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS)

clean:
	rm -f $(BIN)
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
	make clean

gcovr:
		gcovr --exclude tests
		gcovr --exclude tests --branches

tests_run:	fclean
			echo 'plane'