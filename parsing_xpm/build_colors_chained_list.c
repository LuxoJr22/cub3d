/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_colors_chained_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:24:18 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/04 15:24:18 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

static void	get_first_color_line_index(t_xpm *xpm)
{
	int	i;

	i = xpm->carac_line_index;
	while (xpm->file_lbl[++i])
	{
		if (xpm->file_lbl[i][0] = '"')
		{
			xpm->first_color_line_index = i;
			return ;
		}
	}
}

static void	feed_colors_node(t_xpm *xpm, t_colors *colors_node, int i)
{
	char	**line_splitted;
	
	if (i < xpm->nb_lines)
	{
		if (slen(xpm->file_lbl[i]) > 2)
			colors_node->symbol = xpm->file_lbl[i][1];
		line_splitted = ft_split((const char *)xpm->file_lbl[i], ' ');
		if (get_size_ntcharss(line_splitted) >= 3)
			colors_node->color = ft_substr(line_splitted[2], 0, slen(line_splitted[2]) - 3);
	}
	free_ntcharss(&line_splitted);
}

static void	add_colors_node(t_xpm *xpm, int i)
{
	t_colors	*colors_node;
	t_colors	*last;
	
	if (i > xpm->first_color_line_index)
	{
		colors_node = new_colors();
		feed_colors_node(xpm, colors_node, i);
		last = xpm->colors;
		while (last->next)
			last = last->next;
		last->next = colors_node;
	}
	else
		feed_colors_node(xpm, xpm->colors, i);
}

void	build_colors_chained_list(t_xpm *xpm)
{
	int	i;
	int	j;
	
	get_first_color_line_index(xpm);
	i = xpm->first_color_line_index;
	j = -1;
	while (xpm->file_lbl[i] && ++j < xpm->nb_colors)
	{
		add_colors_node(xpm, i);
		i++;
	}
	xpm->last_color_line_index = i - 1;
}
