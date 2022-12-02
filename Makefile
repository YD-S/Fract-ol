NAME    = fractol
CFLAGS  = -Wall -Wextra -Werror
SRC		= main.c fractals.c ft_mandelbrot.c complex.c colors.c mouse.c hooks.c ft_julia.c
OBJ		= ${SRC:.c=.o}
LIBFT = libft/libft.a
INC = -I libft/includes
MLX = MLX42/libmlx42.a
BREW = /opt/homebrew/Cellar/glfw/3.3.8/lib/

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJ)
	@gcc $(CFLAGS) $(OBJ) $(MLX) -lglfw -L $(BREW) $(INC) -o $(NAME) $(LIBFT)
	@echo 🔥 🔥 Compliling Everything ✅ ✅

$(LIBFT):
	@make -C libft

$(MLX):
	@make -C MLX42/
clean:
	@rm -rf $(OBJ)
	@make -C MLX42/ clean
	@make -C libft/ clean
	@echo 🔥 🔥 Deleting all .o Files 🗑️ 🗑️
fclean: clean
	@rm -f $(NAME)
	@make -C MLX42/ fclean
	@make -C libft/ fclean
	@echo 🔥 🔥 Deleting .a File 🗑️ 🗑️

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $<

re: fclean all

.PHONY: all clean fclean re bonus mlx42