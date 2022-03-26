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


typedef struct	s_all {
	t_win		win;
	t_player	player;
	t_textures	textures;
	char		**map;
}				t_all;

int	render(t_all *vars);
void	refresh_win(t_win *win);
int init_mlx(t_win *win, int argc, char **argv);
t_image *init_new_img(void *mlx);
int	create_trgb(US_INT t, US_INT r, US_INT g, US_INT b);
int close_win(int key, t_all *vars);

#endif