#ifndef VISUALIZE_H
#define VISUALIZE_H

#include "mlx.h"
#include "libft.h"
#include "math.h"

#define WINDOW_W 1080			//
#define WINDOW_H 720			//

// #define MAX_VALUE_LENGTH (WINDOW_W/2) - (WINDOW_W/16)
// #define MIN_VALUE_LENGTH 

#define START_LINE_STACK_A WINDOW_W/32
#define START_LINE_STACK_B (WINDOW_W * 17 / 32)

#define END_LINE_STACK_A (WINDOW_W * 15 /32)
#define END_LINE_STACK_B WINDOW_W - WINDOW_W / 32

#define MIDDLE_LINE_X_VALUE WINDOW_W/2

#define STACK_A data->stacks.stack_a
#define STACK_B data->stacks.stack_b
#define IN_BACKUP data->stacks.input_backup
#define MLX data->mlx
#define IMAGE data->full_img

typedef struct mlx_data
{
	void		*mlx;
	void		*win;
}				mlx_data;

typedef struct s_stacks
{
	t_list		*input_backup;
	t_list		*stack_a;
	t_list		*stack_b;
	size_t		size_a;
	size_t		size_b;
	int			*tabs;
}				t_stacks;

typedef struct	img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				img_data;

typedef struct	s_data {
	int			time;
	int			max_nbr;
	img_data	full_img;
	mlx_data	mlx;
	t_stacks	stacks;
}				t_data;

//	Input Functions
bool		input_init(int argc, char **argv, t_data *data);
bool 		is_an_integer(const char *str_num);
void		sort_arr(int *arr_a, int max);
bool		double_input(int *arr, int max);
bool		reapply_values(t_list **stack_x, int max, int *arr);
t_list		*createinput(int argc, char **argv, int *tabs);
int			index_of_sorted_arr(int *arr, int value, int max);

//	List utility functions
void		clone_list(t_list **orig, t_list **copy);
void		print_lst_content_int(void *content);

//	Freeing functions
void		free_list(t_list **list);
void		free_at_end(t_data *data);

//	MLX Utility Functions
int			draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);
int			draw_line_img(img_data *img, int beginX, int beginY, int endX, int endY, int color);
int			close_game(t_data *data);
int			key_press(int key, t_data *data);

#endif