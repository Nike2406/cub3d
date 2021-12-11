/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:08:27 by prochell          #+#    #+#             */
/*   Updated: 2021/12/11 21:41:21 by prochell         ###   ########.fr       */
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
# define INVAL_COLOR	4
# define INVAL_TEXTURE	5

# define ERR_PLAYER		1
# define ERR_SYMBOL		2
# define ERR_MAP		3
# define ERR_PLR_LOCK	4
# define ERR_NO_MAP		5

# define TEXWIDTH		64
# define TEXHEIGHT		64
# define WIN_WIDTH		640
# define WIN_HEIGHT		480

typedef struct s_player
{
	int		x;
	int		y;
	char	plr_direction;
}	t_player;

typedef struct s_img
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

typedef struct s_info
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	void	*mlx;
	void	*win;
	t_img	img;
	int		buf[WIN_HEIGHT][WIN_WIDTH];
	int		**texture;
	char	**texture_addr;
	int		floor_color;
	int		ceil_color;
	double	movespeed;
	double	rotspeed;
	char	**map_arr;
	int		zoom;
}	t_info;

typedef struct s_raycasting
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		texnum;
	double	wallx;
	int		texx;
	double	step;
	double	texpos;
}	t_raycasting;

typedef struct s_all
{
	t_info			*info;
	t_player		player;
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
float	mod(float a);
float	max(float a, float b);
void	double_int_arr_fill(int **arr, int first, int second);

void	parsing_qube(char *file_name, t_all *data);
int		parse_colors(t_all *data, char *str);
int		parse_textures(t_all *data, char *str);
void	check_map_validation(t_all *data);
void	check_sympols(char **map);
void	check_player(t_all *data);
void	check_map_spaces(t_all *data, char s);
int		valid_symbol(char **arr, int i, int j, char s);
void	check_borders(char **map, int i);

void	data_preset(t_all *data);
int		start_lodev_version(t_info *info, t_player player);
int		main_loop(t_info *info);
int		key_press_y(int key, t_info *info);
void	position_preset(t_info *info, t_player player);
void	directon_preset_1(t_info *info, t_player player);
void	directon_preset_2(t_info *info, t_player player);

void	raycasting_preset(t_raycasting *ray_c, t_info *info, int x);
void	get_side_position(t_raycasting *ray_c, t_info *info);
void	get_ray_hit(t_raycasting *ray_c, t_info *info);
void	get_texture_params(t_raycasting *ray_c, t_info *info);
void	fill_verticals(t_raycasting *ray_c, t_info *info, int x);

void	print_map(t_info *info);
void	print_player(t_info *info, int start_x, int start_y, int color);
void	print_rect(t_info *info, int start_x, int start_y, int color);

#endif
