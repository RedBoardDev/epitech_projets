##
## EPITECH PROJECT, 2021
## project
## File description:
## Makefile
##

NAME	=	my_world

# src
SRC_DIR	=	./
EXTENSION	=	.c

SRC_FILES	=	events/events	\
				events/key_pressed	\
				events/key_released	\
				events/mouse	\
				events/text	\
				interface/menu/buttons/buttons1	\
				interface/menu/buttons/buttons2	\
				interface/menu/events_menu	\
				interface/world/buttons/arrows	\
				interface/world/buttons/rotate	\
				interface/world/buttons/save_home	\
				interface/world/buttons/save	\
				interface/world/buttons/toggle	\
				interface/check_click_buttons	\
				interface/check_click_soundbox	\
				interface/check_mouse_on_buttons	\
				interface/init_spritesheets_menu	\
				interface/init_spritesheets	\
				interface/put_spritesheets	\
				interface/text_input_load_map	\
				interface/toggle_spritesheets	\
				interface/utils_sprites	\
				map/transform_map/check_incidence	\
				map/transform_map/transform_map	\
				map/check_limits_translation	\
				map/create_map_begin	\
				map/create_quad	\
				map/draw_map	\
				map/events_map	\
				map/exec_events_map	\
				map/get_color_with_z	\
				map/get_color	\
				map/get_highest_point	\
				map/init_maps_runtime	\
				map/re_create_map	\
				clean_window	\
				draw_simple	\
				init_all	\
				int_array_utils	\
				main	\
				myworld	\
				utils	\
				lib_sound	\

SRC	=	$(addprefix $(SRC_DIR), $(addsuffix $(EXTENSION), $(SRC_FILES)))

SRC	+=	bonus/buttons.c	\
		bonus/open_folder_with_maps.c	\
		bonus/load_file.c	\
		bonus/save_file.c	\

# no main
SRC_FILES_NO_MAIN	=	$(filter-out main, $(SRC_FILES))

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
		-L../lib	\
		-lmy	\
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
	@echo -e "\033[1;34m\n============== Files compilation ok =============="
	@echo -e "\033[0m"
	make -C ../lib/my
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(CSFML_FLAGS)
	@echo -e "\033[1;32m\n================= Compilation done ================="
	@echo -e "\033[0m"

clean:
	rm -f $(BIN)
	rm -f $(OBJ)
	make -C ../lib/my clean
	@echo -e "\033[1;33m\n=============== Cleaning done ==============="
	@echo -e "\033[0m"

fclean:	clean
	rm -f $(NAME)
	make -C ../lib/my fclean
	@echo -e "\033[1;33m\n=============== Full cleaning done ==============="
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
		make -C ../lib/my
		gcc -o $(NAME_TESTS) $(SRC_NO_MAIN) $(TESTS) $(TESTS_FLAGS) $(FLAGS)
		./$(NAME_TESTS)

.PHONY:		all clean fclean re exec gcovr tests_run
