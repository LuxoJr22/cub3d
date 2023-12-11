/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:13:33 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/11 17:02:55 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_number(char c)
{
	int	i;

	if (c >= 'A')
		i = c - 'A' + 10;
	else
		i = c - '0';
	return (i);
}

int	create_color(char *str)
{
	int	r;
	int	g;
	int	b;

	r = get_number(str[1]) * 16 + get_number(str[2]);
	g = get_number(str[3]) * 16 + get_number(str[4]);
	b = get_number(str[5]) * 16 + get_number(str[6]);
	return (get_trgb(0, r, g, b));
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

int	add_trgb(int color1, int color2)
{
	t_rgb	c1;
	t_rgb	c2;

	c1.r = color1 >> 16;
	c1.g = (color1 >> 8) - (c1.r << 8);
	c1.b = color1 - (c1.g << 8) - (c1.r << 16);
	c2.r = color2 >> 16;
	c2.g = (color2 >> 8) - (c2.r << 8);
	c2.b = color2 - (c2.g << 8) - (c2.r << 16);
	return (get_trgb(0, (c1.r + c2.r) / 2, (c1.g + c2.g) / 2,
			(c1.b + c2.b) / 2));
}

int	effect_color(t_game *game, int color)
{
	if (game->map_active)
		return (add_trgb(color, 0x00000000));
	else
		return (color);
}
