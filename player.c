/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:47:21 by marvin            #+#    #+#             */
/*   Updated: 2023/04/20 19:47:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int move(t_game *game)
{
	int mx;
	int my;

	if (game->player->dy == 1)
	{
		mx = (int)(game->player->px - (game->player->pdx / 10)) / 64;
		my = (int)(game->player->py - (game->player->pdy / 10)) / 64;
		if (game->map[my * game->map_w + mx] != 1)
		{
			game->player->px -= (game->player->pdx / 10);
			game->player->py -= (game->player->pdy / 10);
		}
	}
	if (game->player->dy == -1)
	{
		mx = (int)(game->player->px + (game->player->pdx / 10)) / 64;
		my = (int)(game->player->py + (game->player->pdy / 10)) / 64;
		if (game->map[my * game->map_w + mx] != 1)
		{
			game->player->px += (game->player->pdx / 5);
			game->player->py += (game->player->pdy / 5);
		}
	}
	if (game->player->dx == 1)
	{
		game->player->pa += 0.02;
		if (game->player->pa > 2 * PI)
			game->player->pa -= 2 * PI;
		game->player->pdx = cos(game->player->pa) * 5;
		game->player->pdy = sin(game->player->pa) * 5;
	}
	if (game->player->dx == -1)
	{
		game->player->pa -= 0.02;
		if (game->player->pa < 0)
			game->player->pa += 2 * PI;
		game->player->pdx = cos(game->player->pa) * 5;
		game->player->pdy = sin(game->player->pa) * 5;
	}
}