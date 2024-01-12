/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_full_null_charss.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:06:59 by nstoutze          #+#    #+#             */
/*   Updated: 2024/01/12 02:57:10 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

char	**malloc_full_null_charss(int size)
{
	char	**array;
	int		i;

	array = NULL;
	i = -1;
	if (size)
	{
		array = malloc(sizeof(char *) * (size + 1));
		if (!array)
			return (NULL);
		while (++i <= size)
			array[i] = 0;
	}
	return (array);
}
