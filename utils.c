/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:56:21 by marvin            #+#    #+#             */
/*   Updated: 2023/04/21 15:56:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int dist(int x1, int y1, int x2, int y2)
{
	return (sqrt((x2 - x1) * (x2- x1) + (y2 - y1) * (y2 - y1)));
}

int	get_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

float check_angle(float a)
{
	if ( a < 0)
			a += 2 * PI;
		if ( a > 2 * PI)
			a -= 2 * PI;
	return (a);
}