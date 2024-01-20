/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:33:28 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/20 15:33:46 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map(t_game *game)
{
	t_p	p;
	int	act;
	int	is_player;

	is_player = 0;
	p.x = 0;
	while (p.x < game->map_h)
	{
		p.y = 0;
		while (p.y < game->map_w)
		{
			act = game->map[p.x * game->map_w + p.y];
			map_error(game, p, act);
			if (act == 87 || act == 69 || act == 78 || act == 83)
			{
				is_player += 1;
				game->map[p.x * game->map_w + p.y] = 0;
			}
			p.y ++;
		}
		p.x ++;
	}
	if (is_player != 1)
		exit_game_code(game, 6, "Error: map don't have any player\n");
}

char	*check_last(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	if (str[--i] != '\n')
		str = add_malloc(str, '\n');
	return (str);
}

char	*get_str_map(char *str, char buf[2], int fd)
{
	str = add_malloc(str, buf[0]);
	while (read(fd, buf, 1) && buf[0] != '\0')
		str = add_malloc(str, buf[0]);
	str = check_last(str);
	return (str);
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
		str = get_str_map(str, buf, fd);
		create_map(game, str);
		other ++;
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
	if (other != 7)
		exit_game_code(game, 7, "Error: wrong format file\n");
	check_map(game);
	free(str);
}
