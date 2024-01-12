/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:05:56 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/11 18:21:59 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*reset_str(char *str)
{
	char	*ret;

	free(str);
	ret = malloc(sizeof(char));
	ret[0] = '\0';
	return (ret);
}

char	*add_malloc(char *str, char buf)
{
	int		i;
	char	*str_ret;

	i = 0;
	while (str[i])
		i ++;
	str_ret = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (str[i])
	{
		str_ret[i] = str[i];
		i ++;
	}
	str_ret[i] = buf;
	str_ret[i + 1] = '\0';
	free(str);
	return (str_ret);
}

char	*get_character(t_game *game, char buf[2], char *str, int fd)
{
	if (buf[0] == 'C')
	{
		while (read(fd, buf, 1) && buf[0] != '\n')
			str = add_malloc(str, buf[0]);
		game->ceil_color = get_color(str);
	}
	if (buf[0] == 'F')
	{
		while (read(fd, buf, 1) && buf[0] != '\n')
			str = add_malloc(str, buf[0]);
		game->floor_color = get_color(str);
	}
	return (str);
}

void	get_map(t_game *game, char *name)
{
	int		fd;
	char	buf[2];
	char	*str;
	int		other;

	other = 0;
	str = malloc(sizeof(char));
	str[0] = '\0';
	fd = open(name, O_RDONLY);
	while (read(fd, buf, 1))
	{
		if (buf[0] == 'F' || buf[0] == 'C')
		{
			str = get_character(game, buf, str, fd);
			other ++;
			str = reset_str(str);
		}
		if ((buf[0] == ' ' || buf[0] == '1') && other == 2)
		{
			str = add_malloc(str, buf[0]);
			while (read(fd, buf, 1) && buf[0] != '\0')
				str = add_malloc(str, buf[0]);
			create_map(game, str);
			str = reset_str(str);
		}
	}
	free(str);
}
