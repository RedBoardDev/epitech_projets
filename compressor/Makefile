##
## EPITECH PROJECT, 2022
## B-FUN-400-MLH-4-1-compressor-thomas.ott
## File description:
## Makefile
##

MYPATH	:=	$(shell stack path --allow-different-user --local-install-root)

NAME	=	imageCompressor

RESET	=	\033[0m
BOLD_GREEN	=	\033[1;32m

all:
	@stack build --allow-different-user ||	\
	(echo -e "$(RESET)\033[1;31mCompilation failed$(RESET)" && false)
	cp "$(MYPATH)/bin/$(NAME)-exe" ./$(NAME)
	@echo -e "$(BOLD_GREEN)Compilation done$(RESET)"

clean:
	stack clean --allow-different-user

fclean:		clean
	rm -f $(NAME)

re:		fclean all
