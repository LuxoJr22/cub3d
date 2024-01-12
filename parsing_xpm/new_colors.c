/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:11:08 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/04 15:11:08 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

t_colors	*new_colors(void)
{
	t_colors	*new;

	new = (t_colors *)malloc(sizeof(t_colors));
	if (!new)
		return (NULL);
	new->color = NULL;
	new->next = NULL;
}
