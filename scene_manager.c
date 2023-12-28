/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:56:51 by luxojr            #+#    #+#             */
/*   Updated: 2023/12/28 13:54:16 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	display_raycast(game);
	if (game->map_active == 0)
		draw_minimap(game);
	else
		show_map(game);
	if (game->frame % 2 == 0)
		move(game);
	if (game->frame % 15 == 0)
		game->anim = game->anim->next;
	collision(game, game->player->col, game->sprite.col);
}

int	scene_manager(t_game *game)
{
	mlx_destroy_image(game->mlx, game->frame2.img);
	game->frame2 = game->frame1;
	game->frame1.img = mlx_new_image(game->mlx, 960, 640);
	game->frame1.addr = mlx_get_data_addr(game->frame1.img, &game->frame1.bits,
			&game->frame1.line_length, &game->frame1.endian);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->frame2.img, 0, 0);
	game_scene(game);
	game->frame ++;
	if (game->frame >= 60)
		game->frame = 0;
}
