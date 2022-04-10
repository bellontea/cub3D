#include "cub3d.h"

/*
- Вычисление расстояния от начальной клетки до первых сторон x и y (sideDist)
*/
void init_sideDist(t_all *vars)
{
	if (vars->player.rayDir.x < 0)
	{
		vars->player.step.x = -1;
		vars->player.sideDist.x = (vars->player.pos.x - vars->player.currRayOnMap.x) * vars->player.deltaDist.x;
	}
	else
	{
		vars->player.step.x = 1;
		vars->player.sideDist.x = (vars->player.currRayOnMap.x + 1.0 - vars->player.pos.x) * vars->player.deltaDist.x;
	}
	if (vars->player.rayDir.y < 0)
	{
		vars->player.step.y = -1;
		vars->player.sideDist.y = (vars->player.pos.y - vars->player.currRayOnMap.y) * vars->player.deltaDist.y;
	}
	else
	{
		vars->player.step.y = 1;
		vars->player.sideDist.y = (vars->player.currRayOnMap.y + 1.0 - vars->player.pos.y) * vars->player.deltaDist.y;
	}
}

/*
- Вычисление координат верктора луча (rayDir)
- Вычисление координат клетки, в которой находится луч в текущий момент (currRayOnMap)
- Вычичсление длины луча до следующей стороны x или y (deltaDist)
- Вычисление расстояния от начальной клетки до первых сторон x и y (sideDist)
*/
void init_ray_vars(t_all *vars, int x)
{
	double	cameraX;

	cameraX = 2 * x / (double) WIN_WIDTH - 1;
	vars->player.rayDir.x = vars->player.dir.x + vars->player.plane.x * cameraX;
	vars->player.rayDir.y = vars->player.dir.y + vars->player.plane.y * cameraX;
	vars->player.currRayOnMap.x = (int) vars->player.pos.x;
	vars->player.currRayOnMap.y = (int) vars->player.pos.y;
	if (vars->player.rayDir.x == 0)
		vars->player.deltaDist.x = 1e30;
	else
		vars->player.deltaDist.x = fabs(1.0 / vars->player.rayDir.x);
	if (vars->player.rayDir.y == 0)
		vars->player.deltaDist.y = 1e30;
	else
		vars->player.deltaDist.y = fabs(1.0 / vars->player.rayDir.y);
	init_sideDist(vars);
}

/*
- DDA алгоритм: идем по лучу, пока не врежемся в стену
- Вычисление расстояния от стены до плоскости камеры (planeWallDist)
*/
void	rayDDA(t_all *vars)
{
	while (1)
	{
		if (vars->player.sideDist.x < vars->player.sideDist.y)
		{
			vars->player.sideDist.x += vars->player.deltaDist.x;
			vars->player.currRayOnMap.x += vars->player.step.x;
			vars->player.side = X_SIDE;
		}
		else
		{
			vars->player.sideDist.y += vars->player.deltaDist.y;
			vars->player.currRayOnMap.y += vars->player.step.y;
			vars->player.side = Y_SIDE;
		}
		if (vars->map[vars->player.currRayOnMap.y][vars->player.currRayOnMap.x] == '1')
			break ;
	}
	if (vars->player.side == X_SIDE)
		vars->player.planeWallDist = (vars->player.sideDist.x - vars->player.deltaDist.x);
	else
		vars->player.planeWallDist = (vars->player.sideDist.y - vars->player.deltaDist.y);
}

int	define_texture(t_player plr)
{
	if (plr.side == X_SIDE)
	{
		if (plr.pos.x < plr.currRayOnMap.x)
			return (EA);
		return (WE);
	}
	if (plr.pos.y < plr.currRayOnMap.y)
		return (SO);
	return (NO);
}

int calculate_texX(t_player plr, t_texture tex)
{
	double wallX;
	int texX;

	if (plr.side == X_SIDE)
		wallX = plr.pos.y + plr.planeWallDist * plr.rayDir.y;
	else
		wallX = plr.pos.x + plr.planeWallDist * plr.rayDir.x;
	wallX -= floor((wallX));
	texX = (int)(wallX * (double)(tex.width));
	if ((plr.side == X_SIDE && plr.rayDir.x > 0) || (plr.side == Y_SIDE && plr.rayDir.y < 0)) 
		texX = tex.width - texX - 1;
	return (texX);
}

void draw_ver_line(t_all *vars, int x, int texX, t_texture tex)
{
	double step;
	double texPos;
	int texY;

	step = 1.0 * tex.height / vars->player.lineHeight;
	texPos = (vars->player.drawStart - WIN_HEIGHT / 2 + vars->player.lineHeight / 2) * step;
	for(int y = vars->player.drawStart; y < vars->player.drawEnd; y++)
	{
		texY = (int)texPos & (tex.height - 1);
		texPos += step;
		pixel_put(vars->win.img, x, y, tex.pic[texX][texY]);
	}
}

void calculate_borders(t_player *plr)
{
	plr->lineHeight = WIN_HEIGHT / plr->planeWallDist;
	plr->drawStart = -(plr->lineHeight) / 2 + WIN_HEIGHT / 2;
	if (plr->drawStart < 0)
		plr->drawStart = 0;
	plr->drawEnd = plr->lineHeight / 2 + WIN_HEIGHT / 2;
	if (plr->drawEnd >= WIN_HEIGHT)
		plr->drawEnd = WIN_HEIGHT - 1;

}

void raycaster(t_all *vars)
{
	int x;
	int texNum;

	x = 0;
	while (x < vars->win.width)
	{
		init_ray_vars(vars, x);
		rayDDA(vars);
		calculate_borders(&(vars->player));
		texNum = define_texture(vars->player);
		draw_ver_line(vars, x, calculate_texX(vars->player, vars->texture[texNum]), vars->texture[texNum]);
		x++;
	}
}