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

int	get_color(char *str, t_game *game)
{
	char	**array;
	int		r;
	int		g;
	int		b;

	r = 256;
	g = 256;
	b = 256;
	array = ft_split(str, ",");
	if (array[0])
		r = ft_atoi(array[0]);
	if (r != 256 && array[1])
		g = ft_atoi(array[1]);
	if (g != 256 && array[2])
		b = ft_atoi(array[2]);
	free_dptr(array);
	if (r == 256 || g == 256 || b == 256)
		exit_game_code(game, 6, "Error: wrong color format\n");
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
	nb_ret = 0;
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
	game->map_h = nb_ret;
	game->map_w = len_max;
}

void	fill_g(t_game *game, int i, t_p index, char *str)
{
	if (str[i] == ' ')
		game->map[i + index.x] = 2;
	else if (str[i] == '0' || str[i] == '1')
		game->map[i + index.x] = str[i] - 48;
	else if (str[i] == 'D')
		game->map[i + index.x] = str[i];
	else
		game->map[i + index.x] = 0;
}

t_p	fill_map(t_game *game, char *str, int i, t_p index)
{
	int	is_end;

	is_end = 0;
	if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
		set_player_pos(game, (i + index.x - index.y * game->map_w),
			(i + index.x) / game->map_w, str[i]);
	if (str[i] != '\n')
		fill_g(game, i, index, str);
	else if (str[i] == '\n')
	{
		index.y ++;
		while (i + index.x + 1 < game->map_w * index.y)
		{
			is_end = 1;
			game->map[i + index.x] = 2;
			index.x ++;
		}
		game->map[i + index.x] = 2;
		if (is_end == 0)
			index.x --;
	}
	return (index);
}

void	create_map(t_game *game, char *str)
{
	int	i;
	t_p	index;
	int	len_max;

	index.x = 0;
	index.y = 0;
	len_max = 0;
	get_len_max(game, str);
	len_max = game->map_w;
	game->map = malloc(sizeof(int) * (game->map_h * game->map_w));
	i = 0;
	while (str[i])
	{
		index = fill_map(game, str, i, index);
		i ++;
	}
}
