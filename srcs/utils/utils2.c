/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:06:25 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/21 16:30:17 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "stdint.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pt;
	size_t	i;
	char	*s_bis;

	if (nmemb == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	pt = malloc(nmemb * size);
	if (!pt)
		return (NULL);
	i = -1;
	s_bis = pt;
	while (++i < nmemb * size)
	{
		s_bis[i] = '\0';
	}
	return (pt);
}

char	*ft_strjoin_f(char *s1, char *s2, int mode)
{
	char	*r_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	r_str = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!r_str)
		return (NULL);
	j = -1;
	i = -1;
	while (s1[++i])
		r_str[i] = s1[i];
	while (s2[++j])
		r_str[i++] = s2[j];
	r_str[i] = '\0';
	if (mode == 1 || mode == 3)
		free(s1);
	if (mode == 2 || mode == 3)
		free(s2);
	return (r_str);
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits / 8));
	*(unsigned int *)dst = color;
}

t_rgb	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char			*dst;
	unsigned int	ret;

	dst = data->addr + (y * data->line_length + x * (data->bits / 8));
	ret = *(unsigned int *)dst;
	return (get_colors(ret));
}
