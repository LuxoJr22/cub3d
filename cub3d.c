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

#include "srcs/cub3d.h"

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
	free(text);
	return (tab);
}

int	leave(t_game *game)
{
	game->mouse.pos.x = 0;
	game->mouse.act_pos.x = 0;
	game->player->cm = 0;
	return (0);
}

void	is_good_arg(char *name)
{
	int	i;
	int	fd;

	i = ft_strlen(name);
	if (i < 5)
		exit_game_code(0, 10, "Error: arguments is wrong format\n");
	if (name[i - 1] != 'b' || name[i - 2] != 'u'
		|| name[i - 3] != 'c' || name[i - 4] != '.')
		exit_game_code(0, 10, "Error: arguments is wrong format\n");
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: %s doesn't exist\n", name);
		exit(1);
	}
	close(fd);
}

void	mlx_hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 17, (1L << 0), exit_game, game);
	mlx_hook(game->mlx_win, 2, (1L << 0), key_manager, game);
	mlx_hook(game->mlx_win, 3, (1L << 1), relinput, game);
	mlx_hook(game->mlx_win, 4, (1L << 2), button_mouse, game);
	mlx_hook(game->mlx_win, 6, (1L << 6), mouse_manager, game);
	mlx_hook(game->mlx_win, 8, (1L << 5), leave, game);
	mlx_loop_hook(game->mlx, scene_manager, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game		*game;
	t_player	*player;

	if (argc != 2)
		exit_game_code(0, 10, "Error: not good amounts of argument\n");
	is_good_arg(argv[1]);
	player = init_player();
	game = init_game(player, argv[1]);
	init_sprites(game);
	init_mouse(game);
	get_font(game, "assets/font/");
	game->plan.x = sin(game->player->pa) * 0.66;
	game->plan.y = -1 * (cos(game->player->pa) * 0.66);
	mlx_hooks(game);
	return (EXIT_SUCCESS);
}
