/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:24:28 by nstoutze          #+#    #+#             */
/*   Updated: 2022/12/13 18:45:21 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	slen(char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		else
			i++;
	}
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = 0;
	while (s[len])
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	else
	{
		while (s[i])
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
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
	if (s1)
		free(s1);
	return (join);
}

char	*cut(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	leng;
	size_t	i;

	if (!s)
		return (NULL);
	leng = slen(s);
	if ((size_t)start >= leng)
		return (NULL);
	if (leng - (size_t)start > len)
		sub = (char *)malloc(sizeof(char) * (len + 1));
	else
		sub = (char *)malloc(sizeof(char) * (leng - (size_t)start + 1));
	if (!sub)
		return (NULL);
	i = -1;
	while (++i < len && s[start])
	{
		sub[i] = s[start];
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
