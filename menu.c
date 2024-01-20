/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:01:56 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/17 16:31:25 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_img(t_game *game, t_xpm *xpm, t_p pos)
{
	t_p	p;

	p.x = 0;
	if (pos.x < 0)
		p.x = -1 * pos.x;
	if (pos.y < 0)
		p.y = -1 * pos.y;
	while (p.x < xpm->height && p.x + pos.x < 640)
	{
		p.y = 0;
		while (p.y < xpm->width && p.y + pos.y < 960)
		{
			if (xpm->img_ints[p.x * xpm->width + p.y] != 16711935)
				my_mlx_pixel_put(&game->frame1, p.y + pos.y,
					p.x + pos.x, xpm->img_ints[p.x * xpm->width + p.y]);
			p.y ++;
		}
		p.x ++;
	}
}

void	menu_input(t_game *game, int keycode)
{
	if (keycode == 65293)
		game->scene = 1;
}

void	menu_scene(t_game *game)
{
	t_p	pos;

	pos = game->off;
	pos.y -= 640;
	show_img(game, game->back, pos);
	show_img(game, game->back, game->off);
	pos = game->off;
	pos.y += 640;
	show_img(game, game->back, pos);
	if (game->frame % 4 == 0)
		game->off.y ++;
	if (game->off.y == 640)
		game->off.y = 0;
}
