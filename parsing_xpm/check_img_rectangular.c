/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img_rectangular.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:34:13 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/11 16:31:57 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

void	check_img_rectangular(t_xpm *xpm)
{
	int	i;

	i = xpm->first_img_line_index;
	while (i < xpm->nb_lines)
	{
		if (xpm->file_lbl[i][0] == '"')
		{
			if (xpm_strlen(xpm->file_lbl[i]) != xpm->len_first_img_line)
			{
				xpm->rectangular = FALSE;
				break ;
			}
		}
		i++;
	}
}
