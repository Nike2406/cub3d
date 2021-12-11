/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lodev_ver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:53:36 by prochell          #+#    #+#             */
/*   Updated: 2021/12/11 21:28:06 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(info->mlx, path,
			&img->img_width, &img->img_height);
	if (!img->img)
		common_err(INVAL_TEXTURE);
	img->endian = 0;
	img->bpp = 4;
	img->size_l = img->img_width;
	img->data = (int *)mlx_get_data_addr(img->img,
			&img->bpp, &img->size_l, &img->endian);
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

	load_image(info, info->texture[0], info->texture_addr[0], &img);
	load_image(info, info->texture[1], info->texture_addr[1], &img);
	load_image(info, info->texture[2], info->texture_addr[2], &img);
	load_image(info, info->texture[3], info->texture_addr[3], &img);
}

int	start_lodev_version(t_info *info, t_player player)
{
	int		i;

	info->mlx = mlx_init();
	position_preset(info, player);
	directon_preset_1(info, player);
	info->texture = (int **)malloc(sizeof(int *) * 8);
	if (!info->texture)
		common_err(ERR_MALLOC);
	i = -1;
	while (++i < 4)
	{
		info->texture[i] = (int *)malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH));
		if (!info->texture[i])
			common_err(ERR_MALLOC);
	}
	load_texture(info);
	info->win = mlx_new_window(info->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	info->img.img = mlx_new_image(info->mlx, WIN_WIDTH, WIN_HEIGHT);
	info->img.data = (int *)mlx_get_data_addr(info->img.img,
			&info->img.bpp, &info->img.size_l, &info->img.endian);
	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_hook(info->win, 17, 0, keys_err, info);
	mlx_hook(info->win, 2, 0, key_press_y, info);
	mlx_loop(info->mlx);
	return (0);
}
