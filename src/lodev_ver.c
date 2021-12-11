/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lodev_ver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:53:36 by prochell          #+#    #+#             */
/*   Updated: 2021/12/11 18:15:09 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_lodev(t_info *info)
{
	int	x;
	int	y;

	y = -1;
	while (++y < win_height)
	{
		x = -1;
		while (++x < win_width)
			info->img.data[y * win_width + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	calc(t_info *info)
{
	int				x;
	t_raycasting	*raycasting;

	if (!(raycasting = (t_raycasting *)malloc(sizeof(t_raycasting))))
		common_err(ERR_MALLOC);
	x = 0;
	while (x < win_width)
	{
		raycasting_preset(raycasting, info, x);
		get_side_position(raycasting, info);
		get_ray_hit(raycasting, info);
		get_texture_params(raycasting, info);
		fill_verticals(raycasting, info, x);
		x++;
	}
}

int	main_loop(t_info *info)
{
	calc(info);
	draw_lodev(info);
	return (0);
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);

	if (!img->img)
		exit(1);
	img->endian = 0;
	img->bpp = 4;
	img->size_l = img->img_width;

	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	y = -1;
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;
	// int		i;

	// i = -1;

	load_image(info, info->texture[0], "./textures/watM_64.xpm", &img);
	load_image(info, info->texture[1], "./textures/cry_64.xpm", &img);
	load_image(info, info->texture[2], "./textures/watG_64.xpm", &img);
	load_image(info, info->texture[3], "./textures/agreed_64.xpm", &img);
	load_image(info, info->texture[4], "./textures/bluestone.xpm", &img);
	// load_image(info, info->texture[5], "./textures/mossy.xpm", &img);
	load_image(info, info->texture[5], "./textures/wood.xpm", &img);
	// load_image(info, info->texture[7], "./textures/colorstone.xpm", &img);
}

int	start_lodev_version(t_info *info, t_player player)
{
	int		i;
	int		j;

	info->mlx = mlx_init();
	position_preset(info, player);
	directon_preset_1(info, player);

	// double_int_arr_fill(info->buf, win_height, win_width);

	// Можно вырезать
	i = -1;
	while (++i < win_height)
	{
		j = -1;
		while (++j < win_width)
			info->buf[i][j] = 0;
	}

	if (!(info->texture = (int **)malloc(sizeof(int *) * 8)))
		common_err(ERR_MALLOC);
	i = -1;
	while (++i < 8)
	{
		// ft_calloc(sizeof(int), texHeight * texWidth);
		if (!(info->texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
			 common_err(ERR_MALLOC);
	}
	// Можно вырезать
	double_int_arr_fill(info->texture, 8, texWidth * texHeight);

	// Заполнение исходных текстур 0-ми
	// i = -1;
	// while (++i < 8)
	// {
	// 	j = -1;
	// 	while (++j < texWidth * texHeight)
	// 		info->texture[i][j] = 0;
	// }
	load_texture(info);
	info->moveSpeed = 0.08;
	info->rotSpeed = 0.08;
	info->win = mlx_new_window(info->mlx, win_width, win_height, "cub3D");
	info->img.img = mlx_new_image(info->mlx, win_width, win_height);
	info->img.data = (int *)mlx_get_data_addr(info->img.img, &info->img.bpp, &info->img.size_l, &info->img.endian);
	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_hook(info->win, 17, 0, keys_err, info);
	mlx_hook(info->win, 2, 0, &key_press_Y, info);
	mlx_loop(info->mlx);
	return (0);
}
