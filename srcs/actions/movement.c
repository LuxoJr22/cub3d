/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:52:47 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/21 16:28:02 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_back(t_game *game)
{
	int	mxo;
	int	myo;
	int	mx;
	int	my;

	mxo = (int)(game->player->px - (game->player->pdx) / 5) / 64;
	myo = (int)(game->player->py - (game->player->pdy) / 5) / 64;
	mx = (int)game->player->px / 64;
	my = (int)game->player->py / 64;
	if (game->map[my * game->map_w + mxo] == 0)
		game->player->px -= ((game->player->pdx) / 5);
	if (game->map[myo * game->map_w + mx] == 0)
		game->player->py -= ((game->player->pdy) / 5);
}

void	move_front(t_game *game)
{
	int	mxo;
	int	myo;
	int	my;
	int	mx;

	mxo = (int)(game->player->px + ((game->player->pdx) / 5)
			* game->player->sprint) / 64;
	myo = (int)(game->player->py + ((game->player->pdy) / 5)
			* game->player->sprint) / 64;
	my = (int)game->player->py / 64;
	mx = (int)game->player->px / 64;
	if (game->map[my * game->map_w + mxo] == 0)
		game->player->px += ((game->player->pdx) / 5) * game->player->sprint;
	if (game->map[myo * game->map_w + mx] == 0)
		game->player->py += ((game->player->pdy) / 5) * game->player->sprint;
}

void	move_left(t_game *game)
{
	int		mx;
	int		my;
	int		mxo;
	int		myo;
	float	pa;

	pa = game->player->pa + P2;
	pa = check_angle(pa);
	mx = (int)game->player->px / 64;
	my = (int)game->player->py / 64;
	mxo = (int)(game->player->px + (cos(pa) * 5) / 5) / 64;
	myo = (int)(game->player->py + (sin(pa) * 5) / 5) / 64;
	if (game->map[my * game->map_w + mxo] == 0)
		game->player->px += ((cos(pa) * 5) / 5);
	if (game->map[myo * game->map_w + mx] == 0)
		game->player->py += ((sin(pa) * 5) / 5);
}

void	move_right(t_game *game)
{
	int		mx;
	int		my;
	int		mxo;
	int		myo;
	float	pa;

	pa = game->player->pa - P2;
	pa = check_angle(pa);
	mx = (int)game->player->px / 64;
	my = (int)game->player->py / 64;
	mxo = (int)(game->player->px + (cos(pa) * 5) / 5) / 64;
	myo = (int)(game->player->py + (sin(pa) * 5) / 5) / 64;
	if (game->map[my * game->map_w + mxo] == 0)
		game->player->px += ((cos(pa) * 5) / 5);
	if (game->map[myo * game->map_w + mx] == 0)
		game->player->py += ((sin(pa) * 5) / 5);
}
