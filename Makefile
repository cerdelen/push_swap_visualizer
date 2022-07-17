CC = gcc

# CFLAGS = -Wextra -Wall -Werror

LIB_PATH = Libft

LIB = $(LIB_PATH)/libft.a

MLX_PATH = mlx

MLX = $(MLX_PATH)/libmlx.a

MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit

NAME = visualize

SRCS = 	main.c draw_lines.c list_input_managing.c freeing_utils.c list_utils.c instruction_input_managing.c

all: $(MLX) $(LIB)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(SRCS) $(MLX) $(LIB) -o $(NAME)
	@echo "\033[92mVisualize successfully compiled!\033[0m"


$(LIB):
	@$(MAKE) -C $(LIB_PATH)

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

clean:
	@$(MAKE) clean -C $(LIB_PATH)
	@$(RM) $(NAME)

fclean:
	@$(MAKE) fclean -C $(LIB_PATH)
	@$(RM) $(NAME)
	@echo "\033[91mVisualize successfully cleaned!\033[0m"

re: fclean all