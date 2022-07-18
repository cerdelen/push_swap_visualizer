#include "includes/visualize.h"

void	operation_pa(t_data *data, t_list **stack_a, t_list **stack_b)
{
	t_list	*firstelem;

	if (STACKS.size_a == 0)
		return ;
	if (ft_lstsize(*stack_b) > 0)
	{
		firstelem = *stack_b;
		*stack_b = firstelem ->next;
		ft_lstadd_front(stack_a, firstelem);
	}
	write(1, "pa\n", 3);
}

void	operation_pb(t_data *data, t_list **stack_a, t_list **stack_b)
{
	t_list	*firstelem;

	if (ft_lstsize(*stack_a) > 0)
	{
		firstelem = *stack_a;
		*stack_a = firstelem ->next;
		ft_lstadd_front(stack_b, firstelem);
	}
	write(1, "pb\n", 3);
}

void	operation_ra(t_data *data, t_list **stack_a, t_list **stack_b)
{
	t_list	*firstelem;

	if(STACKS.stack_a < 2)
		return ;
	firstelem = *stack_a;
	*stack_a = firstelem->next;
	firstelem->next = NULL;
	ft_lstadd_back(stack_a, firstelem);
	write(1, "ra\n", 3);
}

void	operation_rb(t_data *data, t_list **stack_a, t_list **stack_b)
{
	t_list	*firstelem;

	if(STACKS.stack_b < 2)
		return ;
	firstelem = *stack_b;
	*stack_b = firstelem->next;
	firstelem->next = NULL;
	ft_lstadd_back(stack_b, firstelem);
	write(1, "rb\n", 3);
}

void	operation_rr(t_data *data, t_list **stack_a, t_list **stack_b)
{
	operation_ra(data, stack_a, stack_b);
	operation_rb(data, stack_a, stack_b);
}

void	operation_rra(t_data *data, t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*secondtolast;
	int		length;

	length = ft_lstsize(*stack_a);
	if (length > 1)
	{
		secondtolast = *stack_a;
		while (length > 2)
		{
			secondtolast = secondtolast -> next;
			length--;
		}
		last = secondtolast -> next;
		secondtolast -> next = NULL;
		ft_lstadd_front(stack_a, last);
	}
	write(1, "rra\n", 4);
}

void	operation_rrb(t_data *data, t_list **stack_a, t_list **stack_b)
{
	t_list	*last;
	t_list	*secondtolast;
	int		length;

	length = ft_lstsize(*stack_b);
	if (length > 1)
	{
		secondtolast = *stack_b;
		while (length > 2)
		{
			secondtolast = secondtolast -> next;
			length--;
		}
		last = secondtolast -> next;
		secondtolast -> next = NULL;
		ft_lstadd_front(stack_b, last);
	}
	write(1, "rrb\n", 4);
}

void	operation_rrr(t_data *data, t_list **stack_a, t_list **stack_b)
{
	operation_rra(data, stack_a, stack_b);
	operation_rrb(data, stack_a, stack_b);
}

void	operation_sa(t_data *data, t_list **stack_a, t_list **stack_b)
{
	t_list	*firstelement;
	t_list	*secondelement;
	t_list	*thirdelement;

	if (ft_lstsize(*stack_a) > 1)
	{
		firstelement = *stack_a;
		secondelement = firstelement ->next;
		thirdelement = secondelement ->next;
		secondelement->next = firstelement;
		firstelement->next = thirdelement;
		*stack_a = secondelement;
	}
	write(1, "sa\n", 3);
}

void	operation_sb(t_data *data, t_list **stack_a, t_list **stack_b)
{
	t_list	*firstelement;
	t_list	*secondelement;
	t_list	*thirdelement;

	if (ft_lstsize(*stack_b) > 1)
	{
		firstelement = *stack_b;
		secondelement = firstelement ->next;
		thirdelement = secondelement ->next;
		secondelement->next = firstelement;
		firstelement->next = thirdelement;
		*stack_b = secondelement;
	}
	write(1, "sb\n", 3);
}

void	operation_ss(t_data *data, t_list **stack_a, t_list **stack_b)
{
	operation_sa(data, stack_a, stack_b);
	operation_sb(data, stack_a, stack_b);
}
