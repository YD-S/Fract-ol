NAME    = fractol
CFLAGS  = -Wall -Wextra -Werror
SRC		= main.c fractals.c ft_mandelbrot.c complex.c colors.c mouse.c hooks.c ft_julia.c error.c
OBJ		= ${SRC:.c=.o}
LIBFT = libft/libft.a
INC = -I libft/includes
MLX = MLX42/libmlx42.a
BREW = /opt/homebrew/Cellar/glfw/3.3.8/lib/
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@gcc $(CFLAGS) $(OBJ) $(MLX) -lglfw -L $(BREW) $(INC) -o $(NAME) $(LIBFT)
	@echo "$(COLOUR_GREEN)🔥 🔥 Compliling Everything ✅ ✅$(COLOUR_END)"

$(LIBFT):
	@make -C libft

$(MLX):
	@make -C MLX42/
clean:
	@rm -rf $(OBJ)
	@make -C MLX42/ clean
	@make -C libft/ clean
	@echo "$(COLOUR_RED)🔥 🔥 Deleting all .o Files 🗑️ 🗑️$(COLOUR_END)"
fclean: clean
	@rm -f $(NAME)
	@make -C MLX42/ fclean
	@make -C libft/ fclean
	@echo "$(COLOUR_RED)🔥 🔥 Deleting .a File 🗑️ 🗑️$(COLOUR_END)"

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $<

re: fclean all

.PHONY: all clean fclean re bonus mlx42