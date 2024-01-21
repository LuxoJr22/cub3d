/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:45:10 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/21 16:28:15 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	draw_img(t_game *game, t_p d, t_p p, int side)
{
	t_p	m;

	m.x = 0;
	m.y = 0;
	while (m.y < game->map_h)
	{
		while (m.x < game->map_w)
		{
			if ((m.x > p.x - 5 && m.x < p.x + 5)
				&& (m.y > p.y - 5 && m.y < p.y + 5))
			{
				if (game->map[m.y * game->map_w + m.x] == 1
					|| game->map[m.y * game->map_w + m.x] == 2)
					draw_cube(game, (m.x - p.x + 5) * side - d.x,
						(m.y - p.y + 5) * side - d.y, 0x00FFFFFF);
				else
					draw_cube(game, (m.x - p.x + 5) * side - d.x,
						(m.y - p.y + 5) * side - d.y, 0x00000000);
			}
			m.x ++;
		}
		m.y ++;
		m.x = 0;
	}
}
