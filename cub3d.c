/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:02:59 by luxojr            #+#    #+#             */
/*   Updated: 2023/11/29 12:02:59 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_game(t_game *game)
{
	free(game->player);
	free_ennemies(game);
	free_forces(game);
	//free(game->map);
	free(game->textures);
	mlx_destroy_image(game->mlx, game->frame1.img);
	mlx_destroy_image(game->mlx, game->frame2.img);
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_xpms(game);
	free_anims(game->ennemies->next->text);
	free_anims(game->sprite.anim);
	free(game);
	exit (1);
	return (1);
}

int	*all_text(t_game *game)
{
	int		x;
	int		y;
	int		*tab;
	t_xpm	**text;

	text = malloc(sizeof(t_xpm) * 5);
	text[0] = game->north_xpm;
	text[1] = game->west_xpm;
	text[2] = game->south_xpm;
	text[3] = game->east_xpm;
	text[4] = game->door_xpm;
	tab = malloc(sizeof(int) * 5120);
	x = 0;
	while (x < 5)
	{
		y = -1;
		while (++y < 1024)
			tab[x * 1024 + y] = text[x]->img_ints[y];
		x ++;
	}
	/*free_xpm(text[0]);
	free_xpm(text[1]);
	free_xpm(text[2]);
	free_xpm(text[3]);*/
	//free_xpm(text[4]);
	free(text);
	return (tab);
}

int	leave(t_game *game)
{
	game->mouse.pos.x = 0;
	game->mouse.act_pos.x = 0;
	game->player->cm = 0;
}

int	main(void)
{
	t_game		*game;
	t_player	*player;
	void		*params;
	t_pos		pos;

	player = init_player();
	game = init_game(player);
	init_sprites(game);
	init_mouse(game);
	get_font(game, "assets/font/");
	game->plan.x = ret_abs(sin(game->player->pa)) * 0.66;
	game->plan.y = ret_abs(cos(game->player->pa)) * 0.66;
	pos.x = 28 * 64 + 32;
	pos.y = 3 * 64 + 32;
	init_enemies(game, "assets/gaper/", 9, pos);
	mlx_hook(game->mlx_win, 17, (1L << 0), exit_game, game);
	mlx_hook(game->mlx_win, 2, (1L << 0), key_manager, game);
	mlx_hook(game->mlx_win, 3, (1L << 1), relinput, game);
	mlx_hook(game->mlx_win, 4, (1L << 2), button_mouse, game);
	mlx_hook(game->mlx_win, 6, (1L << 6), mouse_manager, game);
	mlx_hook(game->mlx_win, 8, (1L << 5), leave, game);
	mlx_loop_hook(game->mlx, scene_manager, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}

// penser à virer fsanitize dans le Makefile