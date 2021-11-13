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

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		line_l;
	int		bpp;
	int		en;
}	t_win;

typedef struct s_all
{
	t_win	*win;
	char	**map;
}	t_all;

void	common_err(int err);
void	read_file(char *file_name, t_all *data);
int		get_height(char *file_name);
int		get_width(char *file_name);

#endif
