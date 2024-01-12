/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_file_lbl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:08:17 by nstoutze          #+#    #+#             */
/*   Updated: 2024/01/12 02:58:01 by luxojr           ###   ########.fr       */
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
			//printf("line = %s", line); // à supprimer
			xpm->file_lbl[++i] = ft_strdup(line);
			free_chars(&line);
			line = get_next_line(fd);
		}
		xpm->file_lbl[++i] = ft_strdup(line);
		//xpm->file_lbl[++i] = 0;
		free(line);
		close(fd);
	}
}
