/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:59:44 by luxojr            #+#    #+#             */
/*   Updated: 2023/12/11 21:22:35 by luxojr           ###   ########.fr       */
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
	player->actheight = 1;
	player->is_jump = 0;
	return (player);
}

t_game	*init_game(t_player *player)
{
	t_game		*game;
	int			imgw;
	int			imgh;

	game = malloc(sizeof(t_game));
	game->map_active = 0;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 960, 640, "Cub3d");
	game->player = player;
	game->img.img = mlx_new_image(game->mlx, 960, 640);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits,
			&game->img.line_length, &game->img.endian);
	game->frame1.img = mlx_new_image(game->mlx, 960, 640);
	game->frame1.addr = mlx_get_data_addr(game->frame1.img, &game->frame1.bits,
			&game->frame1.line_length, &game->frame1.endian);
	game->frame2.img = mlx_new_image(game->mlx, 960, 640);
	game->frame2.addr = mlx_get_data_addr(game->frame2.img, &game->frame2.bits,
			&game->frame2.line_length, &game->frame2.endian);
	game->map_h = 8;
	game->map_w = 8;
	get_map(game, "map.cub");
	game->frame = 0;
	return (game);
}

void	set_player_pos(t_game *game, int offx, int offy, char c)
{
	game->player->px = offx * 64 + 32;
	game->player->py = offy * 64 + 32;
	game->player->pdx = cos(game->player->pa) * 5;
	game->player->pdy = sin(game->player->pa) * 5;
	if (c == 'N')
		game->player->pa = P3;
	if (c == 'S')
		game->player->pa = P2;
	if (c == 'E')
		game->player->pa = 0;
	if (c == 'W')
		game->player->pa = PI;
}
