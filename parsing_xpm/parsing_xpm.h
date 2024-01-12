/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_xpm.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 23:03:18 by nstoutze          #+#    #+#             */
/*   Updated: 2024/01/02 19:38:59 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_XPM_H
# define PARSING_XPM_H

# include "../cub3d.h"
# include "get_next_line_bonus.h"

typedef struct s_colors	t_colors;

struct s_colors
{
	t_colors	*next;
	char		*symbol;
	char		*color;
};

typedef enum e_bool
{
	FALSE,
	TRUE
} t_bool;


typedef struct s_xpm
{
	char		*carac_line;
	int			carac_line_index;
	int			first_color_line_index;
	int			last_color_line_index;
	int			first_img_line_index;
	char		*img_one_chars;
	t_bool		valid;
	char		*filename;
	int			nb_lines;
	char		**file_lbl;
	int			height;
	int			width;
	int			nb_colors;
	t_colors	*colors;
	int			colorsymbol_mode;
	int			*img_ints;
	int			len_first_img_line;
	t_bool		rectangular;
} t_xpm;

void		add_colors_node(t_xpm *xpm, int i);
void		adjust_colors(t_xpm *xpm);
void		build_colors_chained_list(t_xpm *xpm);
void		build_img_ints(t_xpm *xpm);
void		check_colorsymbol_mode(t_xpm *xpm);
void		check_img_rectangular(t_xpm *xpm);
void		feed_colors_node(t_xpm *xpm, t_colors *colors_node, int i);
void		feed_file_lbl(t_xpm *xpm);
void		feed_xpm_width_height_nbcolors(t_xpm *xpm);
void		free_chars(char **dust);
void		free_ntcharss(char ***dust);
void		free_xpm(t_xpm *xpm);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		get_first_img_line_index(t_xpm *xpm);
void		get_img_one_chars(t_xpm *xpm);
void		get_nb_lines(t_xpm *xpm);
int			get_size_ntcharss(char **ntcharss);
char		**malloc_full_null_charss(int size);
t_colors	*new_colors();
t_xpm		*new_xpm(char *filename);
t_xpm		*parsing_xpm(char *filename);
int			xpm_strlen(char *xpm_line);

#endif