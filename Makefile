NAME    = fractol
CFLAGS  = -Wall -Wextra -Werror
SRC		= main.c fractals.c ft_mandelbrot.c complex.c colors.c mouse.c hooks.c
OBJ		= ${SRC:.c=.o}
LIBFT = libft/libft.a
INC = -I libft/includes
MLX = MLX42/libmlx42.a
BREW = /opt/homebrew/opt/glfw/lib

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
	@echo 🔥 🔥 Deleting all .o Files 🗑️ 🗑️
fclean: clean
	@rm -f $(NAME)
	@make -C MLX42/ fclean
	@echo 🔥 🔥 Deleting .a File 🗑️ 🗑️

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $<

re: fclean all

.PHONY: all clean fclean re bonus mlx42