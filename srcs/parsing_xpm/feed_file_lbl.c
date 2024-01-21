/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_file_lbl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:08:17 by nstoutze          #+#    #+#             */
/*   Updated: 2024/01/12 20:18:41 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

int	init_file_lbl(t_xpm *xpm)
{
	int	fd;

	xpm->file_lbl = malloc_full_null_charss(xpm->nb_lines);
	if (xpm->file_lbl == NULL)
		return (-1);
	fd = open(xpm->filename, O_RDONLY);
	if (fd == -1)
	{
		free(xpm->file_lbl);
		xpm->file_lbl = NULL;
	}
	return (fd);
}

void	read_lines_to_file_lbl(int fd, char ***file_lbl, int nb_lines)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line && i < nb_lines)
	{
		(*file_lbl)[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (i < nb_lines)
		(*file_lbl)[i] = NULL;
}

void	feed_file_lbl(t_xpm *xpm)
{
	int	fd;

	if (!xpm->valid)
		return ;
	fd = init_file_lbl(xpm);
	if (fd == -1)
		return ;
	read_lines_to_file_lbl(fd, &xpm->file_lbl, xpm->nb_lines);
	close(fd);
}
