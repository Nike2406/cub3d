/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: signacia <signacia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:08:27 by prochell          #+#    #+#             */
/*   Updated: 2021/12/08 11:42:59 by signacia         ###   ########.fr       */
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
# define INVALID_COLOR	4

# define ERR_PLAYER		1
# define ERR_SYMBOL		2
# define ERR_MAP		3
# define ERR_PLR_LOCK	4
# define ERR_NO_MAP		5

#define texWidth		64
#define texHeight		64
#define mapWidth		24
#define mapHeight		24
#define win_width		640
#define win_height		480

typedef struct s_player
{
	int		x;
	int		y;
	char	plr_direction;
}	t_player;

typedef struct s_map
{
	int		width;
	int		height;
}	t_map;

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
	char	**map_arr;
}	t_info;

typedef struct	s_raycasting
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		texNum;
	double	wallX;
	int		texX;
	double	step;
	double	texPos;
}	t_raycasting;

typedef struct s_all
{
	t_info			*info;
	t_player		player;
	t_map			map;
	t_raycasting	*raycasting;
}	t_all;

void	common_err(int err);
void	map_err(int err);
int		keys_err(int code);
void	clean(t_all *data);

int		get_height_file(char *file_name);
int		get_width_file(char *file_name);
int		get_height_arr(char **arr);
int		get_width_arr(char *arr);
float	MOD(float a);
float	MAX(float a, float b);
void	double_int_arr_fill(int **arr, int first, int second);

void	parsing_qube(char *file_name, t_all *data);
void	check_map_validation(t_all *data);
void	check_sympols(char **map);
void	check_player(t_all *data);
void	check_map_spaces(t_all *data, char s);
int		valid_symbol(char **arr, int i, int j, char s);
void	check_borders(char **map, int i);

void	data_preset(t_all *data);
int		start_lodev_version(t_info *info, t_player player);
int		key_press_X(int key, t_info *info);
int		key_press_Y(int key, t_info *info);
void	position_preset(t_info *info, t_player player);
void	directon_preset_1(t_info *info, t_player player);
void	directon_preset_2(t_info *info, t_player player);

void	raycasting_preset(t_raycasting *ray_c, t_info *info, int x);
void	get_side_position(t_raycasting *ray_c, t_info *info);
void	get_ray_hit(t_raycasting *ray_c, t_info *info);
void	get_texture_params(t_raycasting *ray_c, t_info *info);
void	get_texture_side(t_raycasting *ray_c);
void	fill_verticals(t_raycasting *ray_c, t_info *info, int x);

#endif
