/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:08:27 by prochell          #+#    #+#             */
/*   Updated: 2021/11/18 21:15:29 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <stdio.h>
# include <math.h>
# include "./minilibx_macos/mlx.h"

# define ERR_MALLOC		1
# define ERR_READING	2
# define ERR_ARGUMENTS	3

# define ERR_PLAYER		1
# define ERR_SYMBOL		2
# define ERR_MAP		3
# define ERR_PLR_LOCK	4

typedef struct s_player
{
	int		x;
	int		y;
	char	plr_direction;
}	t_player;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		line_l;
	int		bpp;
	int		en;

	int		img_width;
	int		img_height;
}	t_win;

typedef struct s_all
{
	t_win		*win;
	char		**map;
	t_player	player;
}	t_all;

void	common_err(int err);
void	map_err(int err);
void	clean(t_all *data);

int		get_height_file(char *file_name);
int		get_width_file(char *file_name);
int		get_height_arr(char **arr);
int		get_width_arr(char *arr);

void	read_file(char *file_name, t_all *data);
void	check_map_validation(t_all *data);
void	check_sympols(char **map);
void	check_player(t_all *data);
void	check_map_spaces(t_all *data, char s);
int		valid_symbol(char **arr, int i, int j, char s);
void	check_borders(char **map, int i);
void	check_plr_lock(t_all *data);

void	my_mlx_pixel_put(t_win *win, int x, int y, int color);

#endif
