/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:36:37 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/21 17:50:47 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	test_text(t_game *game)
{
	int	fd;
	int	i;

	i = 0;
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

void	init_sprite(t_game *game, t_pos pos)
{
	game->sprite.pos.x = pos.x;
	game->sprite.pos.y = pos.y;
	game->sprite.pos.z = 20;
	game->sprite.active = 1;
	pos.x = game->sprite.pos.x;
	pos.y = game->sprite.pos.y;
	game->sprite.col = init_col(pos, 10);
}

void	init_sprites(t_game *game)
{
	get_name_text(game);
	test_text(game);
	game->north_xpm = parsing_xpm(game->name_texture[0]);
	game->south_xpm = parsing_xpm(game->name_texture[1]);
	game->east_xpm = parsing_xpm(game->name_texture[2]);
	game->west_xpm = parsing_xpm(game->name_texture[3]);
	game->door_xpm = parsing_xpm("assets/door.xpm");
	game->back = parsing_xpm("assets/background/4.xpm");
	game->textures = all_text(game);
	if (game->sprite.active)
		game->sprite.anim = get_anims("assets/penny/", 5);
	game->health[0] = parsing_xpm("assets/health/empty.xpm");
	game->health[1] = parsing_xpm("assets/health/half.xpm");
	game->health[2] = parsing_xpm("assets/health/heart.xpm");
	game->mana[0] = parsing_xpm("assets/mana/mana.xpm");
	game->mana[1] = parsing_xpm("assets/mana/mana_empty.xpm");
	is_text_valid(game);
}

t_game	*init_game(t_player *player, char *str)
{
	t_game		*game;

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
	game->scene = 0;
	game->error = 0;
	game->is_ceiling = 0;
	game->off.x = 0;
	game->off.y = 0;
	game->sprite.active = 0;
	get_map(game, str);
	game->frame = 0;
	return (game);
}
