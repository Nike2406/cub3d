#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <stdio.h>
# include <math.h>
// # include "./minilibx_macos/mlx.h"

# define ERR_MALLOC		1
# define ERR_READING	2
# define ERR_ARGUMENTS	3

typedef struct s_cub3d
{
	int		width;
	int		height;
}	t_cub3d;

void	common_err(int err);
void	read_file(char *file_name, t_cub3d *data);
int		get_height(char *file_name);
int		get_width(char *file_name);

#endif
