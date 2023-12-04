/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_colors_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:58:34 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/04 15:58:34 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

void	feed_colors_node(t_xpm *xpm, t_colors *colors_node, int i)
{
	char	**line_splitted;
	
	if (i < xpm->nb_lines)
	{
		if (slen(xpm->file_lbl[i]) > 2)
			colors_node->symbol = xpm->file_lbl[i][1];
		line_splitted = ft_split(xpm->file_lbl[i], ' ');
		if (get_size_ntcharss(line_splitted) >= 3)
			colors_node->color = ft_substr(line_splitted[2], 0, slen(line_splitted[2]) - 3);
	}
	free_ntcharss(&line_splitted);
}
