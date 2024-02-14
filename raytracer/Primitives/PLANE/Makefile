SRC_DIR	=	src/
SRC	=	$(shell find $(SRC_DIR) -type f '(' -name "*.cpp" ')')

########## COMPIL ##########

CXXFLAGS += -fPIC -g -std=c++2a
CFLAGS	+=	-g -Wall -Wextra -ldl
OBJ	=	$(SRC:.cpp=.o)

########## METHODES #########
NAME	=	raytracer_plane.so

all:	$(OBJ)
	g++ $(OBJ) -o $(NAME) $(CFLAGS) -shared
	mkdir -p ../../plugins
	mv $(NAME) ../../plugins

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf ../../plugins/$(NAME)
	rm -rf $(NAME)

re:	fclean all
