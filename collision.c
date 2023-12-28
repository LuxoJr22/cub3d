/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:49:03 by luxojr            #+#    #+#             */
/*   Updated: 2023/12/28 13:55:10 by luxojr           ###   ########.fr       */
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
	{
		game->player->coin ++;
		game->sprite.active = 0;
	}
}
