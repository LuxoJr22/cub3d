/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:31:43 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/11 18:57:15 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_anims(t_anim *anim)
{
	t_anim	*first;
	t_anim	*next;

	first = anim;
	anim = anim->next;
	while (anim && anim != first)
	{
		free_xpm(anim->xpm);
		next = anim->next;
		free(anim);
		anim = next;
	}
	if (anim)
	{
		free_xpm(anim->xpm);
		free(anim);
	}
}

void	free_ennemy(t_game *game, t_ennemies *ennemy)
{
	t_dir_vec	*last;

	last = game->dir_vec->next;
	while (last)
	{
		if (last->enn == ennemy)
			last->force = 0;
		last = last->next;
	}
	//free_anims(ennemy->text);
	free(ennemy);
}

void	reset_ennemies(t_game *game)
{
	t_ennemies	*last;
	t_ennemies	*act;

	last = game->ennemies;
	act = game->ennemies->next;
	while (act)
	{
		if (act->health <= 0)
		{
			last->next = act->next;
			act = last->next;
			free_ennemy(game, act);
		}
		else
		{
			last = last->next;
			act = act->next;
		}
	}
}

void	move_ennemy(t_game *game, t_ennemies *ennemy)
{
	int	force;

	force = 1;
	if (collision(game, game->player->col, ennemy->range))
	{
		if (game->player->px > ennemy->pos.x)
			ennemy->pos.x += force;
		else if (game->player->px < ennemy->pos.x)
			ennemy->pos.x -= force;
		if (game->player->py > ennemy->pos.y)
			ennemy->pos.y += force;
		else if (game->player->py < ennemy->pos.y)
			ennemy->pos.y -= force;
	}
}

void	update_ennemies(t_game *game)
{
	t_ennemies	*ennemy;

	ennemy = game->ennemies->next;
	while (ennemy)
	{
		move_ennemy(game, ennemy);
		ennemy->col = init_col(ennemy->pos, 10);
		ennemy = ennemy->next;
	}
	reset_ennemies(game);
}
