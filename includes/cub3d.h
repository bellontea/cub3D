#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"
# include "key.h"

# define US_INT unsigned short int

# define WIN_WIDTH	1000.L
# define WIN_HEIGHT 1000.L

typedef struct	s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct	s_vars {
	void			*mlx;
	void			*win;
	t_img_data		*img;
	unsigned int	iter; 
}				t_vars;

int	render(t_vars *vars);
void refresh_win(t_vars *vars);
int init_mlx(t_vars *vars, int argc, char **argv);
t_img_data *init_new_img(void *mlx);
int	create_trgb(US_INT t, US_INT r, US_INT g, US_INT b);
int close_win(int key, t_vars *vars);

#endif