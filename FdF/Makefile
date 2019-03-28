NAME = fdf
FUNCS = get_next_line.c button_sec.c parsi.c math.c del_func.c rotat.c fdf.c set_pixel.c button.c valid_file.c start.c button_two.c
OBJ = $(FUNCS:.c=.o)

LIBFT_HEAD = libft/
LIB = libft/libft.a ./minilibx_macos/libmlx.a

all :$(NAME)

$(NAME) : $(LIB) $(OBJ)
	@gcc -Wall -Wextra -Werror $(FUNCS) $(LIB) -framework OpenGL -framework AppKit -I $(LIBFT_HEAD) -o $(NAME)
	@echo "[ $(NAME) created ]"

%.o: %.c $()
	@gcc -Wall -Wextra -Werror  -I $(LIBFT_HEAD) -c $< -o $@

$(LIB):
	@make -C libft
	@echo "[ $(LIB) created ]"

clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@echo "[ objects cleaned ]"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "[ $(NAME) and $(LIB) cleaned ]"

re: fclean all