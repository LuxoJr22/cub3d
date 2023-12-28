/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:52:47 by luxojr            #+#    #+#             */
/*   Updated: 2023/12/27 12:12:23 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_back(t_game *game)
{
	int	mx;
	int	my;

	mx = (int)(game->player->px - ((game->player->pdx) / 10) * 2) / 64;
	my = (int)(game->player->py - ((game->player->pdy) / 10) * 2) / 64;
	if (game->map[my * game->map_w + mx] == 0)
	{
		game->player->px -= ((game->player->pdx) / 5);
		game->player->py -= ((game->player->pdy) / 5);
	}
}

void	move_front(t_game *game)
{
	int	mx;
	int	my;

	mx = (int)(game->player->px + ((game->player->pdx) / 10) * 2) / 64;
	my = (int)(game->player->py + ((game->player->pdy) / 10) * 2) / 64;
	if (game->map[my * game->map_w + mx] == 0)
	{
		game->player->px += ((game->player->pdx) / 5) * game->player->sprint;
		game->player->py += ((game->player->pdy) / 5) * game->player->sprint;
	}
}

void	move_left(t_game *game)
{
	int		mx;
	int		my;
	float	pa;

	pa = game->player->pa + P2;
	pa = check_angle(pa);
	mx = (int)(game->player->px + ((cos(pa) * 5) / 10) * 2) / 64;
	my = (int)(game->player->py + ((sin(pa) * 5) / 10) * 2) / 64;
	if (game->map[my * game->map_w + mx] == 0)
	{
		game->player->px += ((cos(pa) * 5) / 5);
		game->player->py += ((sin(pa) * 5) / 5);
	}
}

void	move_right(t_game *game)
{
	int		mx;
	int		my;
	float	pa;

	pa = game->player->pa - P2;
	pa = check_angle(pa);
	mx = (int)(game->player->px + ((cos(pa) * 5) / 10) * 2) / 64;
	my = (int)(game->player->py + ((sin(pa) * 5) / 10) * 2) / 64;
	if (game->map[my * game->map_w + mx] == 0)
	{
		game->player->px += ((cos(pa) * 5) / 5);
		game->player->py += ((sin(pa) * 5) / 5);
	}
}
