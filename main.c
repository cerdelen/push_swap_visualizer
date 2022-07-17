#include "includes/visualize.h"



int	close_game(t_data *data)
{
	mlx_destroy_window(MLX.mlx, MLX.win);
	free_at_end(data);
	free(data);
	exit(0);
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == 53)
		close_game(data);
	if (STATUS == MENU)
	{
		if ()
	}
	return (0);
}

int		colour_perc(double perc)
{
	
	int		t = 0;
	int		r;
	int		g;
	int		b = 0;
	int		trgb;

	r = perc * 255;
	g = 255 - 255 * perc;
	trgb = t << 24 | r << 16 | g << 8 | b;
	return (trgb);
}

void	draw(int line_i, int elem_val, int max_value, t_data *data, bool stack, int line_max)
{
	int		y;
	int		thickness = (LAST_LINE_Y - FIRST_LINE_Y) / line_max;
	int		x_end;
	double	x_perc_of_line;

	if (stack == true)			//STACK A
	{
		
		x_perc_of_line = (double) elem_val / max_value;
		x_end = x_perc_of_line * (END_LINE_X_STACK_A - START_LINE_STACK_A) + 10 + START_LINE_STACK_A;
		// printf("line_i = %i\n val= %i max val = %i  \n middle oif calc = %i\n", line_i,elem_val, max_value, END_LINE_X_STACK_A - START_LINE_STACK_A);
		// x_end = (elem_val * 100) / max_value;
		y = FIRST_LINE_Y + (line_i * thickness);						// line_i * ((last_line - first_line) / how many lines)
		// printf("x_perc = %f\n x_end = %i\n", x_perc_of_line, x_end);
		for (int i = 0; i < thickness; i++)
		{
			draw_line_img(&IMAGE, START_LINE_STACK_A, y, x_end, y, colour_perc(x_perc_of_line));
			y++;
		}
	}
	if (stack == false)			//STACK B
	{
		x_perc_of_line = (double) elem_val / max_value;
		x_end = x_perc_of_line * (END_LINE_X_STACK_B - START_LINE_STACK_B) + 10 + START_LINE_STACK_B;
		// printf("line_i = %i\n val= %i max val = %i  \n middle oif calc = %i\n", line_i,elem_val, max_value, END_LINE_X_STACK_A - START_LINE_STACK_A);
		// x_end = (elem_val * 100) / max_value;
		y = FIRST_LINE_Y + (line_i * thickness);						// line_i * ((last_line - first_line) / how many lines)
		// printf("x_perc = %f\n x_end = %i\n", x_perc_of_line, x_end);
		for (int i = 0; i < thickness; i++)
		{
			draw_line_img(&IMAGE, START_LINE_STACK_B, y, x_end, y, 0x00FF0000);
			y++;
		}
	}
}

void	draw_stacks(t_data *data, void (*f)(int, int, int, t_data *, bool, int))
{
	t_list	*ptr;
	int		i;

	if (STACK_A)
	{
		// printf("i wanna start draw Stack a\n");
		ptr = STACK_A;
		i = 0;
		while (ptr != NULL)
		{
			if (ptr -> content)
				(*f)(i, *(int *)ptr->content, data->max_nbr, data, true, ft_lstsize(STACK_A));
			ptr = ptr->next;
			i++;
		}
	}
	if (STACK_B)
	{
		ptr = STACK_B;
		i = 0;
		while (ptr != NULL)
		{
			if (ptr -> content)
				(*f)(i, *(int *)ptr->content, data->max_nbr, data, false, ft_lstsize(STACK_B));
			ptr = ptr->next;
			i++;
		}
	}
	// draw_line(MLX.mlx, MLX.win, MIDDLE_LINE_X_VALUE, 0, MIDDLE_LINE_X_VALUE, WINDOW_H, 0x00FF0000);
	draw_line_img(&IMAGE, MIDDLE_LINE_X_VALUE, 0, MIDDLE_LINE_X_VALUE, WINDOW_H, 0x00FF0000);
	mlx_put_image_to_window(MLX.mlx, MLX.win, IMAGE.img, 0, 0);
}





int main(int argc, char **argv)
{
	t_data		*data;

	data = malloc(sizeof(t_data));
	if (input_init(argc, argv, data) == false)
	{
		// free_and_exit(&data);
		return (printf("error encountered with input\n"));
	}
	printf("NO error encountered with input\n");
	MLX.mlx = mlx_init();
	MLX.win = mlx_new_window(MLX.mlx, WINDOW_W, WINDOW_H, "Push-Swap-Visualizer by CErdelen");
	IMAGE.img = mlx_new_image(MLX.mlx, WINDOW_W, WINDOW_H);
	data->full_img.addr = mlx_get_data_addr(IMAGE.img, &IMAGE.bits_per_pixel, &IMAGE.line_length, &IMAGE.endian);
	mlx_key_hook(MLX.win, key_press, data);
	mlx_hook(MLX.win, 17, 0, close_game, data);
	// draw_line(MLX.mlx, MLX.win, START_LINE_STACK_A, 10, END_LINE_STACK_A, 10, 0x00FF0000);
	// draw_line(MLX.mlx, MLX.win, MIDDLE_LINE_X_VALUE, 0, MIDDLE_LINE_X_VALUE, WINDOW_H, 0x00FF0000);
	// draw_line(MLX.mlx, MLX.win, START_LINE_STACK_B, 10, END_LINE_STACK_B, 10, 0x00FF0000);


	// draw_line_img(&data->full_img, 0, 0, WINDOW_W, WINDOW_H, 0x00FF0000);
	// mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->full_img.img, 0, 0);

	draw_stacks(data, &draw);



	// draw_line_IMAGE(&image, 10, START_LINE_STACK_A, 10, END_LINE_STACK_A, 0x00FF0000);
	// printf("no problem with draw line\n");
	// mlx_put_image_to_window(MLX.mlx, MLX.win, image.IMAGE, 0, 0);
	mlx_loop(MLX.mlx);
	return (0);
}
