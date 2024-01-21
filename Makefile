SRCS = cub3d.c \
	   srcs/init/init.c \
	   srcs/init/free.c \
	   srcs/init/exit.c \
	   srcs/init/init_map.c \
	   srcs/init/init_game.c \
	   srcs/init/utils_init.c \
	   srcs/raycasting/raycaster.c \
	   srcs/raycasting/utils_raycast.c \
	   srcs/raycasting/raycasting.c \
	   srcs/raycasting/show_xpm.c \
	   srcs/raycasting/show_raycast.c \
	   srcs/actions/shoot.c \
	   srcs/actions/movement.c \
	   srcs/actions/collision.c \
	   srcs/actions/keymanager.c \
	   srcs/actions/dir_vector.c \
	   srcs/entities/player.c \
	   srcs/entities/ennemies.c \
	   srcs/parsing/parsing.c \
	   srcs/parsing/utils_parsing.c \
	   srcs/scenes/menu.c \
	   srcs/scenes/game.c \
	   srcs/scenes/minimap.c \
	   srcs/scenes/transitions.c \
	   srcs/scenes/scene_manager.c \
	   srcs/draw/draw.c \
	   srcs/draw/anims.c \
	   srcs/draw/draw_hud.c \
	   srcs/draw/draw_mini.c \
	   srcs/draw/draw_letter.c \
	   srcs/utils/utils.c \
	   srcs/utils/utils2.c \
	   srcs/utils/utils3.c \
	   srcs/utils/ft_split.c \
	   srcs/utils/create_color.c \
	   srcs/parsing_xpm/add_colors_node.c \
	   srcs/parsing_xpm/adjust_colors.c \
	   srcs/parsing_xpm/build_colors_chained_list.c \
	   srcs/parsing_xpm/build_img_ints.c \
	   srcs/parsing_xpm/check_colorsymbol_mode.c \
	   srcs/parsing_xpm/check_img_rectangular.c \
	   srcs/parsing_xpm/feed_file_lbl.c \
	   srcs/parsing_xpm/feed_xpm_width_height_nbcolors.c \
	   srcs/parsing_xpm/feed_colors_node.c \
	   srcs/parsing_xpm/free_chars.c \
	   srcs/parsing_xpm/free_ntcharss.c \
	   srcs/parsing_xpm/free_xpm.c \
	   srcs/parsing_xpm/ft_bzero.c \
	   srcs/parsing_xpm/ft_memset.c \
	   srcs/parsing_xpm/ft_substr.c \
	   srcs/parsing_xpm/ft_strcmp.c \
	   srcs/parsing_xpm/get_first_img_line_index.c \
	   srcs/parsing_xpm/get_nb_lines.c \
	   srcs/parsing_xpm/get_next_line_bonus.c \
	   srcs/parsing_xpm/get_next_line_utils_bonus.c \
	   srcs/parsing_xpm/get_size_ntcharss.c \
	   srcs/parsing_xpm/malloc_full_null_charss.c \
	   srcs/parsing_xpm/new_colors.c \
	   srcs/parsing_xpm/new_xpm.c \
	   srcs/parsing_xpm/parsing_xpm.c \
	   srcs/parsing_xpm/xpm_strlen.c \



OBJS = ${SRCS:.c=.o}

NAME = cub3d

.c.o:
	gcc -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o ${<:.c=.o}


${NAME}: ${OBJS}
	gcc ${OBJS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

all:	${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all
