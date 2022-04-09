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

# define PI 3.141592
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

typedef struct	s_point // структура для точки int
{
	int	x;
	int	y;
	int	z;
}				  t_point;

typedef struct	s_dot // структура для точки double
{
	double	x;
	double	y;
}				  t_dot;

typedef struct	s_player //структура для игрока и луча
{
	t_dot	pos;
	t_dot	dir;
	t_dot	plane;
	float	angle;
	
}				  t_player;

typedef struct	s_move
{
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;
	int		key_l;
	int		key_r;
}				t_move;

typedef struct	s_texture {
	char	*file_name;
	int		width;
	int		height;
	int		**pic;

}				t_texture;

typedef struct	s_all {
	t_win		win;
	t_player	player;
	t_move		move;
	t_texture	texture[4];
	int			color_c;
	int			color_f;
	char		**map;
}				t_all;

int		render(t_all *vars);
void	refresh_win(t_win *win);
int		init_mlx(t_all *vars, int argc, char **argv);
t_image	*init_new_img(void *mlx);
int		create_trgb(US_INT t, US_INT r, US_INT g, US_INT b);
int		close_win(t_all *vars);
int		map_parcer(t_all *vars, char *file_name);
void	pixel_put(t_image *data, int x, int y, int color);
void	mini_map(t_all *vars);
int		key_press(int key, t_all *vars);
int	key_realease(int key, t_all *vars);
int init_player(t_all *vars);
void raycaster(t_all *vars);
void DDA(t_point start, t_point end, int size, t_all *vars);
void drow_sqr(t_point point, int color, t_image *img);
void draw_vision(t_point point, t_all * vars);
void	draw_player(t_point point, t_all * vars);
int	get_color_minimap(char ch);
void draw_minimap(t_point point, t_all * vars);
int head_parcer(t_all *vars, int file);

#endif