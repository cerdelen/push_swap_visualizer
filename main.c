#include "includes/visualize.h"



int	close_game(mlx_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	// free_and_exit(vars);
	exit(0);
	return (0);
}

int	key_press(int key, mlx_data *vars)
{
	if (key == 53)
		close_game(vars);
	return (0);
}

bool input_init(int argc, char **argv, t_data *data)
{
	return true;
}

void	free_and_exit(t_data *data)
{
	if (data->stacks.stack_a != NULL)
	{
		ft_lstclear(&data->stacks.stack_a, ft_lstdelone);
	}
	if (data->stacks.stack_b != NULL)
	{
		ft_lstclear(&data->stacks.stack_b, ft_lstdelone);
	}
	
}

int main(int argc, char **argv)
{
	t_data		data;
	mlx_data	m_data;
	img_data	i_data;

	if (input_init(argc, argv, &data) == false)
		free_and_exit(&data);

	printf("%i %i %i %i\n", START_LINE_STACK_A, MIDDLE_LINE_X_VALUE - END_LINE_STACK_A,
		 START_LINE_STACK_B - MIDDLE_LINE_X_VALUE, WINDOW_W - (END_LINE_STACK_B));
	// printf("%f %f %f\n", START_LINE_STACK_A, END_LINE_STACK_A, MIDDLE_LINE_X_VALUE);
	m_data.mlx = mlx_init();
	m_data.win = mlx_new_window(m_data.mlx, WINDOW_W, WINDOW_H, "Push-Swap-Visualizer by CErdelen");
	i_data.img = mlx_new_image(m_data.mlx, WINDOW_W, WINDOW_H);
	mlx_get_data_addr(&i_data.img, &i_data.bits_per_pixel, &i_data.line_length, &i_data.endian);
	mlx_key_hook(m_data.win, key_press, &m_data);
	mlx_hook(m_data.win, 17, 0, close_game, &m_data);
	draw_line(m_data.mlx, m_data.win, START_LINE_STACK_A, 10, END_LINE_STACK_A, 10, 0x00FF0000);
	draw_line(m_data.mlx, m_data.win, MIDDLE_LINE_X_VALUE, 0, MIDDLE_LINE_X_VALUE, WINDOW_H, 0x00FF0000);
	draw_line(m_data.mlx, m_data.win, START_LINE_STACK_B, 10, END_LINE_STACK_B, 10, 0x00FF0000);
	// draw_line_img(&image, 10, START_LINE_STACK_A, 10, END_LINE_STACK_A, 0x00FF0000);
	// printf("no problem with draw line\n");
	// mlx_put_image_to_window(m_data.mlx, m_data.win, image.img, 0, 0);
	printf("%i %i %i %i\n", 10, START_LINE_STACK_A, 10, END_LINE_STACK_A);
	mlx_loop(m_data.mlx);
	return (0);
}
