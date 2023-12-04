/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ntcharss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:01:15 by nstoutze          #+#    #+#             */
/*   Updated: 2023/11/30 13:01:21 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

void	free_ntcharss(char ***dust)
{
	int	i;

	if (*dust && (*dust)[0])
	{
		i = -1;
		while ((*dust)[++i])
		{
			free((*dust)[i]);
			(*dust)[i] = NULL;
		}
		free(*dust);
	}
	*dust = NULL;
}
