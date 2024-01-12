/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_colors_chained_list.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:24:18 by nstoutze          #+#    #+#             */
/*   Updated: 2024/01/11 18:03:13 by luxojr           ###   ########.fr       */
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
