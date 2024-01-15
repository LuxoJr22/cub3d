/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:05:56 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/15 10:02:53 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_character(t_game *game, char buf[2], char *str, int fd)
{
	if (buf[0] == 'C')
	{
		while (read(fd, buf, 1) && buf[0] != '\n')
			str = add_malloc(str, buf[0]);
		game->ceil_color = get_color(str, game);
	}
	if (buf[0] == 'F')
	{
		while (read(fd, buf, 1) && buf[0] != '\n')
			str = add_malloc(str, buf[0]);
		game->floor_color = get_color(str, game);
	}
	return (str);
}

char	*assign_name(t_game *game, int fd, int i, char *str)
{
	char	buf[2];

	while (read(fd, buf, 1) && buf[0] != '\n')
		str = add_malloc(str, buf[0]);
	free(game->name_texture[i]);
	game->name_texture[i] = ft_strdup(str);
	return (str);
}

char	*get_textures(t_game *game, char buf[2], char *str, int fd)
{
	char	c;
	int		i;

	c = buf[0];
	i = read(fd, buf, 1);
	if (c == 'N' && buf[0] == 'O')
		str = assign_name(game, fd, 0, str);
	else if (c == 'S' && buf[0] == 'O')
		str = assign_name(game, fd, 1, str);
	else if (c == 'E' && buf[0] == 'A')
		str = assign_name(game, fd, 2, str);
	else if (c == 'W' && buf[0] == 'E')
		str = assign_name(game, fd, 3, str);
	else
	{
		free(str);
		return (0);
	}
	return (str);
}

int	ft_is_in(char *str, char c)
{
	int	i;

	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

int	check_g(t_game *game, int x, int y)
{
	if (game->map[x * game->map_w + y] != 0
		&& game->map[x * game->map_w + y] != 1
		&& game->map[x * game->map_w + y] != 68)
		return (1);
	return (0);
}
