/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:03:18 by luxojr            #+#    #+#             */
/*   Updated: 2023/11/29 12:03:18 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_in(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i ++;
	}
	return (0);
}

int	get_color(char *str)
{
	char	**array;
	int		r;
	int		g;
	int		b;

	array = ft_split(str, ",");
	r = ft_atoi(array[0]);
	g = ft_atoi(array[1]);
	b = ft_atoi(array[2]);
	return (get_trgb(0, r, g, b));
}

void	get_len_max(t_game *game, char *str)
{
	int	len;
	int	len_max;
	int	i;
	int	nb_ret;

	i = 0;
	len = 0;
	len_max = 0;
	while (str[i])
	{
		len ++;
		if (str[i] == '\n')
		{
			if (len - 1 > len_max)
				len_max = len - 1;
			len = 0;
			nb_ret ++;
		}
		i ++;
	}
	game->map_h = nb_ret + 1;
	game->map_w = len_max;
}

t_p	fill_map(t_game *game, char *str, int i, t_p index)
{
	if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
		set_player_pos(game, (i - index.x - index.y * game->map_w),
			(i - index.x) / game->map_w, str[i]);
	if (str[i] != '\n')
	{
		if (str[i] == ' ')
			game->map[i - index.x] = 1;
		else
			game->map[i - index.x] = str[i] - 48;
	}
	else if (str[i] == '\n')
	{
		index.y ++;
		index.x ++;
		while (i - index.x + 1 != game->map_w * index.y)
		{
			game->map[i - index.x] = 1;
			index.x --;
		}
	}
	return (index);
}

void	create_map(t_game *game, char *str)
{
	int	i;
	t_p	index;
	int	len_max;

	index.x = 0;
	len_max = 0;
	get_len_max(game, str);
	len_max = game->map_w;
	game->map = malloc(sizeof(int) * ((game->map_h) * len_max) + 1);
	i = 0;
	index.y = 0;
	while (str[i])
	{
		index = fill_map(game, str, i, index);
		i ++;
	}
}
