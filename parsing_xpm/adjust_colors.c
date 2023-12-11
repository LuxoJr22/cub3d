/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:19:12 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/11 16:31:58 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

void	adjust_colors(t_xpm *xpm)
{
	//printf("adjust_colors : ENTREE\n");

	t_colors	*colors_node;
	char		*temp;

	colors_node = xpm->colors;
	temp = NULL;
	while (colors_node)
	{
		//printf("adjust_colors : nouvelle itération\n");
		if (ft_strlen(colors_node->symbol) == 1)
		{
			temp = ft_strdup(colors_node->symbol);
			free_chars(&(colors_node->symbol));
			colors_node->symbol = ft_strjoin(temp, " ");
			free_chars(&temp);
		}
		colors_node = colors_node->next;
	}
	//printf("adjust_colors : fin\n");
}
