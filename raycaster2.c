/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:41:23 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/02 16:51:17 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ret_abs(float i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

t_pos get_deltadist(t_pos raydir)
{
	t_pos	deltadist;

	if (raydir.x == 0)
		deltadist.x = 1e30;
	else
		deltadist.x = ret_abs(1.0 / raydir.x);
	if (raydir.y == 0)
		deltadist.y = 1e30;
	else
		deltadist.y = ret_abs(1.0 / raydir.y);
	return (deltadist);
}

void get_sidedist(t_game *game, t_p map)
{
	if (game->rcast.raydir.x < 0)
    {
		game->rcast.step.x = -1;
		game->rcast.sideDist.x = ((game->player->px / 64) - map.x) * game->rcast.deltadist.x;
	}
	else
	{
		game->rcast.step.x = 1;
		game->rcast.sideDist.x = (map.x + 1.0 - (game->player->px / 64)) * game->rcast.deltadist.x;
	}
	if (game->rcast.raydir.y < 0)
	{
		game->rcast.step.y = -1;
		game->rcast.sideDist.y = ((game->player->py / 64) - map.y) * game->rcast.deltadist.y;
	}
	else
	{
		game->rcast.step.y = 1;
		game->rcast.sideDist.y = (map.y + 1.0 - (game->player->py / 64)) * game->rcast.deltadist.y;
	}
}

void	get_perpwalldist(t_game *game)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (game->rcast.sideDist.x < game->rcast.sideDist.y)
		{
			game->rcast.sideDist.x += game->rcast.deltadist.x;
			game->rcast.map.x += game->rcast.step.x;
			game->rcast.side = 0;
		}
		else
		{
			game->rcast.sideDist.y += game->rcast.deltadist.y;
			game->rcast.map.y += game->rcast.step.y;
			game->rcast.side = 1;
		}
		if (game->map[game->rcast.map.y * game->map_w + game->rcast.map.x] > 0)
			hit = 1;
	}
	if (game->rcast.side == 0)
	{
		game->rcast.perpwalldist = (game->rcast.sideDist.x - game->rcast.deltadist.x);
		game->rcast.hmt = 1;
		if (game->rcast.raydir.x > 0)
			game->rcast.hmt = 3;
	}
	else
	{
		game->rcast.perpwalldist = (game->rcast.sideDist.y - game->rcast.deltadist.y);
		game->rcast.hmt = 0;
		if (game->rcast.raydir.y > 0)
			game->rcast.hmt = 2;
	}
}

void	show_wall(t_game *game, int nb_ray, int lineHeight, t_p draw)
{
		int texNum;
		t_p texsize;
		t_p	tex;
		float wallX;
		float step;
		float texpos;
		int color;
		int	y;

		texsize.x = 32;
		texsize.y = 32;
		texNum = game->map[game->rcast.map.y * game->map_w + game->rcast.map.x];
		if (texNum == 'D')
			game->rcast.hmt = 4;
		if (game->rcast.side == 0)
			wallX = (game->player->py / 64) + game->rcast.perpwalldist * game->rcast.raydir.y;
		else
			wallX = (game->player->px / 64) + game->rcast.perpwalldist * game->rcast.raydir.x;
		wallX -= floor((wallX));
		tex.x = (int)(wallX * (float)(texsize.x));
		if (game->rcast.side == 0 && game->rcast.raydir.x > 0)
			tex.x = texsize.x - tex.x - 1;
		if (game->rcast.side == 1 && game->rcast.raydir.y < 0)
			tex.x = texsize.x - tex.x - 1;
		step = 1.0 * texsize.y / lineHeight;
      	texpos = (draw.x - 640 / 2 + lineHeight / 2) * step;
		y = draw.x;
      	while (y < draw.y)
      	{
        	tex.y = (int)texpos & (texsize.y - 1);
  			texpos += step;
  	    	color = game->textures[texsize.y * tex.y + 31 - tex.x + 1024 * game->rcast.hmt];
			my_mlx_pixel_put(&game->frame1, 960 - nb_ray, y, effect_color(game,
						color));
			y ++;
    	}
}

void	raycasting(t_game *game)
{
	int		nb_ray;
	float	depth[480];
	int		lineHeight;
	t_p		draw;
	t_p		m;

	nb_ray = 0;
	while (nb_ray < 960)
	{
		game->rcast.raydir.x = cos(game->player->pa) + game->plan.x * (((2 * nb_ray) / 960.0) - 1);
		game->rcast.raydir.y = sin(game->player->pa) + game->plan.y * (((2 * nb_ray) / 960.0) - 1);

		game->rcast.map.x = game->player->px / 64;
		game->rcast.map.y = game->player->py / 64;

		game->rcast.deltadist = get_deltadist(game->rcast.raydir);
		get_sidedist(game, game->rcast.map);
		get_perpwalldist(game);
		lineHeight = (int)(640 / game->rcast.perpwalldist);
		draw.x = -lineHeight / 2 + 640 / 2;
		if(draw.x < 0)
			draw.x = 0;
		draw.y = lineHeight / 2 + 640 / 2;
		if(draw.y >= 640)
			draw.y = 640 - 1;
		depth[nb_ray / 2] = ret_abs(lineHeight);
		show_wall(game, nb_ray, lineHeight, draw);
		nb_ray ++;
	}
	if (game->sprite.active)
		draw_sprites(game, depth);
	m.x = (int)(game->player->px + ((game->player->pdx * 2)) * 4) / 64;
	m.y = (int)(game->player->py + ((game->player->pdy * 2)) * 4) / 64;
	if (game->map[m.y * game->map_w + m.x] == 'D')
		show_str(game, 200 , 400, "press e to open the door");

}