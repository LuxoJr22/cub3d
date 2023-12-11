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


/*
feeds :
	(t_colors *)colors_node->(char *)symbol
	(t_colors *)colors_node->(char *)color
*/
void	feed_colors_node(t_xpm *xpm, t_colors *colors_node, int i)
{
	char	**line_splitted;
	char	special_sep;
	
	if (i < xpm->nb_lines && slen(xpm->file_lbl[i]) > 2)
	{
		line_splitted = ft_split(xpm->file_lbl[i], " \t");
		if (get_size_ntcharss(line_splitted) == 4)
		{
			special_sep = line_splitted[1][0];
			colors_node->symbol = (char *)malloc(sizeof(char) * 3);
			colors_node->symbol[0] = ' ';
			colors_node->symbol[1] = special_sep;
			colors_node->symbol[2] = '\0';
			colors_node->color = ft_substr(line_splitted[3], 0, 7);
		}
		else
		{
			if (ft_strlen(line_splitted[0]) == 1)
				colors_node->symbol = ft_strdup("  ");
			else
				colors_node->symbol = ft_substr(line_splitted[0], 1, 2);
			colors_node->color = ft_substr(line_splitted[2], 0, 7);
		}
	}
	free_ntcharss(&line_splitted);
}


/*
feeds colors_node->(char *)symbol
feeds colors_node->(char *)color
*/
/*
void	feed_colors_node(t_xpm *xpm, t_colors *colors_node, int i)
{
	char	**line_splitted;
	
	if (i < xpm->nb_lines)
	{
		if (slen(xpm->file_lbl[i]) > 2)
			colors_node->symbol = xpm->file_lbl[i][1];
		line_splitted = ft_split(xpm->file_lbl[i], " ");
		if (get_size_ntcharss(line_splitted) >= 3)
			colors_node->color = ft_substr(line_splitted[2], 0, slen(line_splitted[2]) - 3);
	}
	free_ntcharss(&line_splitted);
}
*/
