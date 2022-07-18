#include "includes/visualize.h"

void	reset_stacks(t_data *data)
{
	free_list(&STACK_A);
	free_list(&STACK_B);
	STACK_A = NULL;
	STACK_B = NULL;
	SIZE_A = 0;
	SIZE_B = 0;
}

void	reset_image(t_data *data)
{
	mlx_clear_window(MLX.mlx, MLX.win);
	if (IMAGE.img)
		mlx_destroy_image(MLX.mlx, IMAGE.img);
	IMAGE.img = mlx_new_image(MLX.mlx, WINDOW_W, WINDOW_H);
	data->full_img.addr = mlx_get_data_addr(IMAGE.img, &IMAGE.bits_per_pixel, &IMAGE.line_length, &IMAGE.endian);
}
