/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:05:29 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/04 15:05:29 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

void	get_nb_lines(t_xpm *xpm)
{
	int		nb_lines;
	int		fd;
	char	*line;

	nb_lines = 0;
	fd = open(xpm->filename, O_RDONLY);
	if (fd == -1)
	{
		xpm->valid = FALSE;
		return ;
	}
	line = get_next_line(fd);
	while (line)
	{
		free_chars(&line);
		line = get_next_line(fd);
		nb_lines++;
	}
	close(fd);
	xpm->nb_lines = nb_lines;
	if (nb_lines > 3)
		xpm->valid = TRUE;
}
