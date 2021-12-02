/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lodev_untext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:53:36 by prochell          #+#    #+#             */
/*   Updated: 2021/12/02 20:14:47 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main_loop(t_info *info);

int	world_map[24][24] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						};

int	key_press(int key, t_info *info)
{
	if (key == 13)
	{
		if (!world_map[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if (!world_map[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
		main_loop(info);
	}
	//move backwards if no wall behind you
	if (key == 1)
	{
		if (!world_map[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if (!world_map[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
		main_loop(info);
	}
	//rotate to the right
	if (key == 2)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
		main_loop(info);
	}
	//rotate to the left
	if (key == 0)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
		main_loop(info);
	}
	if (key == 53)
		exit(0);
	return (0);
}

void	verLine(t_info *info, int x, int y1, int y2, int color)
{
	int	y;


	// y = y1;
	y = 0;
	while (y <= y1)
	{
		mlx_pixel_put(info->mlx, info->win, x, y, 0x000000);
		y++;
	}
	// y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(info->mlx, info->win, x, y, color);
		y++;
	}
	while (y2 <= win_height)
	{
		mlx_pixel_put(info->mlx, info->win, x, y2, 0x000000);
		y2++;
	}
}

void	calc(t_info *info)
{
	int	x;

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
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (world_map[mapY][mapX] > 0) // Here!!!!!!!!!!!!!
				hit = 1;
		}


		// stamp
		if (side == 0) // Here!!!!!!!!!!!!!!!
			perpWallDist = sideDistX - deltaDistX;//(mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = sideDistY - deltaDistY;//(mapY - info->posY + (1 - stepY) / 2) / rayDirY;
		lineHeight = (int)(win_height / perpWallDist);
		drawStart = -lineHeight / 2 + win_height / 2;
		if(drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + win_height / 2;
		if(drawEnd >= win_height)
			drawEnd = win_height - 1;

		int	color;
		if (world_map[mapY][mapX] == 1)
			color = 0xFF0000;
		else if (world_map[mapY][mapX] == 2)
			color = 0x00FF00;
		else if (world_map[mapY][mapX] == 3)
			color = 0x0000FF;
		else if (world_map[mapY][mapX] == 4)
			color = 0xFFFFFF;
		else
			color = 0xFFFFFF;

		if (side == 1)
			color = color / 2;

		verLine(info, x, drawStart, drawEnd, color);
		x++;
	}
}

int	main_loop(t_info *info)
{
	calc(info);
	// mlx_put_image_to_window(info->mlx, info->win, &info->img, 0, 0);
	return (0);
}

int	start_lodev_version(char **world_map, t_all *data)
{
	t_info	info;
	info.mlx = mlx_init();
	(void)data;
	(void)world_map;

	info.posX = 12;
	info.posY = 2;
	info.dirX = -1.0;
	info.dirY = 0.0;
	info.planeX = 0.0;
	info.planeY = 0.66;
	info.moveSpeed = 0.15;
	info.rotSpeed = 0.15;

	// info.world_map = world_map;

	info.win = mlx_new_window(info.mlx, win_width, win_height, "cub3D");
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, 2, 0, &key_press, &info);

	mlx_loop(info.mlx);
	return (0);
}
