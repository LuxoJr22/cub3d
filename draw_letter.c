/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_letter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:37:31 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/15 11:01:41 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_font(t_game *game, char *file)
{
	t_xpm	**alphabet;
	char	*str;
	int		i;

	i = 0;
	alphabet = malloc(sizeof(t_xpm *) * 26);
	str = ft_strjoin(file, "a.xpm");
	while (i < 26)
	{
		alphabet[i] = parsing_xpm(str);
		str[ft_strlen(file)]++;
		i ++;
	}
	free(str);
	game->alphabet = alphabet;
}

void	show_str(t_game *game, int x, int y, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			show_xpm(game, game->alphabet[str[i] - 'a'], x + i * 22, y);
		}
		i ++;
	}
}
