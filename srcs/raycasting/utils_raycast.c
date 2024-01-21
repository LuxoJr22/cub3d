/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:39:24 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/21 16:29:31 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	ret_abs(float i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

t_pos	get_deltadist(t_pos raydir)
{
	t_pos	deltadist;

	if (raydir.x == 0)
		deltadist.x = 1e30;
	else
		deltadist.x = ret_abs(1.0 / raydir.x);
	if (raydir.y == 0)
		deltadist.y = 1e30;
	else
		deltadist.y = ret_abs(1.0 / raydir.y);
	return (deltadist);
}

void	get_sidedist(t_game *game, t_p map)
{
	if (game->rcast.raydir.x < 0)
	{
		game->rcast.step.x = -1;
		game->rcast.sidedist.x = ((game->player->px / 64) - map.x)
			* game->rcast.deltadist.x;
	}
	else
	{
		game->rcast.step.x = 1;
		game->rcast.sidedist.x = (map.x + 1.0 - (game->player->px / 64))
			* game->rcast.deltadist.x;
	}
	if (game->rcast.raydir.y < 0)
	{
		game->rcast.step.y = -1;
		game->rcast.sidedist.y = ((game->player->py / 64) - map.y)
			* game->rcast.deltadist.y;
	}
	else
	{
		game->rcast.step.y = 1;
		game->rcast.sidedist.y = (map.y + 1.0 - (game->player->py / 64))
			* game->rcast.deltadist.y;
	}
}

void	get_hmt(t_game *game)
{
	if (game->rcast.side == 0)
	{
		game->rcast.sidedist.x -= game->rcast.deltadist.x;
		game->rcast.perpwalldist = game->rcast.sidedist.x;
		game->rcast.hmt = 1;
		if (game->rcast.raydir.x > 0)
			game->rcast.hmt = 3;
	}
	else
	{
		game->rcast.sidedist.y -= game->rcast.deltadist.y;
		game->rcast.perpwalldist = game->rcast.sidedist.y;
		game->rcast.hmt = 0;
		if (game->rcast.raydir.y > 0)
			game->rcast.hmt = 2;
	}
}

void	get_perpwalldist(t_game *game)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (game->rcast.sidedist.x < game->rcast.sidedist.y)
		{
			game->rcast.sidedist.x += game->rcast.deltadist.x;
			game->rcast.map.x += game->rcast.step.x;
			game->rcast.side = 0;
		}
		else
		{
			game->rcast.sidedist.y += game->rcast.deltadist.y;
			game->rcast.map.y += game->rcast.step.y;
			game->rcast.side = 1;
		}
		if (game->map[game->rcast.map.y * game->map_w + game->rcast.map.x] > 0)
			hit = 1;
	}
	get_hmt(game);
}
