NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INC_DIR = -I includes
SRCS_DIR = srcs
OBJS_DIR = objs

SRCS =	create_map.c \
		draw.c \
		get_next_line_utils.c \
		get_next_line.c \
		main.c \
		utils.c \
		values.c

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.c=%.o})

LIBFT_PATH = libft
LIBFT_LIB = ${LIBFT_PATH}/libft.a
LIBFT_INC = ${LIBFT_PATH}

MLX_PATH = mlx
MLX_LIB	= ${MLX_PATH}/libmlx.a ${MLX_FLAGS}
MLX_INC = -I ${MLX_PATH}/
MLX_FLAGS = -framework OpenGL -framework AppKit

all: ${NAME}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} ${INC_DIR} -I ${LIBFT_INC} ${MLX_INC} -c $< -o $@

${NAME}: ${OBJS}
	@make -C ${LIBFT_PATH}
	@make -C ${MLX_PATH}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} ${MLX_LIB} -o ${NAME}

clean:
	@make clean -C ${LIBFT_PATH}
	@make clean -C ${MLX_PATH}
	${RM} ${OBJS_DIR}

fclean:	clean
	@make fclean -C ${LIBFT_PATH}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re