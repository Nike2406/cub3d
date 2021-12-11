/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: signacia <signacia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:48:20 by prochell          #+#    #+#             */
/*   Updated: 2021/12/11 16:27:56 by signacia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	position_preset(t_info *info, t_player player)
{
	float	m;
	float	n;

	m = 0;
	n = 0;
	if (info->map_arr[player.y + 1][player.x] == '1' || \
		info->map_arr[player.y - 1][player.x] == '1')
		m = 0.5;
	if (info->map_arr[player.y][player.x - 1] == '1' || \
		info->map_arr[player.y][player.x - 1] == '1')
		n = 0.5;
	info->posx = player.x + n;
	info->posy = player.y + m;
}

void	directon_preset_1(t_info *info, t_player player)
{
	if (player.plr_direction == 'S')
	{
		info->dirx = 0.0;
		info->diry = 1.0;
		info->planex = -0.66;
		info->planey = 0.0;
	}
	else if (player.plr_direction == 'E')
	{
		info->dirx = -1.0;
		info->diry = 0.0;
		info->planex = 0.0;
		info->planey = -0.66;
	}
	else
		directon_preset_2(info, player);
}

void	directon_preset_2(t_info *info, t_player player)
{
	if (player.plr_direction == 'N')
	{
		info->dirx = 0.0;
		info->diry = -1.0;
		info->planex = 0.66;
		info->planey = 0.0;
	}
	else if (player.plr_direction == 'W')
	{
		info->dirx = 1.0;
		info->diry = 0.0;
		info->planex = 0.0;
		info->planey = 0.66;
	}
}
