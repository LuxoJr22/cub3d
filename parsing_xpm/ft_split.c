/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:47:35 by nstoutze          #+#    #+#             */
/*   Updated: 2023/11/30 12:59:06 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

# include <stdint.h>

static void	*ft_calloc(size_t count, size_t size)
{
	size_t	*element;

	if (size == SIZE_MAX)
		count = 1;
	element = (void *) malloc(count * size);
	if (!element)
		return (NULL);
	ft_bzero(element, count * size);
	return ((void *) element);
}

static int	nb_str(char *str, char c)
{
	int	i;
	int	nb_word;

	i = -1;
	nb_word = 0;
	while (str[++i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			nb_word++;
	}
	return (nb_word);
}

static void	testfac(char *str, char sep, int tab_size, char **tab)
{
	int	i;
	int	startword;
	int	len_world;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		len_world = 0;
		if (str[i] == sep)
			i++;
		startword = i;
		if (str[i] != sep)
		{
			while (str[i] && str[i] != sep)
			{
				len_world++;
				if ((str[i + 1] == sep || str[i + 1] == '\0') && j < tab_size)
					tab[j++] = ft_substr(str, startword, len_world);
				i++;
			}
		}
	}
	tab[j] = (NULL);
}

char	**ft_split(char const *s, char sep)
{
	int		tab_size;
	char	*str;
	char	**tab;
	char	**error;

	str = (char *)s;
	if (!str)
	{
		error = (char **)ft_calloc(1, sizeof(char *));
		return (error);
	}
	tab_size = nb_str(str, sep);
	if (tab_size == 0)
	{
		error = (char **)ft_calloc(1, sizeof(char *));
		return (error);
	}
	tab = (char **)ft_calloc(tab_size + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	testfac(str, sep, tab_size, tab);
	return (tab);
}
