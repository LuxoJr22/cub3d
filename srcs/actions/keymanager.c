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

#include "../cub3d.h"

void	open_door(t_game *game, int keycode)
{
	int	mx;
	int	my;

	mx = (int)(game->player->px + ((game->player->pdx) * 4) * 2) / 64;
	my = (int)(game->player->py + ((game->player->pdy) * 4) * 2) / 64;
	if (game->map[my * game->map_w + mx] == 'D' && keycode == 101)
		game->map[my * game->map_w + mx] = 0;
}

int	key_manager(int keycode, t_game *game)
{
	if (game->scene == 1)
		game_input(game, keycode);
	if (game->scene == 0)
		menu_input(game, keycode);
	return (1);
}

int	relinput(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game);
	if (game->scene == 1)
		game_relinput(game, keycode);
	return (1);
}

int	button_mouse(int keycode, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (keycode == 1 && game->scene == 1 && game->player->mana >= 10)
	{
		shoot(game);
		game->player->mana -= 10;
	}
	return (0);
}

int	mouse_manager(int x, int y, t_game *game)
{
	game->mouse.act_pos.x = x;
	game->mouse.act_pos.y = y;
	return (1);
}
