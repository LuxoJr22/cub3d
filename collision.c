/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:49:03 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/10 19:27:01 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_col	init_col(t_pos position, int scale)
{
	t_col	hitbox;

	hitbox.xmax = position.x + (scale / 2);
	hitbox.xmin = position.x - (scale / 2);
	hitbox.ymax = position.y + (scale / 2);
	hitbox.ymin = position.y - (scale / 2);
	return (hitbox);
}

int	collision(t_game *game, t_col hit1, t_col hit2)
{
	if ((hit1.xmin < hit2.xmax && hit1.ymax > hit2.ymin)
		&& (hit1.xmax > hit2.xmin && hit1.ymin < hit2.ymax))
		return (1);
	return (0);
}

void	collisions(t_game *game)
{
	t_ennemies	*ennemy;
	t_pos		pos;

	pos.x = game->player->px;
	pos.y = game->player->py;
	if (collision(game, game->player->col, game->sprite.col)
		&& game->sprite.active != 0)
	{
		game->player->coin ++;
		game->sprite.active = 0;
		//free_anims(game->sprite.anim);
	}
	ennemy = game->ennemies->next;
	while (ennemy)
	{
		if (collision(game, ennemy->col, game->player->col)
			&& game->player->time_hit == 0)
		{
			boost(game, get_angle(pos, ennemy->pos), 50, 0);
			game->player->is_hit = 1;
			game->player->health -= 5;
			game->player->time_hit = 100;
		}
		ennemy = ennemy->next;
	}
}
