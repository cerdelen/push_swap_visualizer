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
	free(data);
}
