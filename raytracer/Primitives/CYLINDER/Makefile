##
## EPITECH PROJECT, 2023
## B-OOP-400-MLH-4-1-raytracer-leo.baldachino
## File description:
## Makefile
##

SRC	=	Cylinder.cpp

NAME = 	../../plugins/raytracer_cylinder.so

all:	$(NAME)

$(NAME):	$(SRC)
	g++ -o $(NAME) $(SRC) -shared -fPIC

fclean:
	rm -f $(NAME)

re: fclean all
