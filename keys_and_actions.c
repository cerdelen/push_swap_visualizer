#include "includes/visualize.h"

int	close_game(t_data *data)
{
	if (MLX.win)
		mlx_destroy_window(MLX.mlx, MLX.win);
	free_list(&STACK_A);
	free_list(&STACK_B);
	free_at_end(data);
	free(data);
	exit(0);
	return (0);
}

void	start_slide(t_data *data)
{
	STATUS = SLIDES;
	clone_list(&IN_BACKUP, &STACK_A);
	SIZE_A = ft_lstsize(STACK_A);
	draw_stacks(data, &draw);
}

void	start_play(t_data *data)
{
	STATUS = PLAY;
	clone_list(&IN_BACKUP, &STACK_A);
	SIZE_A = ft_lstsize(STACK_A);
	draw_stacks(data, &draw);
}


int	key_press(int key, t_data *data)
{
	printf("key = %i\n", key);
	if (key == K_ESC)
		close_game(data);
	if (STATUS == MAIN)
	{
		if (key == K_S)
			start_slide(data);
		if (key == K_N)
			start_play(data);
	}
	else if (STATUS == SLIDES)
	{
		if (key == K_M)
			draw_menu(data);
	}
	else if (STATUS == AUTOVIEW)
	{
		if (key == K_M)
			draw_menu(data);
	}
	else if (STATUS == PLAY)
	{
		// printf("%zu %zu\n", SIZE_A, SIZE_B);
		if (key == K_M)
		{
			draw_menu(data);
			return (0);
		}
		else if (key == K_Q)
		{
			operation_sa(data, &STACK_A, &STACK_B);
			draw_stacks(data, &draw);
		}
		else if (key == K_W)
		{
			operation_sb(data, &STACK_A, &STACK_B);
			draw_stacks(data, &draw);
		}
		else if (key == K_E)
		{
			operation_ss(data, &STACK_A, &STACK_B);
			draw_stacks(data, &draw);
		}
		else if (key == K_R)
		{
			operation_pa(data, &STACK_A, &STACK_B);
			draw_stacks(data, &draw);
		}
		else if (key == K_T)
		{
			operation_pb(data, &STACK_A, &STACK_B);
			draw_stacks(data, &draw);
		}
		else if (key == K_Y)
		{
			operation_ra(data, &STACK_A, &STACK_B);
			draw_stacks(data, &draw);
		}
		else if (key == K_U)
		{
			operation_rb(data, &STACK_A, &STACK_B);
			draw_stacks(data, &draw);
		}
		else if (key == K_I)
		{
			operation_rr(data, &STACK_A, &STACK_B);
			draw_stacks(data, &draw);
		}
		else if (key == K_O)
		{
			operation_rra(data, &STACK_A, &STACK_B);
			draw_stacks(data, &draw);
		}
		else if (key == K_P)
		{
			operation_rrb(data, &STACK_A, &STACK_B);
			draw_stacks(data, &draw);
		}
		else if (key == K_Z)
		{
			operation_rrr(data, &STACK_A, &STACK_B);
			draw_stacks(data, &draw);
		}
	}
	return (0);
}
