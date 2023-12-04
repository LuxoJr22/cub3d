/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:17:11 by nstoutze          #+#    #+#             */
/*   Updated: 2023/11/29 23:02:50 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	icis(char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (i);
	}
	return (i);
}

static void	janitor(char **dust)
{
	if (*dust)
	{
		free(*dust);
		*dust = NULL;
	}
}

static char	*read_fd(char *proto, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		nb_read_bytes;
	int		i;

	i = -1;
	while (++i <= BUFFER_SIZE)
		buffer[i] = '\0';
	nb_read_bytes = 1;
	while (!ft_strchr(buffer, '\n') && nb_read_bytes)
	{
		nb_read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nb_read_bytes == -1 || (!nb_read_bytes && !proto))
		{
			janitor(&proto);
			return (0);
		}
		buffer[nb_read_bytes] = '\0';
		if (proto)
			proto = ft_strjoin(proto, buffer);
		else
			proto = ft_strdup(buffer);
	}
	return (proto);
}

static char	*gen_line(int fd, char *proto, char **tank)
{
	char	*line;

	line = read_fd(proto, fd);
	proto = ft_strdup(line);
	janitor(&line);
	if (proto && ft_strchr(proto, '\n'))
	{
		line = cut(proto, 0, icis(proto, '\n') + 1);
		if (slen(line) != slen(proto))
		{
			*tank = cut(proto, icis(proto, '\n') + 1, slen(proto));
			janitor(&proto);
			return (line);
		}
		else
		{
			janitor(&line);
			return (proto);
		}
	}
	else if (proto)
		return (proto);
	return (0);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			*proto;
	static	char	*(tank[1024]);

	proto = NULL;
	if (!tank[fd])
		return (gen_line(fd, proto, &tank[fd]));
	else
	{
		if (ft_strchr(tank[fd], '\n'))
		{
			line = cut(tank[fd], 0, icis(tank[fd], '\n') + 1);
			proto = cut(tank[fd], icis(tank[fd], '\n') + 1, slen(tank[fd]));
			janitor(&(tank[fd]));
			tank[fd] = ft_strdup(proto);
			janitor(&proto);
			return (line);
		}
		else
		{
			proto = ft_strdup(tank[fd]);
			janitor(&(tank[fd]));
			return (gen_line(fd, proto, &(tank[fd])));
		}
	}
}
