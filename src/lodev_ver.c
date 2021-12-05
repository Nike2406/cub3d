/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lodev_ver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:53:36 by prochell          #+#    #+#             */
/*   Updated: 2021/12/05 14:48:07 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int key, t_info *info)
{
	if (key == 13)
	{
		if (ft_strchr(" 0",info->world_map[(int)(info->posY)][(int)(info->posX + info->dirX * info->moveSpeed)]))
			info->posX += info->dirX * info->moveSpeed;
		if (ft_strchr(" 0",info->world_map[(int)(info->posY + info->dirY * info->moveSpeed)][(int)(info->posX)]))
			info->posY += info->dirY * info->moveSpeed;
		// if (!info->world_map[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
	}
	//move backwards if no wall behind you
	if (key == 1)
	{
		// if (!info->world_map[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
		if (ft_strchr(" 0", info->world_map[(int)(info->posY)][(int)(info->posX - info->dirX * info->moveSpeed)]))
			info->posX -= info->dirX * info->moveSpeed;
		// if (!info->world_map[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
		if (ft_strchr(" 0", info->world_map[(int)(info->posY - info->dirY * info->moveSpeed)][(int)(info->posX)]))
			info->posY -= info->dirY * info->moveSpeed;
	}
	//rotate to the left
	if (key == 0)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
	}
	//rotate to the right
	if (key == 2)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	if (key == 53)
		exit(0);
	printf("x - %f, y - %f\n", info->posX, info->posY);
	return (0);
}

void	draw_lodev(t_info *info)
{
	int	x;
	int	y;

	// y = 0;
	// while (y <= y1)
	// {
	// 	printf("%s\n", info->win);
	// 	my_mlx_pixel_put(info->win, x, y, 0x000000);
	// 	y++;
	// }
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
	int	x;
	int	y;

	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
	int texNum;
	double wallX;
	int texX;
	double step;
	double texPos;

	x = 0;
	while (x < win_width)
	{
		cameraX = 2 * x / (double)win_width - 1;
		rayDirX = info->dirX + info->planeX * cameraX;
		rayDirY = info->dirY + info->planeY * cameraX;
		mapX = (int)info->posX;
		mapY = (int)info->posY;
		deltaDistX = fabs(1 / rayDirX);
		deltaDistY = fabs(1 / rayDirY);
		hit = 0;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (info->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
		}

		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = '0';
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = '1';
			}
			if (info->world_map[mapY][mapX] == '1')
				hit = 1;
		}

		if (side == '0')
			 perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		// if (side == '0')
		// 	perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		// else
		// 	perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;
		lineHeight = (int)(win_height / perpWallDist);
		drawStart = -lineHeight / 2 + win_height / 2;
		if(drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + win_height / 2;
		if(drawEnd >= win_height)
			drawEnd = win_height - 1;
		texNum = info->world_map[mapY][mapX];
		if (side == '0')
			wallX = info->posY + perpWallDist * rayDirY;
		else
			wallX = info->posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		texX = (int)(wallX * (double)texWidth);
		if (side == '0' && rayDirX > 0)
			texX = texWidth - texX - 1;
		if (side == '1' && rayDirY < 0)
			texX = texWidth - texX - 1;
		step = 1.0 * texHeight / lineHeight;
		texPos = (drawStart - win_height / 2 + lineHeight / 2) * step;

		int	texY;
		int	color;
		y = 0;
		while (y < drawStart)
		{
			info->buf[y][x] = 0xFF0000;
			y++;
		}
		y = drawStart;
		while (y <= drawEnd)
		{
			texY = (int)texPos & (texHeight - 1);
			texPos += step;
			color = info->texture[texNum % 8][texHeight * texY + texX];
			if (side == '1')
				color = (color >> 1) & 8355711;
			info->buf[y][x] = color;
			y++;
		}
		while (y < win_height)
		{
			info->buf[y][x] = 0x00FF00;
			y++;
		}
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
	// int size;
	int	y;
	// printf("%s\n", path);
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);

	// Check it out!
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

	load_image(info, info->texture[0], "./textures/eagle.xpm", &img);
	load_image(info, info->texture[1], "./textures/redbrick.xpm", &img);
	load_image(info, info->texture[2], "./textures/purplestone.xpm", &img);
	load_image(info, info->texture[3], "./textures/greystone.xpm", &img);
	load_image(info, info->texture[4], "./textures/bluestone.xpm", &img);
	load_image(info, info->texture[5], "./textures/mossy.xpm", &img);
	load_image(info, info->texture[6], "./textures/wood.xpm", &img);
	load_image(info, info->texture[7], "./textures/colorstone.xpm", &img);
}

int	start_lodev_version(char **world_map, t_all *data)
{
	t_info	info;
	int		i;
	int		j;
	// (void)data;

	float m = 0;
	float n = 0;
	info.mlx = mlx_init();
	// if (data->map_arr[data->player.y + 1][data->player.x] == '1')
	// 	m = -0.5;
	// if (data->map_arr[data->player.y][data->player.x + 1] == '1')
	// 	n = -0.5;
	if (data->map_arr[data->player.y - 1][data->player.x] == '1')
		m = 0.5;
	if (data->map_arr[data->player.y][data->player.x - 1] == '1')
		n = 0.5;
	info.posX = data->player.x + n;
	info.posY = data->player.y + m;
	// Направление
	if (data->player.plr_direction == 'S')
	{
		info.dirX = 0.0;
		info.dirY = 1.0;
		info.planeX = -0.66;
		info.planeY = 0.0;
	}
	else if (data->player.plr_direction == 'E')
	{
		info.dirX = -1.0;
		info.dirY = 0.0;
		info.planeX = 0.0;
		info.planeY = -0.66;
	}
	else if (data->player.plr_direction == 'N')
	{
		info.dirX = 0.0;
		info.dirY = -1.0;
		info.planeX = 0.66;
		info.planeY = 0.0;
	}
	else if (data->player.plr_direction == 'W')
	{
		info.dirX = 1.0;
		info.dirY = 0.0;
		info.planeX = 0.0;
		info.planeY = 0.66;
	}
	info.world_map = world_map;

	i = -1;
	while (++i < win_height)
	{
		j = -1;
		while (++j < win_width)
			info.buf[i][j] = 0;
	}

	if (!(info.texture = (int **)malloc(sizeof(int *) * 8)))
		return (-1);
	// ft_calloc(sizeof(int *), 8);
	i = -1;
	while (++i < 8)
	{
		// ft_calloc(sizeof(int), texHeight * texWidth);
		if (!(info.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
			 return (-1);
	}
	// Заполнение исходных текстур 0-ми
	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < texWidth * texHeight)
			info.texture[i][j] = 0;
	}
	load_texture(&info);
	info.moveSpeed = 0.08;
	info.rotSpeed = 0.08;
	info.win = mlx_new_window(info.mlx, win_width, win_height, "cub3D");
	info.img.img = mlx_new_image(info.mlx, win_width, win_height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, 2, 0, &key_press, &info);

	mlx_loop(info.mlx);
	return (0);
}
