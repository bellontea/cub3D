#include "cub3d.h"

void draw_ver_line(t_all *vars, int x, int start, int end)
{
	while (start < end)
	{
		pixel_put(vars->win.img, x, start, create_trgb(0, 0, 0, 255));
		start++;
	}
}

void raycaster(t_all *vars)
{
	int x = 0;
	t_dot rayDir;
	double cameraX;
	t_point map;
	t_dot sideDist;
	t_dot deltaDist;
	double perpWallDist;
	t_point step;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
	int texNum;

	while (x < vars->win.width)
	{
		// вычисление x на плоскости камеры
		// -1 / 0 / 1 - лево / центр / право
		cameraX = 2 * x / (double) vars->win.width - 1;

		// вычисление координат вектора луча
		rayDir.x = vars->player.dir.x + vars->player.plane.x * cameraX;
		rayDir.y = vars->player.dir.y + vars->player.plane.y * cameraX;

		// координаты клетки, в которой находится луч, изначально равно позиции игрока
		map.x = (int) vars->player.pos.x;
		map.y = (int) vars->player.pos.y;

		// длина луча до следующей стороны x или y
		if (rayDir.x == 0)
			deltaDist.x = 1e30;
		else
			deltaDist.x = fabs(1.0 / rayDir.x);
		
		if (rayDir.y == 0)
			deltaDist.y = 1e30;
		else
			deltaDist.y = fabs(1.0 / rayDir.y);

		// определяем sideDist x и y - расстояния от начальной клетки до первых сторон x и y
		if (rayDir.x < 0)
		{
			step.x = -1;
			sideDist.x = (vars->player.pos.x - map.x) * deltaDist.x;
		}
		else
		{
			step.x = 1;
			sideDist.x = (map.x + 1.0 - vars->player.pos.x) * deltaDist.x;
		}
		if (rayDir.y < 0)
		{
			step.y = -1;
			sideDist.y = (vars->player.pos.y - map.y) * deltaDist.y;
		}
		else
		{
			step.y = 1;
			sideDist.y = (map.y + 1.0 - vars->player.pos.y) * deltaDist.y;
		}
		// DDA алгоритм: идем по лучу, пока не врежемся в стену
		while (1)
		{
			if (sideDist.x < sideDist.y)
			{
				sideDist.x += deltaDist.x;
				map.x += step.x;
				side = 0;
			}
			else
			{
				sideDist.y += deltaDist.y;
				map.y += step.y;
				side = 1;
			}
			if (vars->map[map.y][map.x] == '1')
				break;
		}
		// вычисляем расстояние от стены до плоскости, где находится игрок
		if (side == 0)
			perpWallDist = (sideDist.x - deltaDist.x);
		else
			perpWallDist = (sideDist.y - deltaDist.y);

		// вычисляем высоту стены и координаты для отрисовки
		lineHeight = vars->win.height / perpWallDist;
		drawStart = -lineHeight / 2 + vars->win.height / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + vars->win.height / 2;
		if (drawEnd >= vars->win.height)
			drawEnd = vars->win.height - 1;

		// Определяем текстуру
		if (side == 0)
		{
			if (vars->player.pos.x < map.x)
				texNum = EA;
			else
				texNum = WE;
		}
		else
		{
			if (vars->player.pos.y < map.y)
				texNum = SO;
			else
				texNum = NO;
		}

		double wallX;
		if (side == 0)
			wallX = vars->player.pos.y + perpWallDist * rayDir.y;
		else
			wallX = vars->player.pos.x + perpWallDist * rayDir.x;
		wallX -= floor((wallX));

		int texX = (int)(wallX * (double)(vars->texture->width));
		if(side == 0 && rayDir.x > 0) texX = vars->texture->width - texX - 1;
		if(side == 1 && rayDir.y < 0) texX = vars->texture->width - texX - 1;

		double step = 1.0 * vars->texture->height / lineHeight;
		double texPos = (drawStart - vars->win.height / 2 + lineHeight / 2) * step;
		for(int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & (vars->texture->height - 1);
			texPos += step;
			int color = vars->texture[texNum].pic[texX][texY];
			pixel_put(vars->win.img, x, y, color);
		}

		// // рисуем стену
		// draw_ver_line(vars, x, drawStart, drawEnd);

		x++;
	}
	
}