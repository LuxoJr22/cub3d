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

int	key_manager(int keycode, t_game *game)
{
	if (keycode == 65363)
		game->player->cm = 1;
	if (keycode == 65361)
		game->player->cm = -1;
	if (keycode == 100)
		game->player->dx += 1;
	if (keycode == 113)
		game->player->dx += -1;
	if (keycode == 115)
		game->player->dy += 1;
	if (keycode == 122)
		game->player->dy += -1;
	if (keycode == 65289)
		game->map_active = 1;
	return (1);
}

int	relinput(int keycode, t_game *game)
{
	if (keycode == 65363)
		game->player->cm = 0;
	if (keycode == 65361)
		game->player->cm = 0;
	if (keycode == 100)
		game->player->dx -= 1;
	if (keycode == 113)
		game->player->dx -= -1;
	if (keycode == 115)
		game->player->dy -= 1;
	if (keycode == 122)
		game->player->dy -= -1;
	if (keycode == 65289)
		game->map_active = 0;
	return (1);
}
