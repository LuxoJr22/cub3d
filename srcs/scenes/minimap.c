/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:16:59 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/21 16:29:54 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	create_img(t_game *game)
{
	t_p	d;
	t_p	p;
	int	side;

	side = 16;
	p.x = (game->player->px / 64);
	p.y = (game->player->py / 64);
	d.x = (game->player->px - (p.x * 64)) / 4;
	d.y = (game->player->py - (p.y * 64)) / 4;
	draw_img(game, d, p, side);
}

void	draw_cube_side(t_game *game, t_p pos, int color, int side)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (i < side)
	{
		while (z < side)
		{
			my_mlx_pixel_put(&game->frame1, pos.x + i, pos.y + z, color);
			z ++;
		}
		i ++;
		z = 0;
	}
}

void	draw_minimap(t_game *game)
{
	draw_back_mini(game);
	create_img(game);
	draw_cube(game, 80, 80, 0x00FFFFFF);
	draw_border_mini(game);
}

void	draw_map(t_game *game, t_p p, t_p o, int side)
{
	t_p	pos;

	while (p.y < game->map_h)
	{
		while (p.x < game->map_w)
		{
			pos.x = p.x * side + o.x;
			pos.y = p.y * side + o.y;
			if (game->map[p.y * game->map_w + p.x] == 1
				|| game->map[p.y * game->map_w + p.x] == 2)
				draw_cube_side(game, pos, 0x00FFFFFF, side);
			else
				draw_cube_side(game, pos, 0x00000000, side);
			p.x ++;
		}
		p.x = 0;
		p.y ++;
	}
}

void	show_map(t_game *game)
{
	t_p	o;
	t_p	p;
	int	side;

	side = 16;
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
	draw_map(game, p, o, side);
	p.x = (game->player->px / 4) + o.x;
	p.y = (game->player->py / 4) + o.y;
	draw_cube_side(game, p, 0x0000FF00, side);
}
