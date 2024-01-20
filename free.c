/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:17:09 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/19 13:45:12 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_dptr(char	**dptr)
{
	int	i;

	i = -1;
	while (dptr[++i])
	{
		free(dptr[i]);
	}
	free(dptr);
}

void	free_xpm_array(t_xpm **array, int size, int is_malloc)
{
	if (!array)
		return ;
	while (--size >= 0)
	{
		if (array[size])
		{
			free_xpm(array[size]);
			array[size] = NULL;
		}
	}
	if (is_malloc)
		free(array);
}

void	free_xpms(t_game *game)
{
	free_xpm(game->north_xpm);
	free_xpm(game->south_xpm);
	free_xpm(game->west_xpm);
	free_xpm(game->east_xpm);
	free_xpm(game->door_xpm);
	free_xpm(game->back);
	free_xpm_array(game->health, 3, 0);
	free_xpm_array(game->mana, 2, 0);
	free_xpm_array(game->alphabet, 26, 1);
	if (game->sprite.active)
		free_anims(game->sprite.anim);
}

void	free_ennemies(t_game *game)
{
	t_ennemies	*en;
	t_ennemies	*next;

	en = game->ennemies;
	next = game->ennemies->next;
	free(en);
	while (next)
	{
		en = next;
		next = en->next;
		free_anims(en->text);
		free(en);
	}
}

void	free_forces(t_game *game)
{
	t_dir_vec	*dir_v;
	t_dir_vec	*next;

	dir_v = game->dir_vec;
	next = game->dir_vec->next;
	free(dir_v);
	while (next)
	{
		dir_v = next;
		next = dir_v->next;
		free(dir_v);
	}
}
