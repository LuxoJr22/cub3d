/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:58:35 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/04 17:06:00 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

t_xpm	*parsing_xpm(char *filename)
{
	t_xpm	*xpm;

	xpm = new_xpm(filename);
	get_nb_lines(xpm);
	feed_file_lbl(xpm);
	feed_xpm_width_height_nbcolors(xpm);
	if (xpm->nb_colors)
		build_colors_chained_list(xpm);
	get_img_one_chars(xpm);
	return (xpm);
}
