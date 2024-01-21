/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:50:52 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/21 16:29:36 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	show_raycast(t_game *game, int lineHeight, int nb_ray, t_p tex)
{
	float	step;
	float	texpos;
	int		color;
	int		y;

	step = 1.0 * game->rcast.tsize.y / lineHeight;
	texpos = (game->rcast.draw.x - 640 / 2 + lineHeight / 2) * step;
	y = game->rcast.draw.x;
	while (y < game->rcast.draw.y)
	{
		tex.y = (int)texpos & (game->rcast.tsize.y - 1);
		texpos += step;
		color = game->textures[game->rcast.tsize.y * tex.y + 31 - tex.x
			+ 1024 * game->rcast.hmt];
		my_mlx_pixel_put(&game->frame1, 960 - nb_ray, y, effect_color(game,
				color));
		y ++;
	}
}

void	show_wall(t_game *game, int nb_ray, int lineHeight)
{
	int		texnum;
	t_p		tex;
	float	wallx;

	game->rcast.tsize.x = 32;
	game->rcast.tsize.y = 32;
	texnum = game->map[game->rcast.map.y * game->map_w + game->rcast.map.x];
	if (texnum == 'D')
		game->rcast.hmt = 4;
	if (game->rcast.side == 0)
		wallx = (game->player->py / 64) + game->rcast.perpwalldist
			* game->rcast.raydir.y;
	else
		wallx = (game->player->px / 64) + game->rcast.perpwalldist
			* game->rcast.raydir.x;
	wallx -= floor((wallx));
	tex.x = (int)(wallx * (float)(game->rcast.tsize.x));
	if (game->rcast.side == 0 && game->rcast.raydir.x > 0)
		tex.x = game->rcast.tsize.x - tex.x - 1;
	if (game->rcast.side == 1 && game->rcast.raydir.y < 0)
		tex.x = game->rcast.tsize.x - tex.x - 1;
	show_raycast(game, lineHeight, nb_ray, tex);
}

void	show_sprite(t_game *game, t_scast sc, t_p pos, t_anim *text)
{
	int	d;

	d = pos.y * 256 - 640 * 128 + sc.sprite_size.x * 128;
	sc.tex.y = ((d * text->height) / sc.sprite_size.x) / 256;
	if (text->text[text->width * sc.tex.y
			+ text->width - 1 - sc.tex.x] != 16711935)
		my_mlx_pixel_put(&game->frame1, 960 - pos.x, pos.y,
			effect_color(game, text->text[text->width * sc.tex.y
				+ text->width - 1 - sc.tex.x]));
}

void	drawsprites(t_game *game)
{
	t_ennemies	*ennemy;
	t_pos		pos;

	ennemy = game->ennemies->next;
	while (ennemy)
	{
		pos.x = ennemy->pos.x;
		pos.y = ennemy->pos.y;
		drawsprite(game, pos, ennemy->text);
		ennemy = ennemy->next;
	}
	pos.x = game->sprite.pos.x;
	pos.y = game->sprite.pos.y;
	if (game->sprite.active)
		drawsprite(game, pos, game->sprite.anim);
}
