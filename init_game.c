/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:36:37 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/12 17:04:23 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprites(t_game *game)
{
	t_pos	pos;

	game->north_xpm = parsing_xpm("assets/tree.xpm");
	game->south_xpm = parsing_xpm("assets/south.xpm");
	game->east_xpm = parsing_xpm("assets/east.xpm");
	game->west_xpm = parsing_xpm("assets/west.xpm");
	game->door_xpm = parsing_xpm("assets/door.xpm");
	game->textures = all_text(game);
	game->sprite.pos.x = 27 * 64 + 32;
	game->sprite.pos.y = 10 * 64 + 32;
	game->sprite.pos.z = 20;
	game->sprite.active = 1;
	pos.x = game->sprite.pos.x;
	pos.y = game->sprite.pos.y;
	game->sprite.col = init_col(pos, 10);
	game->sprite.anim = get_anims(game, "assets/penny/", 5);
}

void	init_frames(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, 960, 640);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits,
			&game->img.line_length, &game->img.endian);
	game->frame1.img = mlx_new_image(game->mlx, 960, 640);
	game->frame1.addr = mlx_get_data_addr(game->frame1.img, &game->frame1.bits,
			&game->frame1.line_length, &game->frame1.endian);
	game->frame2.img = mlx_new_image(game->mlx, 960, 640);
	game->frame2.addr = mlx_get_data_addr(game->frame2.img, &game->frame2.bits,
			&game->frame2.line_length, &game->frame2.endian);
}

t_game	*init_game(t_player *player)
{
	t_game		*game;
	int			imgw;
	int			imgh;

	game = malloc(sizeof(t_game));
	game->ennemies = malloc(sizeof(t_ennemies));
	game->ennemies->next = 0;
	game->dir_vec = malloc(sizeof(t_dir_vec));
	game->dir_vec->next = 0;
	game->map_active = 0;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 960, 640, "Cub3d");
	game->player = player;
	init_frames(game);
	game->map_h = 8;
	game->map_w = 8;
	game->transition = -1;
	game->scene = 1;
	get_map(game, "map.cub");
	game->frame = 0;
	return (game);
}
