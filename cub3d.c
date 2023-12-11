/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:02:59 by luxojr            #+#    #+#             */
/*   Updated: 2023/11/29 12:02:59 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_game(int i)
{
	exit (1);
	return (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	scene_manager(t_game *game)
{
	t_pos	start;
	t_pos	length;

	mlx_destroy_image(game->mlx, game->frame2.img);
	game->frame2 = game->frame1;
	game->frame1.img = mlx_new_image(game->mlx, 960, 640);
	game->frame1.addr = mlx_get_data_addr(game->frame1.img, &game->frame1.bits_per_pixel, &game->frame1.line_length, &game->frame1.endian);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->frame2.img, 0, 0);
	start.x = 0;
	start.y = 0;
	length.x = 960;
	length.y = 320;
	draw_back(game, start, length, effect_color(game, game->ceil_color));
	start.y += length.y;
	draw_back(game, start, length, effect_color(game, game->floor_color));
	display_raycast(game);
	if (game->map_active == 0)
		draw_minimap(game);
	else
		show_map(game);
	game->frame ++;
	if (game->frame % 2 == 0)
		move(game);
	if (game->frame >= 60)
		game->frame = 0;
}

/*
int	*all_text(t_game *game, t_xpm *test)
{
	int			*textures;
	int			x;
	int			y;
	t_xpm		**text;
	t_colors	*colors;
	int			i;

	text = malloc(sizeof(t_xpm) * 4);
	text[0] = game->north_xpm;
	text[1] = game->west_xpm;
	text[2] = game->south_xpm;
	text[3] = game->east_xpm;
	colors = text[0]->colors;
	textures = malloc(sizeof(int) * 1024 * 4 + 1);
	x = 0;
	y = 0;
	i = 0;
	while (x < 4)
	{
		while (y < 1024)
		{
			textures[x * 1024 + y] = get_trgb(0, 0, 0, 0);
			while (i < text[x]->nb_colors)
			{
				if (colors->symbol == text[x]->img_one_chars[y])
				{
					textures[x * 1024 + y] = create_color(colors->color);
				}
				colors = colors->next;
				i ++;
			}
			i = 0;
			colors = text[x]->colors;
			y ++;
		}
		y = 0;
		x ++;
	}
	return (textures);
}
*/

int	main(void)
{
	t_game		*game;
	t_player	*player;
	void		*params;
	int			imgw;
	int			imgh;

	game = malloc(sizeof(t_game));
	player = malloc(sizeof(t_player));
	player->px = 150;
	player->py = 400;
	player->pa = 0;
	player->pdx = cos(player->pa) * 5;
	player->pdy = sin(player->pa) * 5;
	player->cm = 0;
	player->sprint = 1;
	player->height = 1;
	player->actheight = 1;
	player->is_jump = 0;
	game->map_active = 0;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 960, 640, "Cub3d");
	game->player = player;
	game->bg = mlx_xpm_file_to_image(game->mlx,
			"assets/black.xpm", &imgw, &imgh);
	// game->north_xpm = parsing_xpm("assets/wall.xpm");
	// game->south_xpm = parsing_xpm("assets/south.xpm");
	// game->east_xpm = parsing_xpm("assets/east.xpm");
	// game->west_xpm = parsing_xpm("assets/west.xpm");
	


	game->south_xpm = parsing_xpm("assets/wall.xpm");
	
	print_parsing_xpm(game->south_xpm, "wall.xpm");

	/*
	game->textures = all_text(game, game->north_xpm);
	game->img.img = mlx_new_image(game->mlx, 960, 640);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	game->frame1.img = mlx_new_image(game->mlx, 960, 640);
	game->frame1.addr = mlx_get_data_addr(game->frame1.img, &game->frame1.bits_per_pixel, &game->frame1.line_length, &game->frame1.endian);
	game->frame2.img = mlx_new_image(game->mlx, 960, 640);
	game->frame2.addr = mlx_get_data_addr(game->frame2.img, &game->frame2.bits_per_pixel, &game->frame2.line_length, &game->frame2.endian);
	game->map_h = 8;
	game->map_w = 8;
	get_map(game, "map.cub");
	game->frame = 0;
	mlx_hook(game->mlx_win, 17, (1L << 0), exit_game, params);
	mlx_hook(game->mlx_win, 2, (1L << 0), key_manager, game);
	mlx_hook(game->mlx_win, 3, (1L << 1), relinput, game);
	mlx_loop_hook(game->mlx, scene_manager, game);
	mlx_loop(game->mlx);
	*/
	return (EXIT_SUCCESS);
}
