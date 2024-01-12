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

/*void	display_wall(t_game *game, int nb_ray, t_pos l, t_pos t)
{
	t_pos	o;
	int		y;
	int		i;

	y = 0;
	o.x = game->player->px + 5;
	o.y = 320 - l.x / 2 + (game->player->actheight - 1) * 100;
	while (y < l.x)
	{
		i = 0;
		while (i < 2)
		{
			o.x = nb_ray * 2 + i;
			if (o.y + y < 640)
				my_mlx_pixel_put(&game->frame1, o.x, o.y + y, effect_color(game,
						game->textures[(int)t.y * 32 + (int)t.x]));
			i ++;
		}
		t.y += l.y;
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

void	height_wall(t_game *game, float ra, int nb_ray, t_dist dis)
{
	t_pos	t;
	t_pos	l;
	float	lineh;
	float	ty_step;
	float	ty_off;

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
	if (game->raycast.hmt != 0)
		dis.hmt = 4;
	t.y = ty_off * ty_step + dis.hmt * 32;
	l.x = lineh;
	l.y = ty_step;
	display_wall(game, nb_ray, l, t);
}

t_dist	get_dist(t_game *game, float ra, int nb_ray, t_dist dis)
{
	if (game->raycast.dis.x < game->raycast.dis.y)
	{
		dis.a.x = game->raycast.hc.x;
		dis.a.y = game->raycast.hc.y;
		dis.dist = game->raycast.dis.x;
		game->raycast.hmt = game->raycast.mt.x;
		dis.hmt = 1;
		if (ra > PI)
			dis.hmt = 2;
	}
	else if (game->raycast.dis.y < game->raycast.dis.x || nb_ray < 1)
	{
		dis.a.x = game->raycast.vc.x;
		dis.a.y = game->raycast.vc.y;
		dis.dist = game->raycast.dis.y;
		game->raycast.hmt = game->raycast.mt.y;
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
	return (dis);
}

void	display_raycast(t_game *game)
{
	int		nb_ray;
	float	ra;
	t_dist	dis;
	float	depth[480];
	t_p		m;

	ra = check_angle(game->player->pa - DR * 30);
	nb_ray = 0;
	while (nb_ray < 480)
	{
		raycast(game, ra);
		dis = get_dist(game, ra, nb_ray, dis);
		depth[nb_ray] = dis.dist;
		//height_wall(game, ra, nb_ray, dis);
		ra = check_angle(ra + (DR / 8));
		nb_ray ++;
	}
	printf("1 : %f\n", depth[180]);
	if (game->sprite.active)
		draw_sprites(game, depth);
	m.x = (int)(game->player->px + ((game->player->pdx * 2)) * 4) / 64;
	m.y = (int)(game->player->py + ((game->player->pdy * 2)) * 4) / 64;
	if (game->map[m.y * game->map_w + m.x] == 'D')
		show_str(game, 200, 400, "press e to open the door");
}
*/