#include "includes/visualize.h"



int	close_game(t_data *data)
{
	if (MLX.win)
		mlx_destroy_window(MLX.mlx, MLX.win);
	free_at_end(data);
	free(data);
	exit(0);
	return (0);
}

void	start_slide(t_data *data)
{
	STATUS = SLIDES;
	draw_stacks(data, &draw);
}

int	key_press(int key, t_data *data)
{
	printf("key = %i\n", key);
	if (key == K_ESC)
		close_game(data);
	if (STATUS == MAIN)
	{
		if (key == K_S)
			start_slide(data);
	}
	else if (STATUS == SLIDES)
	{
		if (key == K_M)
			draw_menu(data);
	}
	else if (STATUS == AUTOVIEW)
	{
		if (key == K_M)
			draw_menu(data);
	}
	else if (STATUS == PLAY)
	{
		if (key == K_Q)
			operation_sa(&STACK_A, &STACK_B);
		if (key == K_W)
			operation_sb(&STACK_A, &STACK_B);
		if (key == K_E)
			operation_ss(&STACK_A, &STACK_B);
		if (key == K_R)
			operation_pa(&STACK_A, &STACK_B);
		if (key == K_T)
			operation_pb(&STACK_A, &STACK_B);
		if (key == K_Y)
			operation_ra(&STACK_A, &STACK_B);
		if (key == K_U)
			operation_rb(&STACK_A, &STACK_B);
		if (key == K_I)
			operation_rr(&STACK_A, &STACK_B);
		if (key == K_O)
			operation_rra(&STACK_A, &STACK_B);
		if (key == K_P)
			operation_rrb(&STACK_A, &STACK_B);
		if (key == K_Z)
			operation_rrr(&STACK_A, &STACK_B);
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
		y = FIRST_LINE_Y + (line_i * thickness);						// line_i * ((last_line - first_line) / how many lines)
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
		y = FIRST_LINE_Y + (line_i * thickness);						// line_i * ((last_line - first_line) / how many lines)
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
	draw_line_img(&IMAGE, MIDDLE_LINE_X_VALUE, 0, MIDDLE_LINE_X_VALUE, WINDOW_H, 0x00FF0000);
	mlx_put_image_to_window(MLX.mlx, MLX.win, IMAGE.img, 0, 0);
}

void	draw_menu(t_data *data)
{
	STATUS = MAIN;
	mlx_clear_window(MLX.mlx, MLX.win);
	mlx_string_put(MLX.mlx, MLX.win, 0, 10, 0x00FF0000, "HELLO THIS IS MENU");
	mlx_string_put(MLX.mlx, MLX.win, 0, 20, 0x00FF0000, "press s to start slides");
	mlx_string_put(MLX.mlx, MLX.win, 0, 30, 0x00FF0000, "press a to start auto");
	// mlx_string_put(MLX.mlx, MLX.win, 0, 30, 0x00FF0000, string);
	// mlx_string_put(MLX.mlx, MLX.win, 0, 40, 0x00FF0000, string);
	// mlx_string_put(MLX.mlx, MLX.win, 0, 50, 0x00FF0000, string);
}


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
	IMAGE.img = mlx_new_image(MLX.mlx, WINDOW_W, WINDOW_H);
	data->full_img.addr = mlx_get_data_addr(IMAGE.img, &IMAGE.bits_per_pixel, &IMAGE.line_length, &IMAGE.endian);
	mlx_key_hook(MLX.win, key_press, data);
	mlx_hook(MLX.win, 17, 0, close_game, data);
	draw_menu(data);

	mlx_loop(MLX.mlx);
	return (0);
}
