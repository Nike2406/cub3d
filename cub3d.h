/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:08:27 by prochell          #+#    #+#             */
/*   Updated: 2021/12/04 22:07:42 by prochell         ###   ########.fr       */
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

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	int		x;
	int		y;
	double	plr_direction;
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

	int		zoom;

	double	shift_x;
	double	shift_y;
	int		render_flag;
}	t_win;

typedef struct s_all
{
	t_win		*win;
	char		**map;
	t_player	player;
}	t_all;

/*			Lodev version			*/
// Start
/*-------------------------------------*/
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24
#define win_width 640
#define win_height 480

typedef struct	s_img
{
	void	*img;
	int		*data;
	char	*addr;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct	s_info
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	void	*mlx;
	void	*win;
	t_img	img;
	int		buf[win_height][win_width];
	int		**texture;
	double	moveSpeed;
	double	rotSpeed;
	//map
	char	**world_map;
}				t_info;

int	start_lodev_version(char **world_map, t_all *data);
/*-------------------------------------*/
// End

void	common_err(int err);
void	map_err(int err);
void	clean(t_all *data);

int		get_height_file(char *file_name);
int		get_width_file(char *file_name);
int		get_height_arr(char **arr);
int		get_width_arr(char *arr);
float	MOD(float a);
float	MAX(float a, float b);

void	read_file(char *file_name, t_all *data);
void	check_map_validation(t_all *data);
void	check_sympols(char **map);
void	check_player(t_all *data);
void	check_map_spaces(t_all *data, char s);
int		valid_symbol(char **arr, int i, int j, char s);
void	check_borders(char **map, int i);
void	check_plr_lock(t_all *data);
void	preset_player_direction(t_all *data, char s);

void	data_preset(t_all *data);
void	first_render(t_win *win, t_all *data);
void	render(t_win *win, t_all *data);
void	my_mlx_pixel_put(t_info *win, int x, int y, int color);
void	get_hook(t_all *data);
int		deal_key(int key, t_all *data);
int		keys_err(int code);

// void	draw(t_all *data);

#endif
