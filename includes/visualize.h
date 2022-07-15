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

typedef struct mlx_data
{
	void		*mlx;
	void		*win;
}				mlx_data;

typedef struct s_stacks
{
	t_list		*stack_a;
	t_list		*stack_b;
	size_t		size_a;
	size_t		size_b;
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
	img_data	full_img;
	mlx_data	mlx_data;
	t_stacks	stacks;
}				t_data;

//	Init Functions
bool	input_init(int argc, char **argv, t_data *data);







//	MLX Utility Functions
int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);
int draw_line_img(img_data *img, int beginX, int beginY, int endX, int endY, int color);


#endif