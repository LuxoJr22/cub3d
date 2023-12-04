/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:03:40 by luxojr            #+#    #+#             */
/*   Updated: 2023/11/29 12:03:40 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int dist(int x1, int y1, int x2, int y2)
{
	return (sqrt((x2 - x1) * (x2- x1) + (y2 - y1) * (y2 - y1)));
}

int	get_trgb(int t, int r, int g, int b)
{
	if (t > 255)
		t = 255;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (t << 24 | r << 16 | g << 8 | b);
}

int add_trgb(int color1, int color2)
{
	int r;
	int g;
	int b;
	int r2;
	int g2;
	int b2;

	r = color1 >> 16;
	g = (color1 >> 8) - (r << 8);
	b = color1 - (g << 8) - (r << 16);
	r2 = color2 >> 16;
	g2 = (color2 >> 8) - (r2 << 8);
	b2 = color2 - (g2 << 8) - (r2 << 16);

	return (get_trgb(0, (r + r2) / 2, (g + g2) / 2, (b + b2) / 2));
}

int effect_color(t_game *game, int color)
{
	if (game->map_active)
		return (add_trgb(color, 0x00000000));
	else
		return (color);
}

float check_angle(float a)
{
	if ( a < 0)
			a += 2 * PI;
		if ( a > 2 * PI)
			a -= 2 * PI;
	return (a);
}