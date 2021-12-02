NAME = cub3d
FLAGS		= -Wall -Wextra -Werror
CFLAGS		= $(FLAGS) -I. -g
CC			= gcc

SRCS 		= src/cub3d.c src/err.c src/read_file.c src/utils.c \
			src/map_validation.c src/map_validation_utils.c \
			src/render_utils.c src/keys.c src/draw1.c src/lodev_untext.c \
			get_next_line/get_next_line.c
OBJS = $(SRCS:%.c=%.o)
LIBFT_OBJS	= $(LIBFT:%.c=%.o)

INCLUDE		= cub3d.h \
			get_next_line/get_next_line.h
LIBFT_A		= libft/libft.a
MINI_LIBX	= minilibx_macos/libmlx.a
FRAMEWORK	= -framework OpenGL -framework AppKit

RED_COLOR = \033[0;31m

.PHONY: all clean fclean re bonus libft norm

.o: .c $(INCLUDE)
	@$(CC) $(CFLAGS) $< -o $@

all: libft mlx $(NAME)

${NAME}: $(OBJS) $(INCLUDE)
	@$(CC) $(OBJS) $(LIBFT_A) $(MINI_LIBX) $(FRAMEWORK) -o $(NAME)
	@echo "${GREEN_COLOR}It's done, my master${GREEN_COLOR}"

bonus: libft $(NAME)

norm:
	norminette $(SRCS)
	norminette $(SRCS_BONUS)
	norminette $(INCLUDE)
	make -C libft/ norm

libft:
	@make lib -C libft

mlx:
	@make -C minilibx_macos

clean:
	rm -f src/*.o
	rm -f get_next_line/*.o
	make -C libft clean
	make -C minilibx_macos clean

fclean: clean
	rm -f $(NAME)
	rm -f fdf
	rm -rf a.out*
	rm -rf */a.out*
	rm -rf *.gch
	rm -rf */*.gch
	rm -f libft/libft.a

re: fclean all
