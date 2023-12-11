/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_img_line_index.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:08:49 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/10 23:08:49 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

void	get_first_img_line_index(t_xpm *xpm)
{
	int	i;
	int	len_line;

	i = xpm->last_color_line_index;
	while (xpm->file_lbl[i])
	{
		len_line = ft_strlen(xpm->file_lbl[i]);
		if (xpm->file_lbl[i][0] == '"'
			&& len_line >= (xpm->width)
			&& xpm->file_lbl[i][len_line - 4] == '"')
		{
			xpm->first_img_line_index = i;
			break ;
		}
		i++;
	}
	//printf("get_first_img_line_index : xpm->file_lbl = %s", xpm->file_lbl[i]);
	xpm->len_first_img_line = xpm_strlen(xpm->file_lbl[i]);
}
