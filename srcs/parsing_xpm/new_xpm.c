/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:03:54 by nstoutze          #+#    #+#             */
/*   Updated: 2024/01/14 16:04:01 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

t_xpm	*new_xpm(char *filename)
{
	t_xpm	*new;

	new = (t_xpm *)malloc(sizeof(t_xpm));
	if (!new)
		return (NULL);
	new->file_lbl = NULL;
	new->filename = ft_strdup(filename);
	new->valid = FALSE;
	new->carac_line = NULL;
	new->colors = NULL;
	new->img_one_chars = NULL;
	new->img_ints = NULL;
	new->colorsymbol_mode = 1;
	new->rectangular = TRUE;
	new->nb_colors = 0;
	new->first_color_line_index = 0;
	new->last_color_line_index = 0;
	return (new);
}
