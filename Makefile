.PHONY: all, fclean, clean, re

NAME = ft_ls

GCC = gcc main.c list_tools.c parser.c options.c -o

LIBFT = libft/libft.a

all: $(NAME)

$(NAME):
		@echo "\033[33mLibrary's compilation\033[0m"
		@make -C libft/
		@echo "\033[33mProject's compilation\033[0m"
		@$(GCC) $(NAME) $(LIBFT)
		@echo "\033[33mAll compilation done\033[0m" "\033[32m [ok] \033[32m"

clean:
				@echo "\033[33mLibrary's cleaning\033[0m"
				@make -C libft/ clean

fclean: clean
		@rm -rf $(NAME)
		@make -C libft/ fclean

re: fclean all
