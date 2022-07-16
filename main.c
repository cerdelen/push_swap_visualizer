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

t_list	*createinput(int argc, char **argv, int *tabs)
{
	t_list				*stack_a;
	t_list				*new;
	int					ind;

	ind = 0;
	stack_a = NULL;
	while (ind < argc - 1)
	{
		tabs[ind] = ft_atoi(argv[ind + 1]);
		new = ft_lstnew(&tabs[ind]);
		ft_lstadd_back(&stack_a, new);
		ind++;
	}
	return (stack_a);
}

int	index_of_sorted_arr(int *arr, int value, int max)
{
	int	i;

	i = 0;
	while (i < max)
	{
		if (value == arr[i])
			return (i);
		i++;
	}
	return (i);
}

void	sort_arr(int *arr_a, int max)
{
	int	i;
	int	temp;

	i = 0;
	while (i < max - 1)
	{
		i++;
		if (arr_a[i] < arr_a[i - 1])
		{
			temp = arr_a[i];
			arr_a[i] = arr_a[i - 1];
			arr_a[i - 1] = temp;
			i = 0;
		}
	}
}

bool	double_input(int *arr, int max)
{
	for (int i = 1; i < max; i++)
		if (arr[i - 1] == arr[i])
			return false;
	return true;
}

bool	reapply_values(t_list **stack_x, int max, int *arr)
{
	t_list	*ptr;
	int		i;
	int		*lel;

	i = 0;
	ptr = *stack_x;
	sort_arr(arr, max);
	if (double_input(arr, max) == false)
		return false;
	ptr = *stack_x;
	while (ptr)
	{
		lel = ptr->content;
		*lel = index_of_sorted_arr(arr, *((int *)ptr->content), max);
		ptr = ptr->next;
	}
	return true;
}

bool is_an_integer(const char *str_num)
{
	int	len;
	int	i = 0;

	if (str_num[0] == '-' || str_num[0] == '+')
	{
		if (str_num[1] == 0)
			return false;
		i = 1;
	}
	while (str_num[i])
		if (ft_isdigit(str_num[i++]) == 0)
			return false;
	i = 0;
	len = ft_strlen(str_num);
	if (len > 11)
		return (false);
	if (len > 10 && str_num[0] != '-')
		return (false);
	if (len > 10 && str_num[0] == '-')
	{
		i = ft_strncmp(str_num, "-2147483648", 11);
		if (i > 0)
			return (false);
	}
	if (len == 10 && str_num)
	{
		i = ft_strncmp(str_num, "2147483647", 11);
		if (i > 0)
			return (false);
	}
	return (true);
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

bool input_init(int argc, char **argv, t_data *data)
{
	int	j = 1;
	for (int i = 1; i < argc; i++)
		if (is_an_integer(argv[i]) == false)
			return false;
	data->stacks.tabs = malloc(sizeof(int) * (argc - 1));
	STACK_A = NULL;
	STACK_B = NULL;
	STACK_A = createinput(argc, argv, data->stacks.tabs);
	if (reapply_values(&STACK_A, argc - 1, data->stacks.tabs) == false)
		return (false);
	clone_list(&STACK_A, &IN_BACKUP);
	// printf("start of print content A\n");
	// ft_lstiter(STACK_A, print_lst_content);
	// printf("start of print content backup\n");
	// ft_lstiter(IN_BACKUP, print_lst_content);
	return true;
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
