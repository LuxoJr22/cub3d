/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img_rectangular.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:34:13 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/10 22:34:13 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

void	check_img_rectangular(t_xpm *xpm)
{
	printf("check_img_rectangular : xpm->len_first_img_line = %d\n", xpm->len_first_img_line);
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
