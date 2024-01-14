/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:39:09 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/14 02:39:42 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_ret(char *str)
{
	int		i;
	int		length;
	char	*ret;

	i = 0;
	length = 0;
	while (str[i] && (ft_is_space(str[i]) == 0 || length == 0))
	{
		if (ft_is_space(str[i]) == 0)
			length ++;
		i ++;
	}
	ret = malloc(sizeof(char) * length + 1);
	return (ret);
}

char	*get_file_str(char *str)
{
	char	*ret;
	int		i;
	int		length;

	ret = get_ret(str);
	i = 0;
	length = 0;
	while (str[i] && (ft_is_space(str[i]) == 0 || length == 0))
	{
		if (ft_is_space(str[i]) == 0)
		{
			ret[length] = str[i];
			length ++;
		}
		i ++;
	}
	ret[length] = '\0';
	free(str);
	return (ret);
}

void	get_name_text(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->name_texture[i] = get_file_str(game->name_texture[i]);
		i ++;
	}
}
