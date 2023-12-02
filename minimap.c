/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:16:59 by luxojr            #+#    #+#             */
/*   Updated: 2023/12/02 17:59:09 by luxojr           ###   ########.fr       */
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
	while (my < game->map_h)
	{
		while (mx < game->map_w)
		{
			if (game->map[my * game->map_w + mx] == 1)
				draw_cube(game, mx * side , my * side, 0x00FFFFFF);
			else
				draw_cube(game, mx * side , my * side, 0x00000000);
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
	//create_img(game);
	//draw_cube(game, 75 , 75, 0x00FFFFFF);
	//draw_player(game);
}