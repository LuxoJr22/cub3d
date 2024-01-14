/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:36:37 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/14 15:02:46 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	test_text(t_game *game)
{
	int	fd;
	int	i;

	while (i < 4)
	{
		fd = open(game->name_texture[i], O_RDONLY);
		if (fd == -1)
		{
			printf("Error: %s doesn't exist\n", game->name_texture[i]);
			game->error = i + 1;
			exit_game(game);
		}
		close(fd);
		i ++;
	}
}

void	is_text_valid(t_game *game)
{
	if (game->north_xpm->valid == FALSE
		|| game->south_xpm->valid == FALSE
		|| game->east_xpm->valid == FALSE
		|| game->west_xpm->valid == FALSE)
	{
		exit_game_code(game, 0, "Error: texture is not valid\n");
	}
}

void	init_sprites(t_game *game)
{
	t_pos	pos;

	get_name_text(game);
	test_text(game);
	game->north_xpm = parsing_xpm(game->name_texture[0]);
	game->south_xpm = parsing_xpm(game->name_texture[1]);
	game->east_xpm = parsing_xpm(game->name_texture[2]);
	game->west_xpm = parsing_xpm(game->name_texture[3]);
	game->door_xpm = parsing_xpm("assets/door.xpm");
	is_text_valid(game);
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

t_game	*init_game(t_player *player, char *str)
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
	game->error = 0;
	get_map(game, str);
	game->frame = 0;
	return (game);
}
