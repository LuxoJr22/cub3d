/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ntcharss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:01:15 by nstoutze          #+#    #+#             */
/*   Updated: 2024/01/12 19:59:01 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

void	free_ntcharss(char ***dust)
{
	int	i;

	i = 0;
	if (*dust)
	{
		while ((*dust)[i] != NULL)
		{
			free((*dust)[i]);
			(*dust)[i] = NULL;
			i++;
		}
		free(*dust);
		*dust = NULL;
	}
}
