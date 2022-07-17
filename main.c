#include "includes/visualize.h"

void	free_list(t_list **list)
{
	t_list	*ptr;

	while (*list)
	{
		ptr = (*list)->next;
		free(*list);
		(*list) = ptr;
	}
}


void	free_at_end(t_data *data)
{
	if (STACK_A != NULL)
		free_list(&STACK_A);
	if (STACK_B != NULL)
		free_list(&STACK_B);
	if (IN_BACKUP != NULL)
		free_list(&IN_BACKUP);
	if (data->stacks.tabs)
		free(data->stacks.tabs);
}

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
	return (0);
}






void	clone_list(t_list **orig, t_list **copy)
{
	t_list	*ptr = *orig;
	t_list	*new;

	*copy = NULL;
	while (ptr)
	{
		new = (ft_lstnew(ptr->content));
		ft_lstadd_back(copy, new);
		ptr = ptr->next;
	}
}

void	print_lst_content_int(void *content)
{
	printf("%i\n", 	*((int *)content));
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
	mlx_get_data_addr(&IMAGE.img, &IMAGE.bits_per_pixel, &IMAGE.line_length, &IMAGE.endian);
	mlx_key_hook(MLX.win, key_press, data);
	mlx_hook(MLX.win, 17, 0, close_game, data);
	draw_line(MLX.mlx, MLX.win, START_LINE_STACK_A, 10, END_LINE_STACK_A, 10, 0x00FF0000);
	draw_line(MLX.mlx, MLX.win, MIDDLE_LINE_X_VALUE, 0, MIDDLE_LINE_X_VALUE, WINDOW_H, 0x00FF0000);
	draw_line(MLX.mlx, MLX.win, START_LINE_STACK_B, 10, END_LINE_STACK_B, 10, 0x00FF0000);
	// draw_line_IMAGE(&image, 10, START_LINE_STACK_A, 10, END_LINE_STACK_A, 0x00FF0000);
	// printf("no problem with draw line\n");
	// mlx_put_image_to_window(MLX.mlx, MLX.win, image.IMAGE, 0, 0);
	mlx_loop(MLX.mlx);
	return (0);
}
