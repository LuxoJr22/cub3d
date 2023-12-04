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

char	**ft_split(char *str, char sep)
{
	int		i;
	int		start;
	int		nb_word;
	int		act_start;
	char	**ret;

	nb_word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == sep || str[i + 1] == '\0')
			nb_word ++;
		i ++;
	}
	ret = malloc(sizeof(char *) * (nb_word + 1));
	nb_word = 0;
	i = 0;
	start = 0;
	act_start = 0;
	while (str[i])
	{
		if (str[i + 1] == '\0' || str[i] == sep)
		{
			if (str[i + 1] == '\0')
				i ++;
			ret[nb_word] = malloc(sizeof(char) * (i - start + 1));
			while (start < i)
			{
				ret[nb_word][start - act_start] = str[start];
				start ++;
			}
			ret[nb_word][start - act_start] = '\0';
			start ++;
			act_start = start;
			nb_word ++;
		}
		i ++;
	}
	return (ret);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] == ' ')
		i ++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - 48;
	return (nb);
}

int	get_color(char *str)
{
	char	**array;
	int		r;
	int		g;
	int		b;

	array = ft_split(str, ',');
	r = ft_atoi(array[0]);
	g = ft_atoi(array[1]);
	b = ft_atoi(array[2]);
	return (get_trgb(0, r, g, b));
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

char	*reset_str(char *str)
{
	char	*ret;

	free(str);
	ret = malloc(sizeof(char));
	ret[0] = '\0';
	return (ret);
}

int	*create_map(t_game *game, char *str)
{
	int	*map;
	int	i;
	int	nb_ret;
	int	len_max;
	int	len;
	int	offset;
	int	offb;

	i = 0;
	offb = 0;
	len = 0;
	offset = 0;
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
	map = malloc(sizeof(int) * ((nb_ret + 1) * len_max) + 1);
	i = 0;
	nb_ret = 0;
	while (str[i])
	{
		if (str[i] == 'N')
		{
			game->player->px = (i - offset + offb - nb_ret * len_max) * 64 + 32;
			game->player->py = ((i - offset + offb) / len_max) * 64 + 32;
			game->player->pa = P3;
			game->player->pdx = cos(game->player->pa) * 5;
			game->player->pdy = sin(game->player->pa) * 5;
		}
		if (str[i] == 'S')
		{
			game->player->px = (i - offset + offb - nb_ret * len_max) * 64 + 32;
			game->player->py = ((i - offset + offb) / len_max) * 64 + 32;
			game->player->pa = P2;
			game->player->pdx = cos(game->player->pa) * 5;
			game->player->pdy = sin(game->player->pa) * 5;
		}
		if (str[i] == 'E')
		{
			game->player->px = (i - offset + offb - nb_ret * len_max) * 64 + 32;
			game->player->py = ((i - offset + offb) / len_max) * 64 + 32;
			game->player->pa = 0;
			game->player->pdx = cos(game->player->pa) * 5;
			game->player->pdy = sin(game->player->pa) * 5;
		}
		if (str[i] == 'W')
		{
			game->player->px = (i - offset + offb - nb_ret * len_max) * 64 + 32;
			game->player->py = ((i - offset + offb) / len_max) * 64 + 32;
			game->player->pa = PI;
			game->player->pdx = cos(game->player->pa) * 5;
			game->player->pdy = sin(game->player->pa) * 5;
		}
		if (str[i] != '\n')
		{
			if (str[i] == ' ')
				map[i - offset + offb] = 1;
			else
				map[i - offset + offb] = str[i] - 48;
		}
		else if (str[i] == '\n')
		{
			nb_ret ++;
			offset ++;
			while (i - offset + 1 + offb != len_max * nb_ret)
			{
				map[i - offset + offb] = 1;
				offb ++;
			}
		}
		i ++;
	}
	game->map_h = nb_ret + 1;
	game->map_w = len_max;
	len = 0;
	while (len < (game->map_h - 1) * game->map_w)
		len ++;
	return (map);
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
		if (buf[0] == 'C')
		{
			while (read(fd, buf, 1) && buf[0] != '\n')
				str = add_malloc(str, buf[0]);
			game->ceil_color = get_color(str);
			str = reset_str(str);
			other ++;
		}
		if (buf[0] == 'F')
		{
			while (read(fd, buf, 1) && buf[0] != '\n')
				str = add_malloc(str, buf[0]);
			game->floor_color = get_color(str);
			str = reset_str(str);
			other ++;
		}
		if ((buf[0] == ' ' || buf[0] == '1') && other == 2)
		{
			str = add_malloc(str, buf[0]);
			while (read(fd, buf, 1) && buf[0] != '\0')
				str = add_malloc(str, buf[0]);
			game->map = create_map(game, str);
			str = reset_str(str);
		}
	}
}
