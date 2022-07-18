#include "includes/visualize.h"

bool		arg_input_init(int argc, char **argv, t_data *data)
{
	if (argc > 3)
	{
		printf("Too many arguments!");
		return false;
	}
	else if (argc == 3)			//	first push swap path then path to folder with permutation
	{

	}
	else if (argc == 2)			//	only push swap path
	{
		
	}
	else if (argc == 1)			//	with this path i can only chose from precoded permutations and play with builtin operations
	{

	}
	return true;
}
