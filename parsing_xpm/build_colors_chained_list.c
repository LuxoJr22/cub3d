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

void	print_list(t_xpm *xpm)
{
	printf("\nNEW PRINT LIST\n");
	t_colors	*node = xpm->colors;
	while (node)
	{
		printf("node->symbol : %c ; node->color = %s\n", node->symbol, node->color);
		if (node->next)
			printf("node->next n'est pas null\n");
		else
			printf("node->next est null\n");
		node = node->next;
	}
	printf("END PRINT LIST\n");
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
		//print_list(xpm);
		i++;
	}
	xpm->last_color_line_index = i - 1;
}
