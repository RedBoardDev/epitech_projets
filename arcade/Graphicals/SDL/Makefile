##
## EPITECH PROJECT, 2022
## B-OOP-400-MLH-4-1-arcade-thomas.ott
## File description:
## Makefile
##

SRC_DIR	=	src/
SRC	=	$(shell find $(SRC_DIR) -type f '(' -name "*.cpp" ')')

########## COMPIL ##########

CXXFLAGS += -fPIC -g -std=c++20
CFLAGS	+=	-g -Wall -Wextra -ldl
SDLFLAGS += -lSDL2 -lGL -lSDL2_ttf
OBJ	=	$(SRC:.cpp=.o)

########## METHODES #########
NAME	=	arcade_sdl2.so

all: $(OBJ)
	g++ $(OBJ) -o $(NAME) $(CFLAGS) -shared $(SDLFLAGS)
	mkdir -p ../../lib
	mv $(NAME) ../../lib

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ../../lib/$(NAME)
	rm -rf $(NAME)

re:	fclean all

test: re
	g++ main.cpp -ldl -o test
