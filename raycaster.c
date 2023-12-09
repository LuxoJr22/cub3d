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

void	cast_vertical_line(t_game *game, float ra, float Tan)
{
	int		mp;
	int		dof;
	t_pos	r;
	t_pos	o;

	dof = 0;
	game->raycast.vc.x = game->player->px;
	game->raycast.vc.y = game->player->py;
	if (ra > P2 && ra < P3)
	{
		r.x = (((int)game->player->px / 64) * 64) - 0.0001;
		r.y = (game->player->px - r.x) * Tan + game->player->py;
		o.x = -64;
		o.y = -o.x * Tan;
	}
	if (ra < P2 || ra > P3)
	{
		r.x = ((int)game->player->px / 64) * 64 + 64;
		r.y = (game->player->px - r.x) * Tan + game->player->py;
		o.x = 64;
		o.y = -o.x * Tan;
	}
	if (ra == 0 || ra == PI)
	{
		r.x = game->player->px;
		r.y = game->player->py;
		dof = 20;
	}
	while (dof < 20)
	{
		mp = (int)r.y / 64 * game->map_w + (int)r.x / 64;
		if (mp > 0 && mp < (game->map_w * game->map_h) && game->map[mp] == 1)
		{
			game->raycast.mt.y = game->map[mp] - 1;
			game->raycast.vc.x = r.x;
			game->raycast.vc.y = r.y;
			game->raycast.dis.y = dist(game->player->px, game->player->py, game->raycast.vc.x, game->raycast.vc.y);
			dof = 20;
		}
		else
		{
			r.x += o.x;
			r.y += o.y;
			dof += 1;
		}
	}
}

void	cast_horizontal_line(t_game *game, float ra, float Tan)
{
	int		mp;
	int		dof;
	t_pos	r;
	t_pos	o;

	dof = 0;
	game->raycast.hc.x = game->player->px;
	game->raycast.hc.y = game->player->py;
	if (ra > PI)
	{
		r.y = (((int)game->player->py / 64) * 64) - 0.0001;
		r.x = (game->player->py - r.y) * Tan + game->player->px;
		o.y = -64;
		o.x = -o.y * Tan;
	}
	if (ra < PI)
	{
		r.y = ((int)game->player->py / 64) * 64 + 64;
		r.x = (game->player->py - r.y) * Tan + game->player->px;
		o.y = 64;
		o.x = -o.y * Tan;
	}
	if (ra == 0 || (ra == PI))
	{
		r.x = game->player->px;
		r.y = game->player->py;
		dof = 20;
	}
	while (dof < 20)
	{
		mp = (int)r.y / 64 * game->map_w + (int)r.x / 64;
		if (mp > 0 && mp < (game->map_w * game->map_h) && game->map[mp] == 1)
		{
			game->raycast.mt.x = game->map[mp] - 1;
			game->raycast.hc.x = r.x;
			game->raycast.hc.y = r.y;
			game->raycast.dis.x = dist(game->player->px, game->player->py, game->raycast.hc.x, game->raycast.hc.y);
			dof = 20;
		}
		else
		{
			r.x += o.x;
			r.y += o.y;
			dof += 1;
		}
	}
}

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

void	display_raycast(t_game *game)
{
	int		nb_ray;
	float	ra, disT;
	int		hmt;
	t_pos	o;
	t_pos	a;
	float	shade;

	ra = check_angle(game->player->pa - DR * 30);
	nb_ray = 0;
	while (nb_ray < 480)
	{
		raycast(game, ra);
		if (game->raycast.dis.x < game->raycast.dis.y)
		{
			a.x = game->raycast.hc.x;
			a.y = game->raycast.hc.y;
			disT = game->raycast.dis.x;
			shade = 0.5;
			hmt = 1;
			if (ra > PI)
				hmt = 2;
		}
		else if (game->raycast.dis.y < game->raycast.dis.x || nb_ray < 1)
		{
			shade = 1;
			a.x = game->raycast.vc.x;
			a.y = game->raycast.vc.y;
			disT = game->raycast.dis.y;
			hmt = 0;
			if (ra > P2 && ra < P3)
				hmt = 3;
		}
		else
		{
			a.x = game->raycast.vc.x;
			a.y = game->raycast.vc.y;
			disT = game->raycast.dis.y;
		}
		o.x = game->player->px + 5;
		o.y = game->player->py + 5;
		float ca = check_angle(game->player->pa - ra);
		disT = disT * cos(ca);
		float lineH = (64*640) / disT;
		float ty_step = 32.0 /(float) lineH;
		float ty_off = 0;
		if (lineH > 640)
		{
			ty_off = (lineH - 640) / 2;
			lineH = 640;
		}
		o.y = 320 - lineH / 2 + (game->player->actheight - 1) * 100;
		int i;
		int y;
		float ty = ty_off * ty_step + hmt * 32;
		float tx;
		if (shade == 0.5)
		{
			tx = (int) (a.x / 2) % 32;
			if (ra < PI)
				tx = 31 - tx;
		}
		else 
		{
			tx = (int) (a.y / 2) % 32;
			if (ra < P3 && ra > P2)
				tx = 31 - tx;
		}
		y = 0;
		while (y < lineH)
		{
			i = 0;
			while (i < 2)
			{
				o.x = nb_ray * 2 + i;
				if (o.y + y < 640)
					my_mlx_pixel_put(&game->frame1, o.x, o.y + y, effect_color(game, game->textures[(int)(ty) * 32 + (int)tx]));
				i ++;
			}
			ty += ty_step;
			y ++;
		}
		ra = check_angle(ra + DR / 8);
		nb_ray ++;
	}
}
