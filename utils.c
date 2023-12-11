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

int	dist(int x1, int y1, int x2, int y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
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

float	check_angle(float a)
{
	if (a < 0)
		a += 2 * PI;
	if (a > 2 * PI)
		a -= 2 * PI;
	return (a);
}

int	ft_strlen(char *str)
{
	int	len;

	len = -1;
	while (str[++len])
		;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;
	size_t	lens1;
	size_t	lens2;

	lens1 = slen(s1);
	lens2 = slen(s2);
	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	join = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!join)
		return (NULL);
	while (++i < lens1)
		join[i] = s1[i];
	while (++j < lens2)
		join[i + j] = s2[j];
	join[i + j] = '\0';
	return (join);
}