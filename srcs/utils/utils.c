/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:03:40 by luxojr            #+#    #+#             */
/*   Updated: 2023/11/29 12:03:40 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	dist(int x1, int y1, int x2, int y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] == ' ')
		i ++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - 48;
	return (nb);
}

float	check_angle(float a)
{
	if (a < 0)
		a += 2 * PI;
	if (a > 2 * PI)
		a -= 2 * PI;
	return (a);
}

int	ft_strlen(char *str)
{
	int	len;

	len = -1;
	while (str[++len])
		;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;
	size_t	lens1;
	size_t	lens2;

	lens1 = slen(s1);
	lens2 = slen(s2);
	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	join = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!join)
		return (NULL);
	while (++i < lens1)
		join[i] = s1[i];
	while (++j < lens2)
		join[i + j] = s2[j];
	join[i + j] = '\0';
	return (join);
}
