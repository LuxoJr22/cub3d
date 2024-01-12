/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:11:40 by nstoutze          #+#    #+#             */
/*   Updated: 2024/01/12 19:55:20 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

static void	free_ints(int **dust)
{
	if (*dust)
	{
		free(*dust);
		*dust = NULL;
	}
}

static void	free_colors(t_xpm *xpm)
{
	t_colors	*colors_node;
	t_colors	*colors_node_next;

	colors_node = xpm->colors;
	while (colors_node)
	{
		colors_node_next = colors_node->next;
		free_chars(&(colors_node->symbol));
		free_chars(&(colors_node->color));
		free(colors_node);
		colors_node = colors_node_next;
	}
}

void	free_xpm(t_xpm *xpm)
{
	free_chars(&(xpm->carac_line));
	free_chars(&(xpm->filename));
	free_ntcharss(&(xpm->file_lbl));
	free_ints(&(xpm->img_ints));
	free_colors(xpm);
	if (xpm)
	{
		free(xpm);
		xpm = NULL;
	}
}
