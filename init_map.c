/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:33:28 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/15 00:54:15 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(t_game *game)
{
	t_p	p;
	int	er;

	p.x = 0;
	er = 0;
	while (p.x < game->map_h)
	{
		p.y = 0;
		while (p.y < game->map_w)
		{
			if (game->map[p.x * game->map_w + p.y] == 0
				|| game->map[p.x * game->map_w + p.y] == 68)
			{
				if (p.x == 0 || p.y == 0
					|| p.x == game->map_h - 1 || p.y == game->map_w - 1)
					exit_game_code(game, 6, "Error: map is not closed\n");
				if (check_g(game, p.x + 1, p.y) || check_g (game, p.x - 1, p.y)
					|| check_g (game, p.x, p.y + 1)
					|| check_g (game, p.x, p.y - 1))
					exit_game_code(game, 6, "Error: map is not closed\n");
			}
			p.y ++;
		}
		p.x ++;
	}
}

int	loop_map(t_game *game, char buf[2], int fd, int other)
{
	char	*str;

	str = 0;
	str = reset_str(str);
	if (buf[0] == 'N' || buf[0] == 'E' || buf[0] == 'S' || buf[0] == 'W')
	{
		str = get_textures(game, buf, str, fd);
		if (str)
			other ++;
	}
	if (buf[0] == 'F' || buf[0] == 'C')
	{
		str = get_character(game, buf, str, fd);
		other ++;
	}
	if ((buf[0] == ' ' || buf[0] == '1') && other == 6)
	{
		str = add_malloc(str, buf[0]);
		while (read(fd, buf, 1) && buf[0] != '\0')
			str = add_malloc(str, buf[0]);
		create_map(game, str);
	}
	free(str);
	return (other);
}

void	get_map(t_game *game, char *name)
{
	int		fd;
	char	buf[2];
	char	*str;
	int		other;
	char	c;

	game->name_texture[0] = malloc(0);
	game->name_texture[1] = malloc(0);
	game->name_texture[2] = malloc(0);
	game->name_texture[3] = malloc(0);
	other = 0;
	str = malloc(sizeof(char));
	str[0] = '\0';
	fd = open(name, O_RDONLY);
	while (read(fd, buf, 1))
		other = loop_map(game, buf, fd, other);
	if (other != 6)
		exit_game_code(game, 7, "Error: wrong format file\n");
	check_map(game);
	free(str);
}
