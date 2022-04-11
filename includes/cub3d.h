/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:33:32 by tjamis            #+#    #+#             */
/*   Updated: 2022/04/11 20:13:00 by tjamis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

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
# define WIN_WIDTH	1500
# define WIN_HEIGHT 1000
# define SCALE 16 // условный размер каждого квадратика в карте
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define X_SIDE 0
# define Y_SIDE 1

// пока немного не пон че с текстурами делать, пока не буду

typedef struct s_steps
{
	double	x;
	double	y;
}			t_steps;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_win {
	void			*mlx;
	void			*win;
	t_image			*img;
	unsigned int	iter;
}					t_win;

typedef struct s_point // структура для точки int
{
	int	x;
	int	y;
	int	z;
}		t_point;

typedef struct s_dot // структура для точки double
{
	double	x;
	double	y;
}			t_dot;

typedef struct s_player //структура для игрока и луча
{
	t_dot	pos;
	t_dot	dir;
	t_dot	plane;
	t_dot	ray_dir;
	t_point	curr_ray_on_map;
	t_dot	side_dist;
	t_dot	delta_dist;
	int		side;
	t_point	step;
	double	plane_wall_dist;
	int		draw_start;
	int		draw_end;
	int		line_height;
	float	angle;
}			t_player;

typedef struct s_move
{
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;
	int		key_l;
	int		key_r;
}			t_move;

typedef struct s_texture {
	char	*file_name;
	int		width;
	int		height;
	int		**pic;
}			t_texture;

typedef struct s_all {
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
int		key_realease(int key, t_all *vars);
int		init_player(t_all *vars);
void	raycaster(t_all *vars);
void	dda(t_point start, t_point end, int size, t_all *vars);
void	drow_sqr(t_point point, int color, t_image *img);
void	draw_vision(t_point point, t_all *vars);
void	draw_player(t_point point, t_all *vars);
int		get_color_minimap(char ch);
void	draw_minimap(t_point point, t_all *vars);
int		head_parcer(t_all *vars, int file);
void	*get_x_y(t_image *img, int x, int y);
int		set_no_texture(t_all *vars, char *str);
int		set_so_texture(t_all *vars, char *str);
int		set_we_texture(t_all *vars, char *str);
int		set_ea_texture(t_all *vars, char *str);
int		set_player(t_all *vars, int y);
int		check_map(char **map);
void	init_ray_vars(t_player *plr, int x);
void	ray_dda(t_all *vars);
void	calculate_borders(t_player *plr);
void	draw_ver_line(t_all *vars, int x, int tex_x, t_texture tex);
int		calculate_tex_x(t_player plr, t_texture tex);
int		define_texture(t_player plr);
void	*init_head_parcer(t_all *vars);
int		set_ceilling_color(t_all *vars, char *str);
int		set_floor_color(t_all *vars, char *str);
int		check_name_file(char *str);

#endif