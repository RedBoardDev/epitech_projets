##
## EPITECH PROJECT, 2021
## project
## File description:
## Makefile
##

NAME_ASM	=	asm/asm

NAME_COREWAR	=	corewar/corewar

# src
SRC_DIR_ASM	=	asm/src/
SRC_DIR_COREWAR	=	corewar/src/
EXTENSION	=	.c

SRC_FILES_ASM	=	main_asm	\
					error_handling	\
					my_strdup	\
					get_file	\
					my_str_to_word_array	\
					op	\
					linked_lists	\
					my_strcmp	\
					my_getnbr	\
					convert_to_bit	\
					convert_to_bit_two	\
					get_label_info	\
					display_header	\
					write_to_file	\
					getnbr	\
					str_to_word	\
					factory	\

SRC_FILES_COREWAR	=	flags	\
						my_put	\
						debug	\
						init	\
						main_flags	\
						main_corewar	\
						init_champions	\
						my_strlen	\
						utils	\
						init_arena	\
						op	\
						main_clock	\
						sti	\
						live	\
						ld	\
						zjmp	\
						fork	\
						add		\
						st	\
						sub	\
						and	\
						or	\
						xor	\
						ldi	\
						lld	\
						lldi	\
						lfork	\
						aff	\
						init_champion_two	\
						main_clock_two	\
						main_clock_three	\
						utils_two	\

SRC_ASM	=	$(addprefix $(SRC_DIR_ASM), $(addsuffix $(EXTENSION), $(SRC_FILES_ASM)))

SRC_COREWAR	=	$(addprefix $(SRC_DIR_COREWAR), $(addsuffix $(EXTENSION), $(SRC_FILES_COREWAR)))

# compilation
OBJ_ASM	=	$(SRC_ASM:.c=.o)

OBJ_COREWAR	=	$(SRC_COREWAR:.c=.o)

CC	=	gcc -g

# clean file
BIN	=	vgcore*	\
		unit_tests*	\

# flags
FLAGS	=	-g	\

# CFLAGS	+=	-Werror	\
# 			-Wextra	\
# 			-Wall	\

all:	$(NAME_ASM) $(NAME_COREWAR)
# all:	$(NAME_ASM)
# all:	$(NAME_COREWAR)

$(NAME_ASM):	$(OBJ_ASM)
	@echo -ne "\033[1;34m=============== Files asm compilation ok ============="
	@echo -e "\033[0m"
	$(CC) -o $(NAME_ASM) $(OBJ_ASM) $(FLAGS)
	@echo -ne "\033[1;32m=============== Compilation asm done ================="
	@echo -e "\033[0m"

$(NAME_COREWAR):	$(OBJ_COREWAR)
	@echo -ne "\033[1;34m=============== Files corewar compilation ok ============="
	@echo -e "\033[0m"
	$(CC) -o $(NAME_COREWAR) $(OBJ_COREWAR) $(FLAGS)
	@echo -ne "\033[1;32m=============== Compilation corewar done ================="
	@echo -e "\033[0m"

clean:
	rm -f $(BIN_ASM)
	rm -f $(OBJ_ASM)
	rm -f $(BIN_COREWAR)
	rm -f $(OBJ_COREWAR)
	@echo -ne "\033[1;33m=============== Cleaning done ===================="
	@echo -e "\033[0m"

fclean:	clean
	rm -f $(NAME_ASM)
	rm -f $(NAME_COREWAR)
	@echo -ne "\033[1;33m=============== Full cleaning done ==============="
	@echo -e "\033[0m"

re:	fclean all

.PHONY:		all clean fclean re
