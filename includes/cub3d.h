#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# include "key.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdio.h>


# define US_INT unsigned short int

# define PI 3,141592
# define WIN_WIDTH	1000.L
# define WIN_HEIGHT 1000.L
# define SCALE 16 // условный размер каждого квадратика в карте

// пока немного не пон че с текстурами делать, пока не буду

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct	s_win {
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_image		*img;
	unsigned int	iter;
}				t_win;

typedef struct	s_point // структура для точки
{
	int	x;
	int	y;
	int	z;
}				  t_point;

typedef struct	s_player //структура для игрока и луча
{
	float	x;
	float	y;
	float	angle;
	float	dir;
	float	start;
	float	end;
}				  t_player;

typedef struct	s_textures
{
	int		no;
	int		so;
	int		we;
	int		ea;
	t_point	floor;
	t_point	ceiling;
}				t_textures;

typedef struct	s_move
{
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;
	int		key_l;
	int		key_r;
}				t_move;

typedef struct	s_all {
	t_win		win;
	t_player	player;
	t_textures	textures;
	t_move		move;
	char		**map;
}				t_all;

int		render(t_all *vars);
void	refresh_win(t_win *win);
int		init_mlx(t_all *vars, int argc, char **argv);
t_image	*init_new_img(void *mlx);
int		create_trgb(US_INT t, US_INT r, US_INT g, US_INT b);
int		close_win(t_all *vars);
int		set_map(t_all *vars, char *file_name);
void	pixel_put(t_image *data, int x, int y, int color);
void	mini_map(t_all *vars);
int		key_press(int key, t_all *vars);
int	key_realease(int key, t_all *vars);

#endif