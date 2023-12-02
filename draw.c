/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:03:05 by luxojr            #+#    #+#             */
/*   Updated: 2023/11/29 12:03:05 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define SGN(_x) ((_x) < 0 ? -1 : ((_x) > 0 ? 1 : 0))


void draw_line(t_game *game, t_pos p1, t_pos p2, int color)
{
	int x0 = p1.x;
	int x1 = p2.x;
	int y0 = p1.y;
	int y1 = p2.y;
	int dx = x1 - x0;
	int dy = y1 - y0;
	int incX = SGN(dx);
	int incY = SGN(dy);
	int x;
	int y;
	int slope;
	int error;
	int errorInc;

	dx = abs(dx);
	dy = abs(dy);
	if (dy == 0)
	{
		x = x0;
		while (x != x1)
		{
			my_mlx_pixel_put(&game->frame1, x, y0, color);
			x += incX;
		}
	}
	else if (dx == 0)
	{
		y = y0;
		while (y != y1 + incY)
		{
			my_mlx_pixel_put(&game->frame1, x0, y, color);
			y += incY;
		}
	}
	else if (dx >= dy)
	{
		slope = 2 * dy;
		error = -dx;
		errorInc = -2 * dx;
		y = y0;
		x = x0;
		while (x != x1 + incX)
		{
			my_mlx_pixel_put(&game->frame1, x, y, color);
			error += slope;
			if (error >= 0)
			{
				y += incY;
				error += errorInc;
			}
			x += incX;
		}
	}
	else
	{
		slope = 2 * dx;
		error = -dy;
		errorInc = -2 * dy;
		x = x0;
		y = y0;
		while( y != y1 + incY)
		{
			my_mlx_pixel_put(&game->frame1, x, y, color);
			error += slope;
			if (error >= 0)
			{
				x += incX;
				error += errorInc;
			}
			y += incY;
		}
	}
}

void	draw_back(t_game *game, t_pos start, t_pos length, int color)
{
	int side;
	int i;
	int z;

	i = 0;
	z = 0;

	while (i < length.x)
	{
		while (z < length.y)
		{
			my_mlx_pixel_put(&game->frame1, start.x + i, start.y + z, color);
			z ++;
		}
		i ++;
		z = 0;
	}
}