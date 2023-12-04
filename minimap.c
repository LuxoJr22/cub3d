/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:16:59 by luxojr            #+#    #+#             */
/*   Updated: 2023/12/04 02:26:09 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void create_img(t_game *game)
{
	int	mx;
	int my;
	int side;

	mx = 0;
	my = 0;
	side = 16;
	int px = (game->player->px / 64);
	int py = (game->player->py / 64);
	int dx;
	int dy;
	dx = (game->player->px - (px * 64)) / 4;
	dy = (game->player->py - (py * 64)) / 4;
	while (my < game->map_h)
	{
		while (mx < game->map_w)
		{
			if ((mx > px - 5 && mx < px + 5) && (my > py - 5 && my < py + 5))
			{
				if (game->map[my * game->map_w + mx] == 1)
					draw_cube(game, (mx - px + 5) * side - dx, (my - py + 5)* side - dy, 0x00FFFFFF);
				else
					draw_cube(game, (mx - px + 5) * side - dx, (my - py + 5) * side - dy, 0x00000000);
			}
			mx ++;
		}
		my ++;
		mx = 0;
	}
}

void	draw_cube(t_game *game, int x, int y, int color)
{
	int side;
	int i;
	int z;

	i = 0;
	z = 0;
	side = 16;

	while (i < side)
	{
		while (z < side)
		{
			my_mlx_pixel_put(&game->frame1, x + i, y + z, color);
			z ++;
		}
		i ++;
		z = 0;
	}
}

void	draw_cube_side(t_game *game, int x, int y, int color, int side)
{
	int i;
	int z;

	i = 0;
	z = 0;

	while (i < side)
	{
		while (z < side)
		{
			my_mlx_pixel_put(&game->frame1, x + i, y + z, color);
			z ++;
		}
		i ++;
		z = 0;
	}
}

void draw_back_mini(t_game *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < 10)
	{
		while (y < 10)
		{
			draw_cube(game, x * 16, y * 16 , 0x00FFFFFF);
			y ++;
		}
		y = 0;
		x ++;
	}
}

void draw_border_mini(t_game *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < 10)
	{
		while (y < 10)
		{
			if (x == 0 || y == 0 || x == 9 || y == 9)
				draw_cube(game, x * 16, y * 16 , 0x00F66B83);
			y ++;
		}
		y = 0;
		x ++;
	}
}



void draw_player(t_game *game)
{
	int h;
	int i;
	int y;
	t_pos p1;
	t_pos p2;

	i = 0;
	y = 0;
	h = 8;

	while (i < h)
	{
		while (y < h)
		{
			mlx_pixel_put(game->mlx, game->mlx_win, (game->player->px  / 4) + i, (game->player->py / 4) + y, 0xFFFFFFFF);
			y ++;
		}
		i ++;
		y = 0;
	}
	/*p1.x = (game->player->px) / 4 + 4;
	p1.y = (game->player->py) / 4 + 4;
	p2.x = (game->player->px + (game->player->pdx * 7)) / 4 + 4;
	p2.y = (game->player->py + (game->player->pdy * 7)) / 4 + 4;
	draw_line(game, p1, p2, 0xFFFFFFFF);*/
}

void	draw_minimap(t_game *game)
{
	draw_back_mini(game);
	create_img(game);
	draw_cube(game, 80 , 80, 0x00FFFFFF);
	draw_border_mini(game);
	//draw_player(game);
}

void	show_map(t_game *game)
{
	t_p	o;
	t_p	p;
	int w;
	int l;

	int side;

	if (game->map_w * 16 > 960)
		side = 960 / game->map_w;
	else if (game->map_h * 16 > 640 && 640 / game->map_h < side)
		side = 640 / game->map_h;
	else
		side = 16;
	o.x = (960 - side * game->map_w) / 2;
	o.y = (640 - side * game->map_h) / 2 ;
	p.x = 0;
	p.y = 0;
	while (p.y < game->map_h)
	{
		while (p.x < game->map_w)
		{
			if (game->map[p.y * game->map_w + p.x] == 1)
				draw_cube_side(game, p.x * side + o.x, p.y * side + o.y, 0x00FFFFFF, side);
			else
				draw_cube_side(game, p.x * side + o.x, p.y * side + o.y, 0x00000000, side);
			p.x ++;
		}
		p.x = 0;
		p.y ++;
	}
	draw_cube_side(game, (game->player->px / 4 )+ o.x, (game->player->py / 4)+ o.y, 0x0000FF00, side);
}