/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:58:35 by nstoutze          #+#    #+#             */
/*   Updated: 2024/01/11 18:04:08 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

t_xpm	*parsing_xpm(char *filename)
{
	t_xpm	*xpm;

	xpm = new_xpm(filename);
	get_nb_lines(xpm);
	if (xpm->valid)
	{
		feed_file_lbl(xpm);
		feed_xpm_width_height_nbcolors(xpm);
		if (xpm->nb_colors)
			build_colors_chained_list(xpm);
		check_colorsymbol_mode(xpm);
		if (xpm->colorsymbol_mode == 2)
			adjust_colors(xpm);
		get_first_img_line_index(xpm);
		check_img_rectangular(xpm);
		if (xpm->rectangular)
			build_img_ints(xpm);
		else
			xpm->valid = FALSE;
	}
	return (xpm);
}
