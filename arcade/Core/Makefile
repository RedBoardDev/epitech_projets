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
CFLAGS	+=	-g -Wall -Wextra -ldl -fno-gnu-unique
OBJ	=	$(SRC:.cpp=.o)

########## METHODES #########
NAME	=	arcade

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS)
	mv $(NAME) ../

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf ../$(NAME)

re:	fclean all
