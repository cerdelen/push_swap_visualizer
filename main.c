#include "includes/visualize.h"

int main(int argc, char **argv)
{
	t_data		*data;

	data = calloc(sizeof(t_data), 1);

	// if (arg_input_init(argc, argv, data) == false)
	// {
	// 	printf("error encountered with stack input\n");
	// 	return (close_game(data));
	// }

	if (list_input_init(argc, argv, data) == false)
	{
		printf("error encountered with stack input\n");
		return (close_game(data));
	}
	// if (operations_input_init(data) == false)
	// {
	// 	printf("error encountered with operations input\n");
	// 	return (close_game(data));
	// }
	
	MLX.mlx = mlx_init();
	MLX.win = mlx_new_window(MLX.mlx, WINDOW_W, WINDOW_H, "Push-Swap-Visualizer by CErdelen");
	reset_image(data);
	mlx_key_hook(MLX.win, key_press, data);
	mlx_hook(MLX.win, 17, 0, close_game, data);
	draw_menu(data);

	mlx_loop(MLX.mlx);
	return (0);
}
