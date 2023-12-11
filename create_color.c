/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:13:33 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/10 17:13:33 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_number(char c)
{
	int	i;

	if (c >= 'A')
		i = c - 'A' + 10;
	else
		i = c - '0';
	return (i);
}

int	create_color(char *str)
{
	int	r;
	int	g;
	int	b;

	r = get_number(str[1]) * 16 + get_number(str[2]);
	g = get_number(str[3]) * 16 + get_number(str[4]);
	b = get_number(str[5]) * 16 + get_number(str[6]);
	return (get_trgb(0, r, g, b));
}
