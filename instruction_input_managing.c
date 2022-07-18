#include "includes/visualize.h"

bool	is_valid_instr(char *instr)
{
	if (ft_strncmp(instr, "pa", 3) == 0)
		return (true);
	if (ft_strncmp(instr, "pb", 3) == 0)
		return (true);
	if (ft_strncmp(instr, "sa", 3) == 0)
		return (true);
	if (ft_strncmp(instr, "sb", 3) == 0)
		return (true);
	if (ft_strncmp(instr, "ss", 3) == 0)
		return (true);
	if (ft_strncmp(instr, "ra", 3) == 0)
		return (true);
	if (ft_strncmp(instr, "rb", 3) == 0)
		return (true);
	if (ft_strncmp(instr, "rr", 3) == 0)
		return (true);
	if (ft_strncmp(instr, "rra", 3) == 0)
		return (true);
	if (ft_strncmp(instr, "rrb", 3) == 0)
		return (true);
	if (ft_strncmp(instr, "rrr", 3) == 0)
		return (true);
	return(false);
}

// bool	operations_input_init(t_data *data)
// {
// 	char	*word;
// 	int		i;

// 	i = 0;
// 	INSTRUCTIONS = malloc(sizeof(char *) * 9999);
// 	word = get_next_line(0);
// 	while (word)
// 	{
// 		if (word[ft_strlen(word)] == '\n')
// 			word[ft_strlen(word)] = 0;
// 		if (!is_valid_instr(word))
// 			return false;
// 		INSTRUCTIONS[i] = word;
// 		word = get_next_line(0);
// 		i++;
// 	}
// 	free(word);
// 	INSTRUCTIONS[i] = NULL;
// }

// bool	operations_input_init(t_data *data)
// {
// 	char	*word;
// 	int		i;
// 	t_list	*temp_stack = NULL;
// 	t_list	*temp;

// 	printf("yes i got here first\n");
// 	i = 0;
// 	word = get_next_line(0);
// 	printf("yes i got here \n");
// 	while (word)
// 	{
// 		if (word[ft_strlen(word)] == '\n')
// 			word[ft_strlen(word)] = 0;
// 		if (!is_valid_instr(word))
// 		{
// 			free(word);
// 			return false;
// 		}
// 		temp = ft_lstnew(word);
// 		ft_lstadd_back(&temp_stack, temp);
// 		word = get_next_line(0);
// 	}
// 	printf("yes i got here too \n");
// 	// free(word);
// 	temp = temp_stack;
//  	INSTRUCTIONS = malloc(sizeof(char *) * (ft_lstsize(temp_stack) + 1));
// 	while (temp)
// 	{
// 		INSTRUCTIONS[i] = temp->content;
// 		i++;
// 		temp = temp->next;
// 	}
// 	printf("yes i got here three \n");
// 	INSTRUCTIONS[i] = NULL;
// 	free_list(&temp_stack);
// 	return true;
// }
