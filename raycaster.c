/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:41:23 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/15 00:41:54 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_scast	init_sc(t_game *game, t_scast sc, float inv_det, t_pos spos)
{
	sc.sprite.x = (spos.x / 64) - (game->player->px / 64);
	sc.sprite.y = (spos.y / 64) - (game->player->py / 64);
	inv_det = 1.0 / (game->plan.x * sin(game->player->pa)
			- cos(game->player->pa) * game->plan.y);
	sc.transform.x = inv_det * (sin(game->player->pa) * sc.sprite.x
			- cos(game->player->pa) * sc.sprite.y);
	sc.transform.y = inv_det * (-game->plan.y * sc.sprite.x
			+ game->plan.x * sc.sprite.y);
	sc.sprite_screenx = ((960 / 2) * (1 + sc.transform.x / sc.transform.y));
	sc.sprite_size.x = abs((int)(640 / (sc.transform.y)));
	sc.sprite_size.y = abs((int)(640 / (sc.transform.y)));
	sc.draw_start.y = -sc.sprite_size.x / 2 + 640 / 2;
	sc.draw_end.y = sc.sprite_size.x / 2 + 640 / 2;
	sc.draw_start.x = -sc.sprite_size.x / 2 + sc.sprite_screenx;
	sc.draw_end.x = sc.sprite_size.x / 2 + sc.sprite_screenx;
	if (sc.draw_start.y < 0)
		sc.draw_start.y = 0;
	if (sc.draw_end.y >= 640)
		sc.draw_end.y = 640 - 1;
	if (sc.draw_start.x < 0)
		sc.draw_start.x = 0;
	if (sc.draw_end.x >= 960)
		sc.draw_end.x = 960 - 1;
	return (sc);
}

void	drawsprite(t_game *game, t_pos spos, t_anim *text)
{
	float	inv_det;
	t_p		pos;
	int		d;
	t_scast	sc;

	sc = init_sc(game, sc, inv_det, spos);
	pos.x = sc.draw_start.x;
	while (pos.x < sc.draw_end.x)
	{
		sc.tex.x = (int)(256 * (pos.x - (-sc.sprite_size.x
						/ 2 + sc.sprite_screenx))
				* text->width / sc.sprite_size.x) / 256;
		if (sc.transform.y > 0 && pos.x > 0 && pos.x < 960
			&& sc.transform.y < game->rcast.depth[pos.x])
		{
			pos.y = sc.draw_start.y;
			while (pos.y < sc.draw_end.y)
			{
				show_sprite(game, sc, pos, text);
				pos.y ++;
			}
		}
		pos.x ++;
	}
}

void	raycaster(t_game *game, int nb_ray)
{
	int	lineheight;

	game->rcast.raydir.x = cos(game->player->pa) + game->plan.x
		* (((2 * nb_ray) / 960.0) - 1);
	game->rcast.raydir.y = sin(game->player->pa) + game->plan.y
		* (((2 * nb_ray) / 960.0) - 1);
	game->rcast.map.x = game->player->px / 64;
	game->rcast.map.y = game->player->py / 64;
	game->rcast.deltadist = get_deltadist(game->rcast.raydir);
	get_sidedist(game, game->rcast.map);
	get_perpwalldist(game);
	lineheight = (int)(640 / game->rcast.perpwalldist);
	game->rcast.draw.x = -lineheight / 2 + 640 / 2;
	if (game->rcast.draw.x < 0)
		game->rcast.draw.x = 0;
	game->rcast.draw.y = lineheight / 2 + 640 / 2;
	if (game->rcast.draw.y >= 640)
		game->rcast.draw.y = 640 - 1;
	game->rcast.depth[nb_ray] = game->rcast.perpwalldist;
	show_wall(game, nb_ray, lineheight);
}

void	raycasting(t_game *game)
{
	int		nb_ray;
	int		nb_h;
	int		lineheight;
	t_p		m;

	nb_ray = 0;
	nb_h = -1;
	while (game->is_ceiling && ++nb_h < 640)
		floor_cast(game, nb_h);
	while (nb_ray < 960)
	{
		raycaster(game, nb_ray);
		if (nb_ray == 480)
		{
			game->player->aim.x = game->rcast.map.x * 64;
			game->player->aim.y = game->rcast.map.y * 64;
		}
		nb_ray ++;
	}
	if (game->sprite.active || game->ennemies->next != 0)
		drawsprites(game);
	m.x = (int)(game->player->px + ((game->player->pdx * 2)) * 4) / 64;
	m.y = (int)(game->player->py + ((game->player->pdy * 2)) * 4) / 64;
	if (game->map[m.y * game->map_w + m.x] == 'D')
		show_str(game, 200, 400, "press e to open the door");
}
