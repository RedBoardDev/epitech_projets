NAME =  libasm.so

# src
EXTENSION	=	.asm
ASFLAGS	=	-f elf64 -g
CFLAGS	=	-fPIC -shared
BIN	=	vgcore*

SRC_DIR	=	src/
SRC	=	$(shell find $(SRC_DIR) -type f '(' -name "*.asm" ')')
OBJ	=	$(SRC:.asm=.o)

# compile

all:	$(NAME)

$(NAME):	$(OBJ)
			ld $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.asm
	nasm $(ASFLAGS) $< -o $@

clean:
		rm -rf $(BIN)
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:		clean all

.PHONY:		all clean fclean re
