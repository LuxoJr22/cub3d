/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_img_ints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 17:47:53 by nstoutze          #+#    #+#             */
/*   Updated: 2023/12/11 16:31:59 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_xpm.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*get_symbol(char *line, int i, int colorsymbol_mode)
{
	//printf("get_symbol : line = %s\n", line);
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
	//printf("get_color_in_colors : symbol = %s\n", symbol);
	t_colors	*colors_node;
	char		*color;

	color = NULL;
	colors_node = xpm->colors;
	while (colors_node)
	{
		//printf("get_color_in_colors : colors_node->symbol = %s ; colors_node->color = %s\n", colors_node->symbol, colors_node->color);
		if (!ft_strcmp(colors_node->symbol, symbol))
		{
			color = ft_strdup(colors_node->color);
			break ;
		}
		colors_node = colors_node->next;
	}
	//printf("get_color_in_colors ; return imminent : color = %s\n", color);
	return (color);
}

void	fill_img_ints_one_width(t_xpm *xpm, char *line, int j)
{
	//printf("fill_img_ints_one_width : %s\n", line);
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
		//printf("fill_img_ints_one_width(while) ; début itération : i = %d ; k = %d\n", i, k);
		symbol = get_symbol(line, i, xpm->colorsymbol_mode);
		color_chars = get_color_in_colors(xpm, symbol);
		//printf("fill_img_ints_one_width(while) ; (j * xpm->width) + k = %d\n", (j * xpm->width) + k);
		//printf("fill_img_ints_one_width(while) ; symbol = %s ; color_chars = %s\n", symbol, color_chars);

		xpm->img_ints[(j * xpm->width) + k] = create_color(color_chars);
		//printf("fill_img_ints_one_width(while) ; PROBE\n");
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
	
	//printf("build_img_ints : ENTREE\n");
	//printf("build_img_ints : xpm->first_img_line_index = %d\n", xpm->first_img_line_index);
	//printf("build_img_ints : xpm->file_lbl[xpm->first_img_line_index] = %s", xpm->file_lbl[xpm->first_img_line_index]);
	//printf("build_img_ints : xpm->colorsymbol_mode = %d\n", xpm->colorsymbol_mode);
	
	int	i;
	int	j;

	i = xpm->first_img_line_index - 1;
	j = 0;
	xpm->img_ints = (int *)malloc(sizeof(int) * (xpm->height * xpm->width));
	fill_img_ints_zeros(xpm);
	//print_img_ints(xpm);
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
