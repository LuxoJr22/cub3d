/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:03:27 by luxojr            #+#    #+#             */
/*   Updated: 2023/11/29 12:03:27 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move(t_game *game)
{
	int		mx;
	int		my;
	float	pa;

	if (game->player->dx == 1 || game->player->dx == -1)
	{
		if (game->player->dx == 1)
			pa = game->player->pa + P2;
		else
			pa = game->player->pa - P2;
		pa = check_angle(pa);
		mx = (int)(game->player->px + ((cos(pa) * 5) / 10) * 2) / 64;
		my = (int)(game->player->py + ((sin(pa) * 5) / 10) * 2) / 64;
		if (game->map[my * game->map_w + mx] != 1)
		{
			game->player->px += ((cos(pa) * 5) / 5);
			game->player->py += ((sin(pa) * 5) / 5);
		}
	}
	if (game->player->dy == 1)
	{
		mx = (int)(game->player->px - ((game->player->pdx) / 10) * 2) / 64;
		my = (int)(game->player->py - ((game->player->pdy) / 10) * 2) / 64;
		if (game->map[my * game->map_w + mx] != 1)
		{
			game->player->px -= ((game->player->pdx) / 5);
			game->player->py -= ((game->player->pdy) / 5);
		}
	}
	if (game->player->dy == -1)
	{
		mx = (int)(game->player->px + ((game->player->pdx) / 10) * 2) / 64;
		my = (int)(game->player->py + ((game->player->pdy) / 10) * 2) / 64;
		if (game->map[my * game->map_w + mx] != 1)
		{
			game->player->px += ((game->player->pdx) / 5);
			game->player->py += ((game->player->pdy) / 5);
		}
	}
	if (game->player->cm == 1)
	{
		game->player->pa += 0.02;
		if (game->player->pa > 2 * PI)
			game->player->pa -= 2 * PI;
		game->player->pdx = cos(game->player->pa) * 5;
		game->player->pdy = sin(game->player->pa) * 5;
	}
	if (game->player->cm == -1)
	{
		game->player->pa -= 0.02;
		if (game->player->pa < 0)
			game->player->pa += 2 * PI;
		game->player->pdx = cos(game->player->pa) * 5;
		game->player->pdy = sin(game->player->pa) * 5;
	}
}
