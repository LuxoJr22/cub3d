/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luxojr <luxojr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:03:48 by luxojr            #+#    #+#             */
/*   Updated: 2023/11/29 12:03:48 by luxojr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "parsing_xpm/parsing_xpm.h"

# define PI 3.1415926535
# define P2 1.5707963267
# define P3 4.7123889804
# define DR 0.0174533

typedef struct s_xpm	t_xpm;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_pos
{
	float	x;
	float	y;
}			t_pos;

typedef struct s_p
{
	int	x;
	int	y;
}			t_p;

typedef struct s_fpos
{
	float	x;
	float	y;
	float	z;
}			t_fpos;

typedef struct s_col
{
	int	ymax;
	int	ymin;
	int	xmax;
	int	xmin;
}				t_col;

typedef struct s_sprites
{
	t_fpos	pos;
	t_col	col;
	int		active;
	int		*texture;
}				t_sprites;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}			t_rgb;

typedef struct s_anim
{
	int				*text;
	int				height;
	int				width;
	struct s_anim	*next;
}				t_anim;

typedef struct s_player
{
	float	px;
	float	py;
	int		dx;
	int		dy;
	float	pa;
	int		cm;
	float	pdy;
	float	pdx;
	float	sprint;
	float	height;
	float	actheight;
	int		is_jump;
	int		coin;
	t_col	col;
}				t_player;

typedef struct s_raycaster
{
	t_pos	dis;
	t_pos	vc;
	t_pos	hc;
	t_pos	mt;
	int		hmt;

}				t_raycaster;

typedef struct s_raycaster2
{
	t_pos	raydir;
	t_pos	sideDist;
	t_pos	deltadist;
	t_p		step;
	t_p		map;
	float	perpwalldist;
	int		side;
	int		hmt;

}				t_raycaster2;

typedef struct s_dist
{
	t_pos	a;
	float	dist;
	int		hmt;

}				t_dist;

typedef struct s_mouse
{
	t_pos	pos;
	t_pos	act_pos;
}				t_mouse;

typedef struct s_game
{
	int			*map;
	t_pos		plan;
	void		*mlx;
	void		*mlx_win;
	t_player	*player;
	t_mouse		mouse;
	int			frame;
	t_data		img;
	t_data		frame1;
	t_data		frame2;
	void		*actframe;
	int			*textures;
	t_raycaster	raycast;
	t_raycaster2	rcast;
	int			floor_color;
	int			ceil_color;
	int			map_h;
	int			map_w;
	int			map_active;
	t_anim		*anim;
	t_sprites	sprite;
	t_xpm		*north_xpm;
	t_xpm		*east_xpm;
	t_xpm		*south_xpm;
	t_xpm		*west_xpm;
	t_xpm		*tree_xpm;
	t_xpm		**alphabet;
}				t_game;

char		**ft_split(char *str, char *charset);
int			ft_atoi(char *str);
float		ret_abs(float i);
int			create_color(char *str);
int			ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
void		draw_back(t_game *game, t_pos start, t_pos length, int color);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_line(t_game *game, t_pos p1, t_pos p2, int color);
void		draw_cube(t_game *game, int x, int y, int color);
void		cast_vertical_line(t_game *game, float ra, float Tan);
void		cast_horizontal_line(t_game *game, float ra, float Tan);
t_col		init_col(t_pos position, int scale);
int			add_trgb(int color1, int color2);
void		draw_minimap(t_game *game);
void		show_xpm(t_game *game, t_xpm *xpm, int x, int y);
void		create_img(t_game *game);
void		get_map(t_game *game, char *name);
void		draw_player(t_game *game);
char		*ft_itoa(int i);
int			effect_color(t_game *game, int color);
void		display_raycast(t_game *game);
int			key_manager(int keycode, t_game *game);
int			get_trgb(int t, int r, int g, int b);
void		show_map(t_game *game);
int			dist(int x1, int y1, int x2, int y2);
int			relinput(int keycode, t_game *game);
int			move(t_game *game);
void		move_back(t_game *game);
void		move_front(t_game *game);
void		move_left(t_game *game);
void		raycasting(t_game *game);
void		move_right(t_game *game);
int			ft_atoi(char *str);
t_game		*init_game(t_player *player);
int			*all_text(t_game *game);
t_player	*init_player(void);
void		init_sprites(t_game *game);
int			mouse_manager(int x, int y, t_game *game);
float		check_angle(float a);
void		draw_back_mini(t_game *game);
void		draw_border_mini(t_game *game);
void		draw_player(t_game *game);
void		print_parsing_xpm(t_xpm *xpm, char *filename);
void		print_img_ints(t_xpm *xpm);
void		print_colors(t_xpm *xpm);
int			scene_manager(t_game *game);
void		draw_img(t_game *game, t_p d, t_p p, int side);
void		raycast(t_game *game, float ra);
int			get_character(t_game *game, char buf[2], char *str, int fd);
char		*add_malloc(char *str, char buf);
int			get_color(char *str);
void		set_player_pos(t_game *game, int offx, int offy, char c);
void		get_map(t_game *game, char *name);
char		*reset_str(char *str);
void		create_map(t_game *game, char *str);
int			exit_game(int i);
void		draw_sprites(t_game *game, float depth[480]);
int			collision(t_game *game, t_col hit1, t_col hit2);
t_anim		*get_anims(t_game *game, char *path, int nb_sprites);
void		get_font(t_game *game, char *file);
void		show_str(t_game *game, int x, int y, char *str);

#endif
