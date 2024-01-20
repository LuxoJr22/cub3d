/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:33:17 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/20 15:33:51 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_error(t_game *game, t_p p, int act)
{
	if (act == 0 || act == 68 || act == 87 || act == 69
		|| act == 78 || act == 83)
	{
		if (p.x == 0 || p.y == 0
			|| p.x == game->map_h - 1 || p.y == game->map_w - 1)
			exit_game_code(game, 6, "Error: map is not closed\n");
		if (check_g(game, p.x + 1, p.y) || check_g (game, p.x - 1, p.y)
			|| check_g (game, p.x, p.y + 1)
			|| check_g (game, p.x, p.y - 1))
			exit_game_code(game, 6, "Error: map is not closed\n");
	}
}

void	exit_game_code(t_game *game, int i, char *str)
{
	printf("%s", str);
	if (i == 10)
		exit(1);
	game->error = i;
	exit_game(game);
}

int	exit_game(t_game *game)
{
	free(game->player);
	free_ennemies(game);
	free_forces(game);
	if (game->error != 7)
		free(game->map);
	mlx_destroy_image(game->mlx, game->frame1.img);
	mlx_destroy_image(game->mlx, game->frame2.img);
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->name_texture[0]);
	free(game->name_texture[1]);
	free(game->name_texture[2]);
	free(game->name_texture[3]);
	if (game->error == 0)
	{
		free_xpms(game);
		free(game->textures);
	}
	free(game->mlx);
	free(game);
	exit (1);
	return (1);
}
