/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_file_lbl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:08:17 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/04 15:08:17 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

void	feed_file_lbl(t_xpm *xpm)
{
	int		fd;
	char	*line;
	int		i;

	if (xpm->valid)
	{
		xpm->file_lbl = malloc_full_null_charss(xpm->nb_lines - 1);
		fd = open(xpm->filename, O_RDONLY);
		line = get_next_line(fd);
		i = -1;
		while (line)
		{
			xpm->file_lbl[++i] = ft_strdup(line);
			free_chars(&line);
			line = get_next_line(fd);
		}
		xpm->file_lbl[++i] = ft_strdup(line);
		free_chars(&line);
		close(fd);
	}
}
