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

void	jump(t_game *game)
{
	if (game->player->height == 5)
		game->player->actheight += 0.05;
	if (game->player->height == 1)
		game->player->actheight -= 0.05;
	if (game->player->actheight >= 5)
		game->player->height = 1;
	if (game->player->actheight < 1)
	{
		game->player->actheight = 1;
		game->player->is_jump = 0;
	}
	printf("%f, %f\n", game->player->height, game->player->actheight);
}

void	move_camera(t_game *game)
{
	if (game->player->cm > 0)
	{
		game->player->pa += game->player->cm * 0.005;
		if (game->player->pa > 2 * PI)
			game->player->pa -= 2 * PI;
		game->player->pdx = cos(game->player->pa) * 5;
		game->player->pdy = sin(game->player->pa) * 5;
	}
	if (game->player->cm < 0)
	{
		game->player->pa += game->player->cm * 0.005;
		if (game->player->pa < 0)
			game->player->pa += 2 * PI;
		game->player->pdx = cos(game->player->pa) * 5;
		game->player->pdy = sin(game->player->pa) * 5;
	}
}

int	move(t_game *game)
{
	int		mx;
	int		my;
	float	pa;

	if (game->player->dx == 1)
		move_left(game);
	if (game->player->dx == -1)
		move_right(game);
	if (game->player->dy == 1)
		move_back(game);
	if (game->player->dy == -1)
		move_front(game);
	if (game->mouse.pos.x != 0 && game->mouse.pos.x != 960)
		game->player->cm = game->mouse.act_pos.x - game->mouse.pos.x;
	game->mouse.pos.x = game->mouse.act_pos.x;
	if (game->player->cm != 0)
		move_camera(game);
}
