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

void raycaster2D(t_game *game, float ra)
{
	int mp, dof;
	float rx, ry, xo, yo, aTan, nTan;
	int vmt = 0;
	int hmt = 0;
	// Horizontal line
	dof = 0;
	float disH = 1000000, hx = game->player->px, hy = game->player->py;
	aTan= -1/tan(ra);
	if (ra > PI)
	{
		ry = (((int)game->player->py / 64) * 64) - 0.0001;
		rx = (game->player->py - ry) * aTan + game->player->px;
		yo = -64;
		xo = -yo * aTan;
	}
	if (ra < PI)
	{
		ry = ((int)game->player->py / 64) * 64 + 64;
		rx = (game->player->py - ry) * aTan + game->player->px;
		yo = 64;
		xo = -yo * aTan;
	}
	if (ra == 0 || (ra >= 3.1 && ra <= 3.2))
	{
		rx = game->player->px;
		ry = game->player->py;
		dof = 20;
	}
	while (dof < 20)
	{
		mp = (int)ry / 64 * game->map_w + (int)rx / 64;
		if (mp > 0 && mp < (game->map_w * game->map_h) && game->map[mp] == 1)
		{
			hmt = game->map[mp] - 1;
			hx = rx;
			hy = ry;
			disH = dist(game->player->px, game->player->py, hx, hy);
			dof = 20;
		}
		else
		{
			rx += xo;
			ry += yo;
			dof += 1;
		}
	}
	// Vertical line
	dof = 0;
	float disV= 1000000, vx = game->player->px, vy = game->player->py;
	nTan= -tan(ra);
	if (ra > P2 && ra < P3)
	{
		rx = (((int)game->player->px / 64) * 64) - 0.0001;
		ry = (game->player->px - rx) * nTan + game->player->py;
		xo = -64;
		yo = -xo * nTan;
	}
	if (ra < P2 || ra > P3)
	{
		rx = ((int)game->player->px / 64) * 64 + 64;
		ry = (game->player->px - rx) * nTan + game->player->py;
		xo = 64;
		yo = -xo * nTan;
	}
	if (ra == 0 || ra == PI)
	{
		rx = game->player->px;
		ry = game->player->py;
		dof = 20;
	}
	while (dof < 20)
	{
		mp = (int)ry / 64 * game->map_w + (int)rx / 64;
		if (mp > 0 && mp < (game->map_w * game->map_h) && game->map[mp] == 1)
		{
			vmt = game->map[mp] - 1;
			vx = rx;
			vy = ry;
			disV = dist(game->player->px, game->player->py, vx, vy);
			dof = 20;
		}
		else
		{
			rx += xo;
			ry += yo;
			dof += 1;
		}
	}
	game->raycast.dis.x = disH;
	game->raycast.dis.y = disV;
	game->raycast.hc.x = hx;
	game->raycast.hc.y = hy;
	game->raycast.vc.x = vx;
	game->raycast.vc.y = vy;
	game->raycast.mt.x = hmt;
	game->raycast.mt.y = vmt;
}





void raycaster3D(t_game *game)
{
	int nb_ray;
	float ra, disT;
	int hmt;
	int color;
	t_pos o;
	t_pos a;
	float shade;

	ra = check_angle(game->player->pa - DR * 30);
	nb_ray = 0;
	
	while (nb_ray < 480)
	{
		raycaster2D(game, ra);


		
		if (game->raycast.dis.x < game->raycast.dis.y)
		{
			a.x = game->raycast.hc.x;
			a.y = game->raycast.hc.y;
			disT = game->raycast.dis.x;
			shade = 0.5;
			color = 0x00FF0000;
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
			color = 0x00AA0000;
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

		//draw_line(game, o, a, color);

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
		o.y = 320 - lineH / 2;
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
			float c = game->textures[(int)(ty) * 32 + (int)tx] * shade;
			color = get_trgb(0, c * 255, c * 255, c * 255);
			i = 0;
			while (i < 2)
			{
				o.x = nb_ray * 2 + i;
				my_mlx_pixel_put(&game->frame1, o.x, o.y + y, color);
				i ++;
			}
			ty += ty_step;
			y ++;
		}
		ra = check_angle(ra + DR / 8);
		nb_ray ++;
	}
}