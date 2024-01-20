/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:56:51 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/15 17:04:21 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (game->scene == 0)
		menu_scene(game);
	if (game->scene == 1)
	{
		game_scene(game);
		if (game->player->health == 0 && game->transition == -1)
			game->transition = 10;
		start_transi(game, get_trgb(0, 100, 0, 0));
	}
	if (game->scene == 2)
		death_scene(game);
	game->frame ++;
	if (game->frame >= 60)
		game->frame = 0;
	return (0);
}
