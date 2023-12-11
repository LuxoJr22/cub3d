#include "cub3d.h"

void	print_charss_nonl(char **charss)
{
	int	i = -1;

	if (!charss)
		return ;
	while (charss[++i])
		printf("%s", charss[i]);
	printf("\n");
}

void	print_colors(t_xpm *xpm)
{
	t_colors	*colors = xpm->colors;

	while (colors)
	{
		printf("colors->symbol = %s ; colors->color = %s\n", colors->symbol, colors->color);
		colors = colors->next;
	}
}

void	print_img_ints(t_xpm *xpm)
{
	int	nb_pixels = xpm->width * xpm->height;
	int	i = -1;

	while (++i < nb_pixels)
	{
		printf("%d ", xpm->img_ints[i]);
		if ((i + 1) % xpm->width == 0)
			printf("\n");
	}
}

void	print_parsing_xpm(t_xpm *xpm, char *filename)
{
	printf("===== PRINT_PARSING_XPM =====\n");
	printf("filename = %s\n", filename);
	printf("xpm->filename = %s\n", xpm->filename);
	printf("caracline = %s\n", xpm->carac_line);
	printf("caracline_index = %d ; first_color_line_index = %d ; last_color_line_index = %d ; first_img_line_index = %d\n", xpm->carac_line_index, xpm->first_color_line_index, xpm->last_color_line_index, xpm->first_img_line_index);
	printf("nb_line = %d ; nb_colors = %d ; height = %d ; width = %d\n", xpm->nb_lines, xpm->nb_colors, xpm->height, xpm->width);
	print_charss_nonl(xpm->file_lbl);
	print_colors(xpm);
	print_img_ints(xpm);
	printf("===== FIN     PRINT_PARSING_XPM     FIN =====\n\n");
	//free(xpm->img_ints); // A SUPPRIMER !!!!!!!!!!!!!
}
