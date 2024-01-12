/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:59:44 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/11 14:44:32 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->px = 150;
	player->py = 400;
	player->pa = 0;
	player->pdx = cos(player->pa) * 5;
	player->pdy = sin(player->pa) * 5;
	player->cm = 0;
	player->sprint = 1;
	player->height = 1;
	player->dx = 0;
	player->dy = 0;
	player->actheight = 1;
	player->is_jump = 0;
	player->coin = 0;
	player->health = 10;
	player->is_hit = 0;
	player->time_hit = 0;
	return (player);
}

void	init_mouse(t_game *game)
{
	game->mouse.pos.x = 0;
	game->mouse.pos.y = 0;
	game->mouse.act_pos.x = 0;
	game->mouse.act_pos.y = 0;
}

void	init_enemies(t_game *game, char *name, int nb_sprites, t_pos pos)
{
	t_ennemies	*ennemy;
	t_ennemies	*next;

	ennemy = malloc(sizeof(t_ennemies));
	ennemy->next = 0;
	ennemy->text = get_anims(game, name, nb_sprites);
	ennemy->pos = pos;
	ennemy->col = init_col(pos, 10);
	ennemy->range = init_col(pos, 500);
	ennemy->health = 5;
	next = game->ennemies;
	while (next->next)
		next = next->next;
	next->next = ennemy;
}

void	set_player_pos(t_game *game, int offx, int offy, char c)
{
	game->player->px = offx * 64 + 32;
	game->player->py = offy * 64 + 32;
	if (c == 'N')
		game->player->pa = P3;
	if (c == 'S')
		game->player->pa = P2;
	if (c == 'E')
		game->player->pa = 0;
	if (c == 'W')
		game->player->pa = PI;
	game->player->pdx = cos(game->player->pa) * 5;
	game->player->pdy = sin(game->player->pa) * 5;
}
