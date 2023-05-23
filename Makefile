
SRCS = cub3d.c draw.c keymanager.c player.c raycaster.c utils.c parsing.c

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
