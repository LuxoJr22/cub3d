/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:45:10 by luxojr            #+#    #+#             */
/*   Updated: 2023/12/10 23:46:08 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_back_mini(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 10)
	{
		while (y < 10)
		{
			draw_cube(game, x * 16, y * 16, 0x00FFFFFF);
			y ++;
		}
		y = 0;
		x ++;
	}
}

void	draw_border_mini(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 10)
	{
		while (y < 10)
		{
			if (x == 0 || y == 0 || x == 9 || y == 9)
				draw_cube(game, x * 16, y * 16, 0x00F66B83);
			y ++;
		}
		y = 0;
		x ++;
	}
}

void	draw_player(t_game *game)
{
	int		h;
	int		i;
	int		y;
	t_pos	p1;
	t_pos	p2;

	i = 0;
	y = 0;
	h = 8;
	while (i < h)
	{
		while (y < h)
		{
			mlx_pixel_put(game->mlx, game->mlx_win, (game->player->px / 4) + i,
				(game->player->py / 4) + y, 0xFFFFFFFF);
			y ++;
		}
		i ++;
		y = 0;
	}
}
