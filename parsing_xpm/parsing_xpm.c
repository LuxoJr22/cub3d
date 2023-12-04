/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:58:35 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/04 15:31:28 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

void	parsing_xpm(char *filename)
{
	t_xpm	*xpm;

	xpm = new_xpm(filename);
	get_nb_lines(xpm);
	feed_file_lbl(xpm);
	feed_xpm_width_height_nbcolors(xpm);
	if (xpm->nb_colors)
		build_colors_chained_list(xpm);
	get_img_one_chars(xpm);
}
