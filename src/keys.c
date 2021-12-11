/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: signacia <signacia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:07:48 by prochell          #+#    #+#             */
/*   Updated: 2021/12/11 17:50:31 by signacia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	key_press_xx(int key, t_info *info)
{
	double	old_dx;
	double	old_px;

	if (key == 2 || key == 124)
	{
		old_dx = info->dirx;
		info->dirx = info->dirx * cos(info->rotspeed)
			- info->diry * sin(info->rotspeed);
		info->diry = old_dx * sin(info->rotspeed)
			+ info->diry * cos(info->rotspeed);
		old_px = info->planex;
		info->planex = info->planex * cos(info->rotspeed)
			- info->planey * sin(info->rotspeed);
		info->planey = old_px * sin(info->rotspeed)
			+ info->planey * cos(info->rotspeed);
	}
	if (key == 53)
		exit(0);
	return (0);
}

static int	key_press_x(int key, t_info *info)
{
	double	old_dx;
	double	old_px;

	if (key == 0 || key == 123)
	{
		old_dx = info->dirx;
		info->dirx = info->dirx * cos(-info->rotspeed)
			- info->diry * sin(-info->rotspeed);
		info->diry = old_dx * sin(-info->rotspeed)
			+ info->diry * cos(-info->rotspeed);
		old_px = info->planex;
		info->planex = info->planex * cos(-info->rotspeed)
			- info->planey * sin(-info->rotspeed);
		info->planey = old_px * sin(-info->rotspeed)
			+ info->planey * cos(-info->rotspeed);
	}
	else
		key_press_xx(key, info);
	return (0);
}

int	key_press_y(int key, t_info *info)
{
	if (key == 13 || key == 126)
	{
		if (ft_strchr(" 0", info->map_arr[(int)(info->posy)][(int)(info->posx
			+ info->dirx * info->movespeed)]))
			info->posx += info->dirx * info->movespeed;
		if (ft_strchr(" 0", info->map_arr[(int)(info->posy + info->diry
					* info->movespeed)][(int)(info->posx)]))
			info->posy += info->diry * info->movespeed;
	}
	else if (key == 1 || key == 125)
	{
		if (ft_strchr(" 0", info->map_arr[(int)(info->posy)][(int)(info->posx
			- info->dirx * info->movespeed)]))
			info->posx -= info->dirx * info->movespeed;
		if (ft_strchr(" 0", info->map_arr[(int)(info->posy - info->diry
					* info->movespeed)][(int)(info->posx)]))
			info->posy -= info->diry * info->movespeed;
	}
	else
		key_press_x(key, info);
	return (0);
}
