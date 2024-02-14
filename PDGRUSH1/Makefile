##
## EPITECH PROJECT, 2021
## project
## File description:
## Makefile
##

NAME	=	 pushswap_checker

# src
SRC_DIR	=	.
SRC	=	$(shell find $(SRC_DIR) -type f '(' -name "*.hs" ')')

# compil
OBJ	=	$(SRC:.hs=.o)
HI_FILES	=	$(shell find $(SRC_DIR) -type f '(' -name "*.hi" ')')
CC	=	ghc --make

COUNT	=	0
TOTAL_NBR_FILES	=	$(shell echo $(SRC) | wc -w)

# clean
BIN	=	vgcore*

# flags
# FLAGS	=

# CFLAGS	+=	-Werror	\
# 			-Wextra	\
# 			-Wall

CSFML_FLAGS	=	-lcsfml-graphics	\
				-lcsfml-window	\
				-lcsfml-system	\
				-lcsfml-audio	\
				-lm

RESET	=	\033[0m
BLACK	=	\033[0;30m
RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
PURPLE	=	\033[0;35m
CYAN	=	\033[0;36m
WHITE	=	\033[0;37m
BOLD_BLACK	=	\033[1;30m
BOLD_RED	=	\033[1;31m
BOLD_GREEN	=	\033[1;32m
BOLD_YELLOW	=	\033[1;33m
BOLD_BLUE	=	\033[1;34m
BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_WHITE	=	\033[1;37m

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e "$(BOLD_BLUE)Files compilation ok\n$(RESET)"
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "$(BOLD_GREEN)Compilation done$(RESET)"

%.o: %.hs
	$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@echo -e "$(BOLD_CYAN)[$(shell echo $$(( $(COUNT) * 100 / \
	$(TOTAL_NBR_FILES) )))%]$(RESET) Compiling $< -> $@"
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(BIN)
	rm -f $(OBJ)
	rm -f $(HI_FILES)
	@echo -e "$(BOLD_YELLOW)Cleaning done\n$(RESET)"

fclean:	clean
	rm -f $(NAME)
	@echo -e "$(BOLD_YELLOW)Full cleaning done\n$(RESET)"

re:	clean all

.PHONY:		all clean fclean re
