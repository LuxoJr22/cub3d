/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anims.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:24:56 by luxojr            #+#    #+#             */
/*   Updated: 2023/12/21 23:46:46 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_itoa(int i)
{
	char	*str;
	int		nb_d;
	int		act;

	nb_d = 1;
	act = i;
	while (act > 10)
	{
		act /= 10;
		nb_d ++;
	}
	str = malloc(sizeof(nb_d));
	str[nb_d] = '\0';
	nb_d --;
	while (i > 9)
	{
		str[nb_d] = (i % 10) + 48;
		i /= 10;
		nb_d --;
	}
	str[nb_d] = i + 48;
	return (str);
}

t_anim	*get_anims(t_game *game, char *path, int nb_sprites)
{
	int		i;
	char	*name;
	t_anim	*start;
	t_anim	*act;
	t_anim	*next;

	i = 0;
	start = malloc(sizeof(t_anim) + 1);
	act = start;
	while (i < nb_sprites)
	{
		name = ft_strjoin(path, ft_strjoin(ft_itoa(i), ".xpm"));
		act->text = parsing_xpm(name)->img_ints;
		i ++;
		if (i < nb_sprites)
		{
			act->next = malloc(sizeof(t_anim));
			act = act->next;
		}
		else
			act->next = start;
	}
	return (start);
}
