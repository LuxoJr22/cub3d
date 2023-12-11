/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_xpm_width_height_nbcolors.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:11:41 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/09 22:32:21 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

static void	get_carac_line(t_xpm *xpm)
{
	int	i;

	i = -1;
	while (xpm->file_lbl[++i])
	{
		if (xpm->file_lbl[i][0] == '"')
		{
			xpm->carac_line = ft_strdup(xpm->file_lbl[i]);
			xpm->carac_line_index = i;
			return ;
		}
	}
}

static void	get_chr_between_dquotes(t_xpm *xpm)
{
	char	*temp;

	temp = ft_strdup(xpm->carac_line);
	free_chars(&(xpm->carac_line));
	xpm->carac_line = ft_substr((const char *)temp, 1, slen(temp) - 4);
	free_chars(&temp);
}

void	feed_xpm_width_height_nbcolors(t_xpm *xpm)
{
	char	**caracs;
	
	get_carac_line(xpm);
	get_chr_between_dquotes(xpm);
	caracs = ft_split(xpm->carac_line, " ");
	if (get_size_ntcharss(caracs) >= 3)
	{
		xpm->width = ft_atoi(caracs[0]);
		xpm->height = ft_atoi(caracs[1]);
		xpm->nb_colors = ft_atoi(caracs[2]);
	}
	if (xpm->nb_colors)
		xpm->colors = new_colors();
	free_ntcharss(&caracs);
}
