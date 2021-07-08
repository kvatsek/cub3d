
SRCS = make_map_lst.c draw_map.c read_params.c check_new_map.c draw_sprites.c bmp_save.c \
make_map_2.c read_param_tex.c key_press.c utils_draw_map.c utils_2_draw.c sprait_utils.c cheak_rep.c

NAME = cub3D

GCC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

MLX_FL =  -Lmlx -lmlx -framework OpenGL -framework AppKit 

${NAME}: ${SRCS} 
		make -C ./libft/
		${GCC} -g ${CFLAGS} ${SRCS} ./libft/libft.a ${MLX_FL} -o ${NAME}

all: ${NAME}

bonus: all

clean: 
		${RM} ./libft/*.o

fclean: clean
		${RM} ${NAME}
		${RM} ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re
