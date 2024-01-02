/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colorsymbol_mode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:57:17 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/11 16:31:22 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

void	check_colorsymbol_mode(t_xpm *xpm)
{
	t_colors	*colors_node;

	colors_node = xpm->colors;
	while (colors_node)
	{
		if (ft_strlen(colors_node->symbol) == 2)
		{
			xpm->colorsymbol_mode = 2;
			return ;
		}
		colors_node = colors_node->next;
	}
}
