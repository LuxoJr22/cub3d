/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_one_chars.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:25:12 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/04 15:25:12 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

static void	get_first_img_line_index(t_xpm *xpm)
{
	int	i;

	i = xpm->last_color_line_index;
	while (xpm->file_lbl[i])
	{
		if (xpm->file_lbl[i][0] == '"')
		{
			xpm->first_img_line_index = i;
			return ;
		}
		i++;
	}
}

void	get_img_one_chars(t_xpm *xpm)
{
	int	nb_pixels;
	int	i;
	int	j;

	nb_pixels = xpm->height * xpm->width;
	xpm->img_one_chars = (char *)malloc(sizeof(char) * (nb_pixels + 1));
	if (!(xpm->img_one_chars))
		return ;
	xpm->img_one_chars[nb_pixels] = '\0';
	get_first_img_line_index(xpm);
	i = 1;
	while (i <= xpm->height)
	{
		j = 1;
		while (j <= xpm->width)
		{
			xpm->img_one_chars[((i - 1) * xpm->height) + (j - 1)] = xpm->file_lbl[i + xpm->last_color_line_index][j];
			j++;
		}
		i++;
	}
}
