/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:58:28 by marvin            #+#    #+#             */
/*   Updated: 2023/04/19 15:58:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

#include <mlx.h>
#include <stdlib.h>
#include "stdio.h"
# include <fcntl.h>
# include <unistd.h>
#include <math.h>
#define PI 3.1415926535
#define P2 PI/2
#define P3 3*PI/2
#define DR 0.0174533

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_pos {
	float x;
	float y;
}			t_pos;

typedef struct s_player {
	float	px;
	float	py;
	int dx;
	int	dy;
	float pa;
	float pdy;
	float pdx;
}				t_player;

typedef struct s_raycaster {
	t_pos	dis;
	t_pos	vc;
	t_pos	hc;
	t_pos	mt;

}				t_raycaster;

typedef struct s_game {
	int			*map;
	void		*mlx;
	void		*mlx_win;
	t_player	*player;
	void		*bg;
	int			frame;
	t_data		img;
	t_data		frame1;
	t_data		frame2;
	void		*actframe;
	int			*textures;
	t_raycaster raycast;
	int			floor_color;
	int			ceil_color;
	int			map_h;
	int			map_w;
}				t_game;

void	draw_back(t_game *game, t_pos start, t_pos length, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_game *game, t_pos p1, t_pos p2, int color);
void	draw_cube(t_game *game, int x, int y);
void	get_map(t_game *game, char *name);
void	draw_player(t_game *game);
void	raycaster3D(t_game *game);
int		key_manager(int keycode, t_game *game);
int		get_trgb(int t, int r, int g, int b);
int 	dist(int x1, int y1, int x2, int y2);
int		relinput(int keycode, t_game *game);
int		move(t_game *game);

float check_angle(float a);


#endif
