/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:30:53 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/20 15:48:00 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_health(t_game *game)
{
	int	i;
	t_p	p;

	i = 0;
	p.x = 580;
	while (i < game->player->health / 2)
	{
		p.y = i * 40;
		show_img(game, game->health[2], p);
		i ++;
	}
	if (game->player->health % 2 == 1)
	{
		p.y = i * 40;
		show_img(game, game->health[1], p);
		i ++;
	}
	while (i * 2 < game->player->maxhealth)
	{
		p.y = i * 40;
		show_img(game, game->health[0], p);
		i ++;
	}
}

void	show_img_cut(t_game *game, t_xpm *xpm, t_p pos, t_p cut)
{
	t_p	p;

	p.x = 0;
	if (pos.x < 0)
		p.x = -1 * pos.x;
	if (pos.y < 0)
		p.y = -1 * pos.y;
	if (cut.y == -1)
		cut.y = pos.y + 960;
	if (cut.x == -1)
		cut.x = pos.x + 640;
	while (p.x < xpm->height && p.x + pos.x < 640 && p.x < cut.x)
	{
		p.y = 0;
		while (p.y < xpm->width && p.y + pos.y < 960 && p.y < cut.y)
		{
			if (xpm->img_ints[p.x * xpm->width + p.y] != 16711935)
				my_mlx_pixel_put(&game->frame1, p.y + pos.y,
					p.x + pos.x, xpm->img_ints[p.x * xpm->width + p.y]);
			p.y ++;
		}
		p.x ++;
	}
}

void	draw_mana(t_game *game)
{
	t_p	p;
	t_p	cut;
	int	width;

	p.x = 620;
	p.y = 5;
	width = game->mana[0]->width;
	cut.x = -1;
	cut.y = (((float)width / game->player->manamax) * game->player->mana);
	show_img(game, game->mana[1], p);
	show_img_cut(game, game->mana[0], p, cut);
}
