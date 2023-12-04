/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:03:05 by luxojr            #+#    #+#             */
/*   Updated: 2023/11/29 12:03:05 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_back(t_game *game, t_pos start, t_pos length, int color)
{
	int	side;
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (i < length.x)
	{
		while (z < length.y)
		{
			my_mlx_pixel_put(&game->frame1, start.x + i, start.y + z, color);
			z ++;
		}
		i ++;
		z = 0;
	}
}
