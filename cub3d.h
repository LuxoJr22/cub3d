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
# include <string.h>
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
	t_xpm			*xpm;
	struct s_anim	*next;
}				t_anim;

typedef struct s_sprites
{
	t_fpos	pos;
	t_col	col;
	t_anim	*anim;
	int		active;
	int		*texture;
}				t_sprites;

typedef struct s_proj
{
	t_pos			pos;
	t_col			col;
	t_pos			dir;
	struct s_proj	*next;
}				t_proj;

typedef struct s_ennemies
{
	t_pos				pos;
	t_col				col;
	t_col				range;
	int					health;
	t_anim				*text;
	struct s_ennemies	*next;
}				t_ennemies;

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
	int		health;
	int		is_hit;
	int		time_hit;
	t_pos	aim;
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

typedef struct s_rcast
{
	t_pos	raydir;
	t_pos	sidedist;
	t_pos	deltadist;
	t_p		step;
	t_p		map;
	float	perpwalldist;
	int		side;
	int		hmt;
	t_p		tsize;
	t_p		draw;
	float	depth[960];
}				t_rcast;

typedef struct s_scast
{
	t_p		draw_start;
	t_p		draw_end;
	t_pos	sprite;
	t_p		sprite_size;
	t_pos	transform;
	t_p		tex;
	int		sprite_screenx;
}				t_scast;

typedef struct s_dist
{
	t_pos	a;
	float	dist;
	int		hmt;

}				t_dist;

typedef struct s_dir_vec
{
	float				angle;
	int					force;
	t_ennemies			*enn;
	struct s_dir_vec	*next;
}				t_dir_vec;

typedef struct s_mouse
{
	t_pos	pos;
	t_pos	act_pos;
}				t_mouse;

typedef struct s_outcodes
{
	t_pos	o0;
	t_pos	o1;
}				t_outcodes;

typedef struct s_game
{
	int			is_ceiling;
	int			error;
	int			transition;
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
	t_dir_vec	*dir_vec;
	t_rcast		rcast;
	int			floor_color;
	int			ceil_color;
	int			scene;
	int			map_h;
	int			map_w;
	int			map_active;
	char		*name_texture[4];
	t_anim		*anim;
	t_sprites	sprite;
	t_ennemies	*ennemies;
	t_xpm		**alphabet;
	t_xpm		*north_xpm;
	t_xpm		*east_xpm;
	t_xpm		*south_xpm;
	t_xpm		*west_xpm;
	t_xpm		*tree_xpm;
	t_xpm		*door_xpm;
}				t_game;

void		start_transi(t_game *game, int color);
int			hit_ennemies(t_game *game, t_col enn, t_pos ps, t_pos aim);
int			check_g(t_game *game, int x, int y);
char		*get_textures(t_game *game, char buf[2], char *str, int fd);
int			get_number(char c);
void		draw_crossh(t_game *game);
void		update_ennemies(t_game *game);
void		state(t_game *game);
char		**ft_split(char *str, char *charset);
void		reset_ennemies(t_game *game);
int			ft_is_space(char c);
void		drawsprite(t_game *game, t_pos spos, t_anim *text);
void		get_name_text(t_game *game);
void		show_sprite(t_game *game, t_scast sc, t_p pos, t_anim *text);
void		show_wall(t_game *game, int nb_ray, int lineHeight);
int			ft_atoi(char *str);
void		floor_cast(t_game *game, int y);
float		ret_abs(float i);
int			create_color(char *str);
int			ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
void		draw_back(t_game *game, t_pos start, t_pos length, int color);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_rgb		my_mlx_pixel_get(t_data *data, int x, int y);
t_rgb		get_colors(int color);
void		draw_line(t_game *game, t_pos p1, t_pos p2, int color);
void		shoot(t_game *game);
void		draw_cube(t_game *game, int x, int y, int color);
void		cast_vertical_line(t_game *game, float ra, float Tan);
void		cast_horizontal_line(t_game *game, float ra, float Tan);
void		collisions(t_game *game);
t_col		init_col(t_pos position, int scale);
void		init_mouse(t_game *game);
int			add_trgb(int color1, int color2);
void		draw_minimap(t_game *game);
void		show_xpm(t_game *game, t_xpm *xpm, int x, int y);
void		create_img(t_game *game);
void		get_map(t_game *game, char *name);
int			button_mouse(int keycode, int x, int y, t_game *game);
char		*ft_itoa(int i);
int			effect_color(t_game *game, int color);
void		display_raycast(t_game *game);
int			key_manager(int keycode, t_game *game);
t_pos		get_deltadist(t_pos raydir);
void		get_sidedist(t_game *game, t_p map);
void		get_perpwalldist(t_game *game);
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
t_game		*init_game(t_player *player, char *str);
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
char		*get_character(t_game *game, char buf[2], char *str, int fd);
void		free_ennemies(t_game *game);
void		free_forces(t_game *game);
char		*add_malloc(char *str, char buf);
int			get_color(char *str, t_game *game);
void		exit_game_code(t_game *game, int i, char *str);
int			ft_is_in(char *str, char c);
void		free_dptr(char	**dptr);
void		set_player_pos(t_game *game, int offx, int offy, char c);
void		get_map(t_game *game, char *name);
void		boost(t_game *game, float pa, int force, t_ennemies *enn);
char		*reset_str(char *str);
void		create_map(t_game *game, char *str);
void		free_font(t_game *game);
void		free_xpms(t_game *game);
int			exit_game(t_game *game);
void		drawsprites(t_game *game);
void		init_enemies(t_game *game, char *name, int nb_sprites, t_pos pos);
void		free_anims(t_anim *anim);
int			collision(t_col hit1, t_col hit2);
t_anim		*get_anims(char *path, int nb_sprites);
void		get_font(t_game *game, char *file);
void		apply_boost(t_game *game);
float		get_angle(t_pos	subject, t_pos object);
void		show_str(t_game *game, int x, int y, char *str);
char		*ft_strjoin_f(char *s1, char *s2, int mode);

#endif
