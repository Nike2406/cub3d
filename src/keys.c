/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:07:48 by prochell          #+#    #+#             */
/*   Updated: 2021/12/05 20:01:28 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press_Y(int key, t_info *info)
{
	if (key == 13 || key == 126)
	{
		if (ft_strchr(" 0",info->map_arr[(int)(info->posY)][(int)(info->posX + info->dirX * info->moveSpeed)]))
			info->posX += info->dirX * info->moveSpeed;
		if (ft_strchr(" 0",info->map_arr[(int)(info->posY + info->dirY * info->moveSpeed)][(int)(info->posX)]))
			info->posY += info->dirY * info->moveSpeed;
		// if (!info->map_arr[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
	}
	//move backwards if no wall behind you
	if (key == 1 || key == 125)
	{
		// if (!info->map_arr[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
		if (ft_strchr(" 0", info->map_arr[(int)(info->posY)][(int)(info->posX - info->dirX * info->moveSpeed)]))
			info->posX -= info->dirX * info->moveSpeed;
		// if (!info->map_arr[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
		if (ft_strchr(" 0", info->map_arr[(int)(info->posY - info->dirY * info->moveSpeed)][(int)(info->posX)]))
			info->posY -= info->dirY * info->moveSpeed;
	}
	else
		key_press_X(key, info);
	// printf("key - %d\n", key);
	// printf("x - %f, y - %f\n", info->posX, info->posY);
	return (0);
}

int	key_press_X(int key, t_info *info)
{
	//rotate to the left
	if (key == 0 || key == 123)
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
	if (key == 2 || key == 124)
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
	return (0);
}
