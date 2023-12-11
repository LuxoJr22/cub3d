/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:47:35 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/10 21:39:00 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdint.h>


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
