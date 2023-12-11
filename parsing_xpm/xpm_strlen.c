/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 23:37:19 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/10 23:37:19 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

int	xpm_strlen(char *xpm_line)
{
	int	len;

	len = 1;
	while (xpm_line[len])
	{
		if (xpm_line[len] != '"')
			len++;
		else
			break ;
	}
	return (len - 1);
}
