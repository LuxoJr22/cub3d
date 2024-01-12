/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_colors_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:23:50 by nstoutze          #+#    #+#             */
/*   Updated: 2024/01/11 18:03:23 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

void	add_colors_node(t_xpm *xpm, int i)
{
	t_colors	*colors_node;
	t_colors	*last;
	
	if (i == xpm->first_color_line_index)
		feed_colors_node(xpm, xpm->colors, i);
	else if (i > xpm->first_color_line_index)
	{
		colors_node = new_colors();
		feed_colors_node(xpm, colors_node, i);
		last = xpm->colors;
		while (last->next)
			last = last->next;
		last->next = NULL;
		last->next = colors_node;
		last->next->next = NULL;
	}
}
