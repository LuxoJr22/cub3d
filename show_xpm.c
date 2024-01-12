/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:37:38 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/03 00:51:45 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	show_xpm(t_game *game, t_xpm *xpm, int x, int y)
{
	int	xi;
	int	yi;

	xi = 0;
	yi = 0;
	while (xi < xpm->width)
	{
		while (yi < xpm->height)
		{
			my_mlx_pixel_put(&game->frame1, x + xi, y + yi,
				xpm->img_ints[yi * xpm->width + xi]);
			yi ++;
		}
		yi = 0;
		xi ++;
	}
}
