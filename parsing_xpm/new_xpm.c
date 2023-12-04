/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:03:54 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/04 15:03:54 by nstoutze         ###   ########.fr       */
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
	return (new);
}
