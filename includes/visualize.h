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

#define END_LINE_X_STACK_A (WINDOW_W * 15 /32)
#define END_LINE_X_STACK_B WINDOW_W - WINDOW_W / 32

#define FIRST_LINE_Y 10
#define LAST_LINE_Y WINDOW_H - 10

#define MIDDLE_LINE_X_VALUE WINDOW_W/2

#define SIZE_A data->stacks.size_a
#define SIZE_B data->stacks.size_b
#define STACK_A data->stacks.stack_a
#define STACK_B data->stacks.stack_b
#define IN_BACKUP data->stacks.input_backup
#define MLX data->mlx
#define IMAGE data->full_img
#define STATUS data->status
#define INSTRUCTIONS data->instr

enum {
	ON_KEYDOWN		= 2,
	ON_KEYUP		= 3,
	ON_MOUSEDOWN	= 4,
	ON_MOUSEUP		= 5,
	ON_MOUSEMOVE	= 6,
	ON_EXPOSE		= 12,
	ON_DESTROY		= 17
};

enum {
	MAIN		= 0,
	AUTOVIEW	= 1,
	SLIDES		= 2,
	PLAY		= 3
};

enum
{
	K_ESC	= 53,
	K_A		= 0,
	K_S		= 1,
	K_M		= 46,
	K_N		= 45,


 	K_Q		= 12,
	K_W		= 13,
	K_E		= 14,
	K_R		= 15,
	K_T		= 17,
	K_Y		= 16,
	K_U		= 32,
	K_I		= 34,
	K_O		= 31,
	K_P		= 35,
	K_Z		= 6,
	K_X		= 7,
	K_C		= 8,



	K_B		= 11,

	K_LEFT	= 123,
	K_RIGHT	= 124,
	K_DOWN	= 125,
	K_UP	= 126,


	K_PLUS	= 24,
	K_MINUS	= 27
};

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
	int			status;
	char		**instr;
	img_data	full_img;
	mlx_data	mlx;
	t_stacks	stacks;
}				t_data;

//	Input Functions
bool		list_input_init(int argc, char **argv, t_data *data);
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

//	Push_Swap Visualization Functions

void		draw_stacks(t_data *data, void (*f)(int, int, int, t_data *, bool, int));
void		draw(int line_i, int elem_val, int max_value, t_data *data, bool stack, int line_max);
void		draw_menu(t_data *data);


bool		arg_input_init(int argc, char **argv, t_data *data);

bool		operations_input_init(t_data *data);

//	Operations functions
void		operation_pa(t_data *data, t_list **stack_a, t_list **stack_b);
void		operation_pb(t_data *data, t_list **stack_a, t_list **stack_b);
void		operation_ra(t_data *data, t_list **stack_a, t_list **stack_b);
void		operation_rb(t_data *data, t_list **stack_a, t_list **stack_b);
void		operation_rr(t_data *data, t_list **stack_a, t_list **stack_b);
void		operation_sa(t_data *data, t_list **stack_a, t_list **stack_b);
void		operation_sb(t_data *data, t_list **stack_a, t_list **stack_b);
void		operation_ss(t_data *data, t_list **stack_a, t_list **stack_b);
void		operation_rra(t_data *data, t_list **stack_a, t_list **stack_b);
void		operation_rrb(t_data *data, t_list **stack_a, t_list **stack_b);
void		operation_rrr(t_data *data, t_list **stack_a, t_list **stack_b);

//	Reset functions
void		reset_stacks(t_data *data);
void		reset_image(t_data *data);


//	Drawing functions
int			colour_perc(double perc);
void		draw(int line_i, int elem_val, int max_value, t_data *data, bool stack, int line_max);
void		draw_stacks(t_data *data, void (*f)(int, int, int, t_data *, bool, int));
void		draw_menu(t_data *data);

//	Keys and action functions
int			close_game(t_data *data);
void		start_slide(t_data *data);
void		start_play(t_data *data);
int			key_press(int key, t_data *data);


#endif