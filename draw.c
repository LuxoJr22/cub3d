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
			if (start.y + z < 640)
				my_mlx_pixel_put(&game->frame1, start.x + i,
					start.y + z, color);
			z ++;
		}
		i ++;
		z = 0;
	}
}

void	draw_cube(t_game *game, int x, int y, int color)
{
	int	side;
	int	i;
	int	z;

	i = 0;
	z = 0;
	side = 16;
	while (i < side)
	{
		while (z < side)
		{
			my_mlx_pixel_put(&game->frame1, x + i, y + z, color);
			z ++;
		}
		i ++;
		z = 0;
	}
}

int	is_visible(t_game *game)
{
	float	x;
	float	y;
	int		sx;
	int		sy;

	x = game->sprite.pos.x - game->player->px;
	y = game->sprite.pos.y - game->player->py;
	sx = 1;
	sy = 1;
	if (x < 0)
	{
		x *= -1;
		sx = -1;
	}
	if (y < 0)
	{
		y *= -1;
		sy = -1;
	}
	if (y > x)
	{
		if (sy > 0)
			if (game->player->pa > 0 && game->player->pa < PI)
				return (1);
		if (sy < 0)
			if (game->player->pa > PI && game->player->pa < 2 * PI)
				return (1);
	}
	else
	{
		if (sx < 0)
			if (game->player->pa > P2 && game->player->pa < P3)
				return (1);
		if (sx > 0)
			if (game->player->pa > P3 || game->player->pa < P2)
				return (1);
	}
	return (0);
}

void	draw_sprite(t_game *game, t_fpos s, float depth[480], float b)
{
	t_p		p;
	int		scale;
	t_pos	t;
	t_pos	t_step;

	scale = 32 * 600 / b;
	t.x = 0;
	t_step.x = 32 / (float)scale;
	t_step.y = 32 / (float)scale;
	p.x = s.x - scale / 2;
	p.y = 0;
	while (p.x < s.x + scale / 2)
	{
		t.y = 31;
		while (p.y < scale)
		{
			if (p.x > 0 && p.x < 960 && s.y - p.y > 0 && s.y - p.y < 640
				&& is_visible(game) && b < depth[(int)(p.x / 2)]
				&& game->anim->text[(int)t.y * 32 + (int)t.x] != 16711935)
				my_mlx_pixel_put(&game->frame1, p.x, s.y - p.y,
					game->anim->text[(int)t.y * 32 + (int)t.x]);
			p.y ++;
			t.y -= t_step.y;
			if (t.y < 0)
				t.y = 0;
		}
		p.y = 0;
		p.x ++;
		t.x += t_step.x;
	}
}

void	draw_sprites(t_game *game, float depth[480])
{
	t_fpos	s;
	float	cs;
	float	sn;
	float	a;
	float	b;

	s.x = game->sprite.pos.x - game->player->px;
	s.y = game->sprite.pos.y - game->player->py;
	s.z = game->sprite.pos.z;
	cs = cos(game->player->pa * -1);
	sn = sin(game->player->pa * -1);
	a = s.y * cs + s.x * sn;
	b = s.x * cs - s.y * sn;
	s.x = a;
	s.y = b;
	s.x = (s.x * 864 / s.y) + (960 / 2);
	s.y = (s.z * 864 / s.y) + (640 / 2);
	draw_sprite(game, s, depth, b);
}
