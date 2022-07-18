#include "includes/visualize.h"

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
	int		*temp;

	if (double_input(arr, max) == false)
		return false;
	i = 0;
	temp = malloc(sizeof(int) * max);
	for(int j = 0; j < max; j++)
		temp[j] = arr[j];
	ptr = *stack_x;
	sort_arr(temp, max);
	ptr = *stack_x;
	while (ptr)
	{
		lel = ptr->content;
		*lel = index_of_sorted_arr(temp, *((int *)ptr->content), max);
		ptr = ptr->next;
	}
	free(temp);
	return true;
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

bool list_input_init(int argc, char **argv, t_data *data)
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
	data->max_nbr = argc - 2;
	data->status = MAIN;
	return true;
}

