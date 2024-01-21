/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 02:35:09 by luxojr            #+#    #+#             */
/*   Updated: 2024/01/21 16:30:13 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*reset_str(char *str)
{
	char	*ret;

	if (str)
		free(str);
	ret = malloc(sizeof(char));
	ret[0] = '\0';
	return (ret);
}

char	*add_malloc(char *str, char buf)
{
	int		i;
	char	*str_ret;

	i = 0;
	while (str[i])
		i ++;
	str_ret = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (str[i])
	{
		str_ret[i] = str[i];
		i ++;
	}
	str_ret[i] = buf;
	str_ret[i + 1] = '\0';
	free(str);
	return (str_ret);
}

int	is_in(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i ++;
	}
	return (0);
}

int	ft_is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
