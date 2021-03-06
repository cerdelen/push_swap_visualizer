CC = gcc

# CFLAGS = -Wextra -Wall -Werror

LIB_PATH = Libft

LIB = $(LIB_PATH)/libft.a

MLX_PATH = mlx

MLX = $(MLX_PATH)/libmlx.a

MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit

NAME = visualize

SRCS = 	main.c operations.c resets.c\
		draw_lines.c list_input_managing.c\
		freeing_utils.c list_utils.c\
		instruction_input_managing.c\
		arg_input_managing.c\
		keys_and_actions.c draw_functions.c

GREEN = \033[92m
RESET = \033[0m
RED = \033[91m

all: $(MLX) $(LIB)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(SRCS) $(MLX) $(LIB) -o $(NAME)
	@echo "$(GREEN)Visualize successfully compiled!$(RESET)"

$(LIB):
	@$(MAKE) -C $(LIB_PATH)

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

clean:
	@$(MAKE) clean -C $(LIB_PATH)
#	@$(RM) $(NAME)

fclean:
	@$(MAKE) fclean -C $(LIB_PATH)
	@$(RM) $(NAME)
	@echo "$(RED)Visualize successfully cleaned!$(RESET)"

re: fclean all
