/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymanager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:03:10 by luxojr            #+#    #+#             */
/*   Updated: 2023/11/29 12:03:10 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_manager(int keycode, t_game *game)
{
	if (keycode == 100)
		game->player->dx = 1;
	if (keycode == 113)
		game->player->dx = -1;
	if (keycode == 115)
		game->player->dy = 1;
	if (keycode == 122)
		game->player->dy = -1;
	return (1);
}

int relinput(int keycode, t_game *game)
{
	if (keycode == 100)
		game->player->dx = 0;
	if (keycode == 113)
		game->player->dx = 0;
	if (keycode == 115)
		game->player->dy = 0;
	if (keycode == 122)
		game->player->dy = 0;
	return (1);
}

/*int key_manager(int keycode, t_game *game)
{
	if (keycode == 100)
	{
		//game->player->dx = 1;
		game->player->pa += 0.1;
		if (game->player->pa > 2 * PI)
			game->player->pa -= 2 * PI;
		game->player->pdx = cos(game->player->pa) * 20;
		game->player->pdy = sin(game->player->pa) * 20;
	}
	if (keycode == 113)
	{
		//game->player->dx = -1;
		game->player->pa -= 0.1;
		if (game->player->pa < 0)
			game->player->pa += 2 * PI;
		game->player->pdx = cos(game->player->pa) * 20;
		game->player->pdy = sin(game->player->pa) * 20;
	}
	if (keycode == 115)
	{
		game->player->dy = 1;
	}
	if (keycode == 122)
		game->player->dy = -1;
	return (1);
}

int relinput(int keycode, t_game *game)
{
	if (keycode == 100)
		game->player->dx = 0;
	if (keycode == 113)
		game->player->dx = 0;
	if (keycode == 115)
		game->player->dy = 0;
	if (keycode == 122)
		game->player->dy = 0;
	return (1);
}*/