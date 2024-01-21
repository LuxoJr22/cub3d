/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_img_ints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:47:53 by nstoutze          #+#    #+#             */
/*   Updated: 2024/01/14 14:54:14 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

char	*get_symbol(char *line, int i, int colorsymbol_mode)
{
	char	*symbol;

	symbol = (char *)malloc(sizeof(char) * (colorsymbol_mode + 1));
	if (!symbol)
		return (NULL);
	symbol[colorsymbol_mode] = '\0';
	symbol[0] = line[i];
	if (colorsymbol_mode == 2)
		symbol[1] = line[i + 1];
	return (symbol);
}

char	*get_color_in_colors(t_xpm *xpm, char *symbol)
{
	t_colors	*colors_node;
	char		*color;

	color = NULL;
	colors_node = xpm->colors;
	while (colors_node)
	{
		if (!ft_strcmp(colors_node->symbol, symbol))
		{
			color = ft_strdup(colors_node->color);
			break ;
		}
		colors_node = colors_node->next;
	}
	return (color);
}

void	fill_img_ints_one_width(t_xpm *xpm, char *line, int j)
{
	char	*symbol;
	char	*color_chars;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (line[i])
	{
		symbol = NULL;
		color_chars = NULL;
		symbol = get_symbol(line, i, xpm->colorsymbol_mode);
		color_chars = get_color_in_colors(xpm, symbol);
		xpm->img_ints[(j * xpm->width) + k] = create_color(color_chars);
		free_chars(&symbol);
		free_chars(&color_chars);
		i += xpm->colorsymbol_mode;
		k++;
	}
}

void	fill_img_ints_zeros(t_xpm *xpm)
{
	int	i;
	int	nb_pixels;

	i = -1;
	nb_pixels = xpm->height * xpm->width;
	while (++i < nb_pixels)
		xpm->img_ints[i] = 0;
}

void	build_img_ints(t_xpm *xpm)
{
	char	*clear_symbols_line;
	int		i;
	int		j;

	i = xpm->first_img_line_index - 1;
	j = 0;
	xpm->img_ints = (int *)malloc(sizeof(int) * (xpm->height * xpm->width));
	fill_img_ints_zeros(xpm);
	if (!(xpm->img_ints))
		return ;
	while (xpm->file_lbl[i] && ++i < xpm->nb_lines && j < xpm->height)
	{
		if (xpm->file_lbl[i][0] == '"')
		{
			clear_symbols_line = ft_substr(xpm->file_lbl[i],
					1, xpm->width * xpm->colorsymbol_mode);
			fill_img_ints_one_width(xpm, clear_symbols_line, j);
			free_chars(&(clear_symbols_line));
			j++;
		}
	}
}
