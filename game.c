/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:04:39 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/18 00:18:54 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_anim(t_game *game)
{
	t_ennemies	*ennemy;

	if (game->sprite.active)
		game->sprite.anim = game->sprite.anim->next;
	ennemy = game->ennemies->next;
	while (ennemy)
	{
		ennemy->text = ennemy->text->next;
		ennemy = ennemy->next;
	}
}

void	game_input(t_game *game, int keycode)
{
	if (keycode == 32)
		boost(game, game->player->pa, 50, 0);
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
	if (keycode == 65505)
		game->player->sprint = 1.5;
	open_door(game, keycode);
}

void	game_relinput(t_game *game, int keycode)
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
	if (keycode == 65505)
		game->player->sprint = 1;
}

void	action_update(t_game *game)
{
	if (game->frame % 2 == 0)
	{
		move(game);
		apply_boost(game);
	}
	if (game->frame % 15 == 0)
		update_anim(game);
	regen_mana(game);
	collisions(game);
	update_ennemies(game);
	if (game->player->time_hit == 0)
		game->player->is_hit = 0;
	else
		game->player->time_hit --;
}

void	game_scene(t_game *game)
{
	t_pos	start;
	t_pos	length;
	t_pos	pos;

	start.x = 0;
	start.y = 0;
	length.x = 960;
	length.y = 320;
	pos.x = game->player->px;
	pos.y = game->player->py;
	game->player->col = init_col(pos, 10);
	draw_back(game, start, length, effect_color(game, game->ceil_color));
	start.y += length.y;
	draw_back(game, start, length, effect_color(game, game->floor_color));
	raycasting(game);
	draw_crossh(game);
	if (game->map_active == 0)
		draw_minimap(game);
	else
		show_map(game);
	if (game->player->health > 0)
		action_update(game);
}
