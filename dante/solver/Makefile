##
## EPITECH PROJECT, 2021
## project
## File description:
## Makefile
##

NAME	=	solver
# src
SRC_DIR	=	src/
EXTENSION	=	.c

SRC_FILES	=	main_solver	\
				choose_case	\
				manage_maps	\
				move_finder	\
				my_free_array	\
				my_str_to_word_array	\
				my_strdup	\
				maps	\
				solver	\

SRC	=	$(addprefix $(SRC_DIR), $(addsuffix $(EXTENSION), $(SRC_FILES)))

# no main
SRC_FILES_NO_MAIN	=	$(filter-out main_solver, $(SRC_FILES))

SRC_NO_MAIN	=	$(addprefix $(SRC_DIR), $(addsuffix $(EXTENSION), $(SRC_FILES_NO_MAIN)))

# tests
TESTS_DIR	=	tests/

TESTS_FILES	=	tests.c	\

TESTS	=	$(addprefix $(TESTS_DIR), $(TESTS_FILES))

NAME_TESTS	=	unit_tests

# compil
OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

# clean
BIN	=	vgcore*	\
		unit_tests*	\

# flags
FLAGS	=	-I./include	\
		-g	\

WFLAGS	=	-Wall	\
			-Werror	\
			-Wextra	\

CSFML_FLAGS	=	-lcsfml-graphics	\
			-lcsfml-window	\
			-lcsfml-system	\
			-lcsfml-audio	\
			-lm

TESTS_FLAGS	=	--coverage	\
				-lcriterion

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e "\033[1;34m\n=========== Solver files compilation ok ==========="
	@echo -e "\033[0m"
	$(CC) -o $(NAME) $(OBJ) $(FLAGS)
	@echo -e "\033[1;32m\n============== Solver compilation done =============="
	@echo -e "\033[0m"

clean:
	rm -f $(BIN)
	rm -f $(OBJ)
	@echo -e "\033[1;33m\n============ Solver cleaning done ============"
	@echo -e "\033[0m"

fclean:	clean
	rm -f $(NAME)
	@echo -e "\033[1;33m\n============ Solver full cleaning done ============"
	@echo -e "\033[0m"

re:	fclean all

exec:	re
	@echo
	@echo "-------------------------------------------------"
	@echo
	@./$(NAME)

gcovr:
		gcovr --exclude tests
		gcovr --exclude tests --branches

tests_run:	fclean
		gcc -o $(NAME_TESTS) $(SRC_NO_MAIN) $(TESTS) $(TESTS_FLAGS) $(FLAGS)
		./$(NAME_TESTS)

.PHONY:		all clean fclean re exec gcovr tests_run
