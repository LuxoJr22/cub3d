/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colorsymbol_mode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:57:17 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/10 21:57:17 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

void	check_colorsymbol_mode(t_xpm *xpm)
{
	t_colors	*colors_node;

	colors_node = xpm->colors;
	while (colors_node)
	{
		printf("check_colorsymbol_mode : colors_node->symbol = %s ; colors_node->color = %s\n", colors_node->symbol, colors_node->color);
		if (ft_strlen(colors_node->symbol) == 2)
		{
			xpm->colorsymbol_mode = 2;
			return ;
		}
		colors_node = colors_node->next;
	}
}
