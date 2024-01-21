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

#include "../cub3d.h"

void	draw_crossh(t_game *game)
{
	t_pos	start;
	t_pos	end;

	start.x = 468;
	start.y = 320;
	end.x = 10;
	end.y = 2;
	draw_back(game, start, end, get_trgb(0, 250, 0, 0));
	start.x = 482;
	start.y = 320;
	draw_back(game, start, end, get_trgb(0, 250, 0, 0));
}

void	draw_back(t_game *game, t_pos start, t_pos length, int color)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (i < length.x)
	{
		while (z < length.y)
		{
			if (start.y + z < 640)
				my_mlx_pixel_put(&game->frame1, start.x + i,
					start.y + z, color);
			z ++;
		}
		i ++;
		z = 0;
	}
}

void	draw_cube(t_game *game, int x, int y, int color)
{
	int	side;
	int	i;
	int	z;

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

int	is_visible(t_game *game)
{
	float	x;
	float	y;

	x = game->sprite.pos.x - game->player->px;
	y = game->sprite.pos.y - game->player->py;
	if (x < 0)
		x *= -1;
	if (y < 0)
		y *= -1;
	if (y > x)
	{
		if ((game->sprite.pos.y - game->player->py > 0)
			&& (game->player->pa > 0 && game->player->pa < PI))
			return (1);
		if ((game->sprite.pos.y - game->player->py < 0)
			&& (game->player->pa > PI && game->player->pa < 2 * PI))
			return (1);
	}
	else if (((game->sprite.pos.x - game->player->px < 0)
			&& (game->player->pa > P2 && game->player->pa < P3))
		|| ((game->sprite.pos.x - game->player->px > 0)
			&& (game->player->pa > P3 || game->player->pa < P2)))
		return (1);
	return (0);
}

void	draw_hud(t_game *game)
{
	draw_health(game);
	draw_mana(game);
}
