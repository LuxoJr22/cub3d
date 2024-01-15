/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:34:56 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/15 11:01:26 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_game *game, float ra)
{
	game->raycast.mt.x = 0;
	game->raycast.mt.y = 0;
	game->raycast.dis.x = 1000000;
	game->raycast.dis.y = 1000000;
	cast_horizontal_line(game, ra, -1 / tan(ra));
	cast_vertical_line(game, ra, -tan(ra));
}

t_pos	cast_vert_line(t_game *game, float ra, float Tan, t_pos o)
{
	if (ra > P2 && ra < P3)
	{
		game->raycast.vc.x = (((int)game->player->px / 64) * 64) - 0.0001;
		game->raycast.vc.y = (game->player->px - game->raycast.vc.x)
			* Tan + game->player->py;
		o.x = -64;
		o.y = -o.x * Tan;
	}
	if (ra < P2 || ra > P3)
	{
		game->raycast.vc.x = ((int)game->player->px / 64) * 64 + 64;
		game->raycast.vc.y = (game->player->px - game->raycast.vc.x)
			* Tan + game->player->py;
		o.x = 64;
		o.y = -o.x * Tan;
	}
	if (ra == 0 || ra == PI)
		o.x = 0;
	return (o);
}

void	cast_vertical_line(t_game *game, float ra, float Tan)
{
	int		mp;
	int		dof;
	t_pos	o;

	dof = 0;
	o = cast_vert_line(game, ra, Tan, o);
	while (dof < 20 && o.x != 0)
	{
		mp = (int)game->raycast.vc.y / 64 * game->map_w
			+ (int)game->raycast.vc.x / 64;
		if (mp > 0 && mp < (game->map_w * game->map_h) && game->map[mp] != 0)
		{
			game->raycast.mt.y = game->map[mp] - 1;
			game->raycast.dis.y = dist(game->player->px, game->player->py,
					game->raycast.vc.x, game->raycast.vc.y);
			dof = 20;
		}
		else
		{
			game->raycast.vc.x += o.x;
			game->raycast.vc.y += o.y;
			dof += 1;
		}
	}
}

t_pos	cast_hori_line(t_game *game, float ra, float Tan, t_pos o)
{
	if (ra > PI)
	{
		game->raycast.hc.y = (((int)game->player->py / 64) * 64) - 0.0001;
		game->raycast.hc.x = (game->player->py - game->raycast.hc.y)
			* Tan + game->player->px;
		o.y = -64;
		o.x = -o.y * Tan;
	}
	if (ra < PI)
	{
		game->raycast.hc.y = ((int)game->player->py / 64) * 64 + 64;
		game->raycast.hc.x = (game->player->py - game->raycast.hc.y)
			* Tan + game->player->px;
		o.y = 64;
		o.x = -o.y * Tan;
	}
	if (ra == 0 || (ra == PI))
		o.x = 0;
	return (o);
}

void	cast_horizontal_line(t_game *game, float ra, float Tan)
{
	int		mp;
	int		dof;
	t_pos	o;

	dof = 0;
	o = cast_hori_line(game, ra, Tan, o);
	while (dof < 20 && o.x != 0)
	{
		mp = (int)game->raycast.hc.y / 64 * game->map_w
			+ (int)game->raycast.hc.x / 64;
		if (mp > 0 && mp < (game->map_w * game->map_h) && game->map[mp] != 0)
		{
			game->raycast.mt.x = game->map[mp] - 1;
			game->raycast.dis.x = dist(game->player->px, game->player->py,
					game->raycast.hc.x, game->raycast.hc.y);
			dof = 20;
		}
		else
		{
			game->raycast.hc.x += o.x;
			game->raycast.hc.y += o.y;
			dof += 1;
		}
	}
}
