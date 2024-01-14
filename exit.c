/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:33:17 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/15 00:51:48 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
