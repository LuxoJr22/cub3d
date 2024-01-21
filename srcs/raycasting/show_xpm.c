/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:37:38 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/21 16:29:34 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	show_floor(t_game *game, t_pos floor, t_pos floorstep, int y)
{
	t_p	cell;
	t_p	t;
	int	color;
	int	x;

	x = 0;
	while (x < 960)
	{
		cell.x = (int)(floor.x);
		cell.y = (int)(floor.y);
		t.x = (int)(32 * (floor.x - cell.x)) & (32 - 1);
		t.y = (int)(32 * (floor.y - cell.y)) & (32 - 1);
		floor.x += floorstep.x;
		floor.y += floorstep.y;
		color = game->north_xpm->img_ints[32 * t.y + t.x];
		my_mlx_pixel_put(&game->frame1, 960 - x, y, effect_color(game,
				color));
		color = game->north_xpm->img_ints[32 * t.y + t.x];
		my_mlx_pixel_put(&game->frame1, 960 - x, 640 - y - 1, effect_color(game,
				color));
		x ++;
	}
}

void	floor_cast(t_game *game, int y)
{
	t_pos	raydir0;
	t_pos	raydir1;
	t_pos	floorstep;
	t_pos	floor;
	float	rowdistance;

	raydir0.x = cos(game->player->pa) - game->plan.x;
	raydir0.y = sin(game->player->pa) - game->plan.y;
	raydir1.x = cos(game->player->pa) + game->plan.x;
	raydir1.y = sin(game->player->pa) + game->plan.y;
	rowdistance = (0.5 * 640) / (y - 640 / 2);
	floorstep.x = rowdistance * (raydir1.x - raydir0.x) / 960;
	floorstep.y = rowdistance * (raydir1.y - raydir0.y) / 960;
	floor.x = (game->player->px / 64) + rowdistance * raydir0.x;
	floor.y = (game->player->py / 64) + rowdistance * raydir0.y;
	show_floor(game, floor, floorstep, y);
}
