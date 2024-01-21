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

#include "../cub3d.h"

int	get_color(char *str, t_game *game)
{
	char	**array;
	int		r;
	int		g;
	int		b;

	r = 257;
	g = 257;
	b = 257;
	array = ft_split(str, ",");
	if (array[0])
		r = ft_atoi(array[0]);
	if (r != 257 && array[1])
		g = ft_atoi(array[1]);
	if (g != 257 && array[2])
		b = ft_atoi(array[2]);
	free_dptr(array);
	if (r == 256 && g == 256 && b == 256)
	{
		game->is_ceiling = 1;
		return (0);
	}
	if (r >= 256 || g >= 256 || b >= 256 || r < 0 || g < 0 || b < 0)
		exit_game_code(game, 7, "Error: wrong color format\n");
	return (get_trgb(0, r, g, b));
}

void	fill_g(t_game *game, int i, t_p index, char *str)
{
	if (str[i] == ' ')
		game->map[i + index.x] = 2;
	else if (str[i] == '0' || str[i] == '1')
		game->map[i + index.x] = str[i] - 48;
	else if (str[i] == 'D' || str[i] == 'N' || str[i] == 'S'
		|| str[i] == 'W' || str[i] == 'E')
		game->map[i + index.x] = str[i];
	else
		game->map[i + index.x] = 0;
}

void	special_character(t_game *game, char *str, int i, t_p index)
{
	if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
		set_player_pos(game, (i + index.x - index.y * game->map_w),
			(i + index.x) / game->map_w, str[i]);
	if (str[i] == 'G')
		init_enemies(game, "assets/ghost/", 3, create_enn_pos((i + index.x
					- index.y * game->map_w), (i + index.x) / game->map_w));
	if (str[i] == 'C')
		init_sprite(game, create_enn_pos((i + index.x
					- index.y * game->map_w), (i + index.x) / game->map_w));
}

t_p	fill_map(t_game *game, char *str, int i, t_p index)
{
	int	is_end;

	is_end = 0;
	special_character(game, str, i, index);
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
		if (is_end == 1)
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

	index.x = 0;
	index.y = 0;
	if (!ft_is_in(str, '0') || !ft_is_in(str, '1'))
		exit_game_code(game, 7, "Error: wrong map format\n");
	get_len_max(game, str);
	game->map = malloc(sizeof(int) * (game->map_h * game->map_w));
	i = 0;
	while (str[i])
	{
		index = fill_map(game, str, i, index);
		i ++;
	}
}
