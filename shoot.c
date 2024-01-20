/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:01:57 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/19 13:26:54 by luxojr           ###   ########.fr       */
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

t_pos	get_p(t_pos outcodeout, t_pos aim, t_col enn, t_pos ps)
{
	t_pos	p;

	if (outcodeout.y == 1)
	{
		p.x = aim.x + (ps.x - aim.x) * (enn.ymax - aim.y) / (ps.y - aim.y);
		p.y = enn.ymax;
	}
	else if (outcodeout.y == -1)
	{
		p.x = aim.x + (ps.x - aim.x) * (enn.ymin - aim.y) / (ps.y - aim.y);
		p.y = enn.ymin;
	}
	else if (outcodeout.x == 1)
	{
		p.y = aim.y + (ps.y - aim.y) * (enn.xmax - aim.x) / (ps.x - aim.x);
		p.x = enn.xmax;
	}
	else if (outcodeout.x == -1)
	{
		p.y = aim.y + (ps.y - aim.y) * (enn.xmin - aim.x) / (ps.x - aim.x);
		p.x = enn.xmin;
	}
	return (p);
}

int	hit_ennemies(t_game *game, t_col enn, t_pos ps, t_pos aim)
{
	t_outcodes	outc;
	t_pos		outcodeout;
	t_pos		p;

	outc.o0 = is_in_col(game->player->aim, enn);
	outc.o1 = is_in_col(ps, enn);
	while (check_outcode(outc.o0, outc.o1) == -1)
	{
		outcodeout = outc.o1;
		if (outc.o0.x + outc.o0.y > outc.o1.x + outc.o1.y)
			outcodeout = outc.o0;
		p = get_p(outcodeout, aim, enn, ps);
		if (outcodeout.x == outc.o0.x && outcodeout.y == outc.o0.y)
		{
			aim = p;
			outc.o0 = is_in_col(aim, enn);
		}
		else
		{
			ps = p;
			outc.o1 = is_in_col(ps, enn);
		}
	}
	return (check_outcode(outc.o0, outc.o1));
}

void	regen_mana(t_game *game)
{
	if (game->frame % 60 == 0 && game->player->mana < game->player->manamax)
		game->player->mana ++;
}
