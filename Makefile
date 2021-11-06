ifeq ($(MAKECMDGOALS),bonus)
	NAME = checker
else
	NAME = fdf
endif
FLAGS		= -Wall -Wextra -Werror
CFLAGS		= $(FLAGS) -I. -g
CC			= gcc

ifeq ($(MAKECMDGOALS),bonus)
	OBJS = $(SRCS_BONUS:%.c=%.o)
else
	OBJS = $(SRCS:%.c=%.o)
endif

LIBFT_OBJS	= $(LIBFT:%.c=%.o)
SRCS 		= src/fdf.c \
			src/read_file.c \
			src/utils1.c \
			src/utils2.c \
			src/draw1.c \
			src/draw2.c \
			src/keys.c \
			src/rotate.c \
			get_next_line/get_next_line.c
SRCS_BONUS	=
INCLUDE		= fdf.h \
			get_next_line/get_next_line.h
LIBFT_A		= libft/libft.a
MINI_LIBX	= minilibx_macos/libmlx.a
FRAMEWORK	= -framework OpenGL -framework AppKit

.PHONY: all clean fclean re bonus libft norm

.o: .c $(INCLUDE)
	$(CC) $(CFLAGS) $< -o $@

all: libft mlx $(NAME)

${NAME}: $(OBJS) $(INCLUDE)
	$(CC) $(OBJS) $(LIBFT_A) $(MINI_LIBX) $(FRAMEWORK) -o $(NAME)

bonus: libft $(NAME)

norm:
	norminette $(SRCS)
	norminette $(SRCS_BONUS)
	norminette $(INCLUDE)
	make -C libft/ norm

libft:
	make lib -C libft

mlx:
	make -C minilibx_macos

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
