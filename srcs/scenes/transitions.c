/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transitions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:54:29 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/21 16:29:48 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_newcolor(t_rgb last_col, t_rgb shade, int time)
{
	t_rgb	new;

	new.r = last_col.r + (shade.r - last_col.r) / time;
	new.g = last_col.g + (shade.g - last_col.g) / time;
	new.b = last_col.b + (shade.b - last_col.b) / time;
	return (get_trgb(0, new.r, new.g, new.b));
}

void	fade(t_game *game, int color)
{
	int		x;
	int		y;
	int		n_c;
	t_rgb	shade;	
	t_rgb	l_c;

	x = 0;
	shade = get_colors(color);
	while (x < 960)
	{
		y = 0;
		while (y < 640)
		{
			l_c = my_mlx_pixel_get(&game->frame1, x, y);
			n_c = get_newcolor(l_c, shade, game->transition);
			my_mlx_pixel_put(&game->frame1, x, y, n_c);
			y ++;
		}
		x ++;
	}
}

void	start_transi(t_game *game, int color)
{
	if (game->transition > 0)
	{
		fade(game, color);
		if (game->frame % 15 == 0)
			game->transition --;
	}
	else if (game->transition == 0)
		game->scene = 2;
}
