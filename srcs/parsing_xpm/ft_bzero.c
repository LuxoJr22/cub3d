/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:55:54 by nstoutze          #+#    #+#             */
/*   Updated: 2023/11/30 12:56:04 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

void	ft_bzero(void *s, size_t n)
{
	if (!s)
		NULL;
	ft_memset(s, 0, (size_t)n);
}
