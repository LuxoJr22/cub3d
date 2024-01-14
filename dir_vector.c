/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:15:06 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/13 22:02:29 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	movement(t_game *game, float pa, int force, t_ennemies *enn)
{
	int		mx;
	int		my;

	pa = check_angle(pa);
	mx = (int)(game->player->px + ((cos(pa) * force) / 5)) / 64;
	my = (int)(game->player->py + ((sin(pa) * force) / 5)) / 64;
	if (enn)
	{
		mx = (int)(enn->pos.x + ((cos(pa) * force) / 10) * 15) / 64;
		my = (int)(enn->pos.y + ((cos(pa) * force) / 10) * 15) / 64;
	}
	if (game->map[my * game->map_w + mx] == 0)
	{
		if (enn == 0)
		{
			game->player->px += ((cos(pa) * force) / 5);
			game->player->py += ((sin(pa) * force) / 5);
		}
		else
		{
			enn->pos.x += ((cos(pa) * force) / 5);
			enn->pos.y += ((sin(pa) * force) / 5);
		}
	}
}

void	boost(t_game *game, float pa, int force, t_ennemies *enn)
{
	t_dir_vec	*new;
	t_dir_vec	*last;

	new = malloc(sizeof(t_dir_vec));
	new->enn = enn;
	new->next = 0;
	new->angle = pa;
	new->force = force;
	last = game->dir_vec;
	while (last->next)
		last = last->next;
	last->next = new;
}

float	get_angle(t_pos	subject, t_pos object)
{
	float	length;
	t_pos	vect;
	float	ang;

	vect.x = subject.x - object.x;
	vect.y = subject.y - object.y;
	length = sqrt(vect.x * vect.x + vect.y * vect.y);
	ang = acos(vect.x / length);
	if (vect.y < 0)
		ang = 2 * PI - ang;
	return (ang);
}

void	reset_boost(t_game *game)
{
	t_dir_vec	*last;
	t_dir_vec	*act;

	last = game->dir_vec;
	act = game->dir_vec->next;
	while (act)
	{
		if (act->force <= 0)
		{
			last->next = act->next;
			free(act);
			act = last->next;
		}
		else
		{
			last = last->next;
			act = act->next;
		}
	}
}

void	apply_boost(t_game *game)
{
	t_dir_vec	*last;

	reset_boost(game);
	last = game->dir_vec->next;
	while (last)
	{
		movement(game, last->angle, last->force, last->enn);
		last->force --;
		last = last->next;
	}
}
