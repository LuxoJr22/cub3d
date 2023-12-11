/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nstoutze <nstoutze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:47:35 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/04 18:12:51 by nstoutze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int char_in_str(char c, char *charset)
{
    int i;

    i = -1;
    while (charset[++i])
    {
        if (c == charset[i])
            return (1);
    }
    return (0);
}

int nb_words_in_str(char *str, char *charset)
{
    int n;
    int i;

    n = 0;
    i = -1;
    if (!(char_in_str(str[++i], charset)))
        n++;
    while (str[++i])
        if (!(char_in_str(str[i], charset))
            && (char_in_str(str[i - 1], charset)))
            n++;
    return (n);
}

char    *next_word(char *str, int *ptr_i, char *charset)
{
    char    *word;
    int     len_word;

    len_word = 0;
    while (char_in_str(str[*ptr_i], charset))
        (*ptr_i)++;
    while (str[*ptr_i + len_word]
           && !(char_in_str(str[*ptr_i + len_word], charset)))
        len_word++;
    word = (char*)malloc(sizeof(char) * (len_word + 1));
    word[len_word] = '\0';
    len_word = 0;
    while (str[*ptr_i] && !(char_in_str(str[*ptr_i], charset)))
    {
        word[len_word] = str[*ptr_i];
        len_word++;
        (*ptr_i)++;
    }
    return (word);
}

char    **ft_split(char *str, char *charset)
{
    char    **tab;
    int     nb_words;
    int     num_word;
    int     i;

    nb_words = nb_words_in_str(str, charset);
    num_word = -1;
    i = 0;
    tab = (char**)malloc(sizeof(char*) * (nb_words + 1));
    tab[nb_words] = '\0';
    while (++num_word < nb_words)
        tab[num_word] = next_word(str, &i, charset);
    return (tab);
}

/*
#include <stdio.h> // A SUPPRIMER
int main()
{
    char str[] = "Salut ca, va ? Ouais et toi ? Oklm";
    //char str[] = "hello";
    //char str[] = " hello";
    //char str[] = " hello ";
    //char str[] = "hello ";
    //char str[] = "  ";
    char charset[] = " ,?";
    int n = nb_words_in_str(str, charset);
	printf("Nombre de mots : %d\n", n);
    char **tab = split2(str, charset);
	int i = -1;
	printf("[");
	while (++i < n)
    {
        printf("%s", tab[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]");
    return (0);
}
*/

/*
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

char	**ft_split(char *s, char sep)
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
*/
