/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:01:57 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/10 14:05:06 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	is_in_col(t_pos pos, t_col col)
{
	t_pos	ret;

	ret.x = 0;
	ret.y = 0;
	if (pos.x < col.xmin)
		ret.x = -1;
	if (pos.x > col.xmax)
		ret.x = 1;
	if (pos.y > col.ymax)
		ret.y = 1;
	if (pos.y < col.ymin)
		ret.y = -1;
	return (ret);
}

int	check_outcode(t_pos outcode0, t_pos outcode1)
{
	if (outcode0.x == 0 || outcode0.y == 0
		|| outcode1.x == 0 || outcode1.y == 0)
	{
		return (1);
	}
	if (outcode0.x == outcode1.x || outcode0.y == outcode1.y)
		return (0);
	return (-1);
}

int	hit_ennemies(t_game *game, t_col enn)
{
	t_pos	ps;
	t_pos	aim;
	t_pos	outcode0;
	t_pos	outcode1;
	t_pos	outcodeout;
	t_pos	p;

	ps.x = game->player->px;
	ps.y = game->player->py;
	aim = game->player->aim;
	outcode0 = is_in_col(game->player->aim, enn);
	outcode1 = is_in_col(ps, enn);
	while (check_outcode(outcode0, outcode1) == -1)
	{
		outcodeout = outcode1;
		if (outcode0.x != 0 || outcode0.y != 0)
			outcodeout = outcode0;
		if (outcodeout.x == 1)
		{
			p.x = aim.x + (ps.x - aim.x) * (enn.ymax - aim.y) / (ps.y - aim.y);
			p.y = enn.ymax;
		}
		else if (outcodeout.x == -1)
		{
			p.x = aim.x + (ps.x - aim.x) * (enn.ymin - aim.y) / (ps.y - aim.y);
			p.y = enn.ymin;
		}
		else if (outcodeout.y == 1)
		{
			p.y = aim.y + (ps.y - aim.y) * (enn.xmax - aim.x) / (ps.x - aim.x);
			p.x = enn.xmax;
		}
		else if (outcodeout.y == -1)
		{
			p.y = aim.y + (ps.y - aim.y) * (enn.xmin - aim.x) / (ps.x - aim.x);
			p.x = enn.xmin;
		}
		if (outcodeout.x == outcode0.x && outcodeout.y == outcode0.y)
		{
			aim.x = p.x;
			aim.y = p.y;
			outcode0 = is_in_col(aim, enn);
		}
		else
		{
			ps.x = p.x;
			ps.y = p.y;
			outcode1 = is_in_col(ps, enn);
		}
	}
	return (check_outcode(outcode0, outcode1));
}
