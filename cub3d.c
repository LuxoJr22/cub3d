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

int	exit_game(int i)
{
	exit (1);
	return (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits / 8));
	*(unsigned int *)dst = color;
}

int	get_number(char c)
{
	int	i;

	if (c >= 'A')
	{
		i = c - 'A' + 10;
	}
	else
		i = c - '0';
	return (i);
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
	text[4] = parsing_xpm("assets/door.xpm");
	tab = malloc(sizeof(int) * 5120);
	x = 0;
	y = 0;
	while (x < 5)
	{
		while (y < 1024)
		{
			tab[x * 1024 + y] = text[x]->img_ints[y];
			y ++;
		}
		y = 0;
		x ++;
	}
	free (text);
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
	int			imgw;
	int			imgh;

	player = init_player();
	game = init_game(player);
	init_sprites(game);
	game->mouse.pos.x = 0;
	game->mouse.pos.y = 0;
	game->mouse.act_pos.x = 0;
	game->mouse.act_pos.y = 0;
	game->plan.x = ret_abs(sin(game->player->pa)) * 0.66;
	game->plan.y = ret_abs(cos(game->player->pa)) * 0.66;
	get_font(game, "assets/font/");
	mlx_hook(game->mlx_win, 17, (1L << 0), exit_game, params);
	mlx_hook(game->mlx_win, 2, (1L << 0), key_manager, game);
	mlx_hook(game->mlx_win, 3, (1L << 1), relinput, game);
	mlx_hook(game->mlx_win, 6, (1L << 6), mouse_manager, game);
	mlx_hook(game->mlx_win, 8, (1L << 5), leave, game);
	mlx_loop_hook(game->mlx, scene_manager, game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
