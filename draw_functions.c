#include "includes/visualize.h"

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
			draw_line_img(&IMAGE, START_LINE_STACK_B, y, x_end, y, colour_perc(x_perc_of_line));
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
	reset_stacks(data);
	mlx_clear_window(MLX.mlx, MLX.win);
	mlx_string_put(MLX.mlx, MLX.win, 0, 10, 0x00FF0000, "HELLO THIS IS MENU");
	mlx_string_put(MLX.mlx, MLX.win, 0, 20, 0x00FF0000, "press s to start slides");
	mlx_string_put(MLX.mlx, MLX.win, 0, 30, 0x00FF0000, "press a to start auto");
	mlx_string_put(MLX.mlx, MLX.win, 0, 40, 0x00FF0000, "press n to start play");
	// mlx_string_put(MLX.mlx, MLX.win, 0, 30, 0x00FF0000, string);
	// mlx_string_put(MLX.mlx, MLX.win, 0, 40, 0x00FF0000, string);
	// mlx_string_put(MLX.mlx, MLX.win, 0, 50, 0x00FF0000, string);
}
