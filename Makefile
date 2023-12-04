SRCS = cub3d.c \
	   draw.c \
	   keymanager.c \
	   player.c \
	   raycaster.c \
	   utils.c \
	   parsing.c \
	   minimap.c \
	   parsing_xpm/add_colors_node.c \
	   parsing_xpm/build_colors_chained_list.c \
	   parsing_xpm/feed_file_lbl.c \
	   parsing_xpm/feed_xpm_width_height_nbcolors.c \
	   parsing_xpm/feed_colors_node.c \
	   parsing_xpm/free_chars.c \
	   parsing_xpm/free_ntcharss.c \
	   parsing_xpm/ft_bzero.c \
	   parsing_xpm/ft_memset.c \
	   parsing_xpm/ft_substr.c \
	   parsing_xpm/get_img_one_chars.c \
	   parsing_xpm/get_nb_lines.c \
	   parsing_xpm/get_next_line_bonus.c \
	   parsing_xpm/get_next_line_utils_bonus.c \
	   parsing_xpm/get_size_ntcharss.c \
	   parsing_xpm/malloc_full_null_charss.c \
	   parsing_xpm/new_colors.c \
	   parsing_xpm/new_xpm.c \
	   parsing_xpm/parsing_xpm.c \

OBJS = ${SRCS:.c=.o}

NAME = cub3d

.c.o:
	gcc -I/usr/include -Imlx_linux -O3 -c $< -o ${<:.c=.o}


${NAME}: ${OBJS}
	gcc ${OBJS} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

all:	${NAME}

clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all
