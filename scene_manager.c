/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:56:51 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/12 14:04:23 by luxojr           ###   ########.fr       */
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

void	action_update(t_game *game)
{
	if (game->frame % 2 == 0)
	{
		move(game);
		apply_boost(game);
	}
	if (game->frame % 15 == 0)
		update_anim(game);
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

void	death_scene(t_game *game)
{
	t_pos	start;
	t_pos	end;

	start.x = 0;
	start.y = 0;
	end.x = 960;
	end.y = 640;
	draw_back(game, start, end, get_trgb(0, 100, 0, 0));
	show_str(game, 200, 320, "you died");
}

int	scene_manager(t_game *game)
{
	mlx_destroy_image(game->mlx, game->frame2.img);
	game->frame2 = game->frame1;
	game->frame1.img = mlx_new_image(game->mlx, 960, 640);
	game->frame1.addr = mlx_get_data_addr(game->frame1.img, &game->frame1.bits,
			&game->frame1.line_length, &game->frame1.endian);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->frame2.img, 0, 0);
	if (game->scene == 1)
	{
		game_scene(game);
		if (game->player->health == 0 && game->transition == -1)
			game->transition = 10;
		start_transi(game, get_trgb(0, 100, 0, 0));
	}
	if (game->scene == 0)
		death_scene(game);
	game->frame ++;
	if (game->frame >= 60)
		game->frame = 0;
}
