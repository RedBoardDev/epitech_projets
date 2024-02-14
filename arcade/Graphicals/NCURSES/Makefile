##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC_DIR	=	src/
SRC	=	$(shell find $(SRC_DIR) -type f '(' -name "*.cpp" ')')

########## COMPIL ##########

CXXFLAGS += -fPIC -g -std=c++20
CFLAGS	+=	-g -Wall -Wextra -ldl
NCURSESFLAGS += -lcurses
OBJ	=	$(SRC:.cpp=.o)

########## METHODES #########
NAME	=	arcade_ncurses.so

all: $(OBJ)
	g++ $(OBJ) -o $(NAME) $(CFLAGS) -shared $(NCURSESFLAGS)
	mkdir -p ../../lib
	mv $(NAME) ../../lib

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ../../lib/$(NAME)
	rm -rf $(NAME)

re:	fclean all

test: re
	g++ main.cpp -ldl -o testCFLAGS
