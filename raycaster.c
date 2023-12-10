/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:03:34 by luxojr            #+#    #+#             */
/*   Updated: 2023/11/29 12:03:34 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast(t_game *game, float ra)
{
	int		mp;
	int		dof;
	t_pos	r;
	t_pos	o;

	game->raycast.mt.y = 0;
	game->raycast.mt.x = 0;
	game->raycast.dis.x = 1000000;
	game->raycast.dis.y = 1000000;
	cast_horizontal_line(game, ra, -1 / tan(ra));
	cast_vertical_line(game, ra, -tan(ra));
}

void	display_wall(t_game *game, int nb_ray, float lineH, t_pos t, float ty_step)
{
	t_pos	o;
	int		y;
	int		i;

	y = 0;
	o.x = game->player->px + 5;
	o.y = 320 - lineH / 2 + (game->player->actheight - 1) * 100;
	while (y < lineH)
	{
		i = 0;
		while (i < 2)
		{
			o.x = nb_ray * 2 + i;
			if (o.y + y < 640)
				my_mlx_pixel_put(&game->frame1, o.x, o.y + y, effect_color(game, game->textures[(int)t.y * 32 + (int)t.x]));
			i ++;
		}
		t.y += ty_step;
		y ++;
	}
}

t_pos	get_direction_text(t_game *game, t_pos a, float ra)
{
	t_pos	t;

	if (game->raycast.dis.x < game->raycast.dis.y)
	{
		t.x = (int)(a.x / 2) % 32;
		if (ra < PI)
			t.x = 31 - t.x;
	}
	else
	{
		t.x = (int)(a.y / 2) % 32;
		if (ra < P3 && ra > P2)
			t.x = 31 - t.x;
	}
	return (t);
}

void	display_raycast(t_game *game)
{
	int		nb_ray;
	float	ra;
	float	ty_off;
	float	ty_step;
	float	lineh;
	t_dist	dis;
	t_pos	t;

	ra = check_angle(game->player->pa - DR * 30);
	nb_ray = 0;
	while (nb_ray < 480)
	{
		raycast(game, ra);
		if (game->raycast.dis.x < game->raycast.dis.y)
		{
			dis.a.x = game->raycast.hc.x;
			dis.a.y = game->raycast.hc.y;
			dis.dist = game->raycast.dis.x;
			dis.hmt = 1;
			if (ra > PI)
				dis.hmt = 2;
		}
		else if (game->raycast.dis.y < game->raycast.dis.x || nb_ray < 1)
		{
			dis.a.x = game->raycast.vc.x;
			dis.a.y = game->raycast.vc.y;
			dis.dist = game->raycast.dis.y;
			dis.hmt = 0;
			if (ra > P2 && ra < P3)
				dis.hmt = 3;
		}
		else
		{
			dis.a.x = game->raycast.vc.x;
			dis.a.y = game->raycast.vc.y;
			dis.dist = game->raycast.dis.y;
		}
		t = get_direction_text(game, dis.a, ra);
		dis.dist = dis.dist * cos(check_angle(game->player->pa - ra));
		lineh = (64 * 640) / dis.dist;
		ty_step = 32.0 / (float)lineh;
		ty_off = 0;
		if (lineh > 640)
		{
			ty_off = (lineh - 640) / 2;
			lineh = 640;
		}
		t.y = ty_off * ty_step + dis.hmt * 32;
		display_wall(game, nb_ray, lineh, t, ty_step);
		ra = check_angle(ra + DR / 8);
		nb_ray ++;
	}
}
