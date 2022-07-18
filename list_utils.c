#include "includes/visualize.h"

void	clone_list(t_list **orig, t_list **copy)
{
	t_list	*ptr = *orig;
	t_list	*new;

	if(copy)
		free_list(copy);
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
