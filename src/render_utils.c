/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:48:20 by prochell          #+#    #+#             */
/*   Updated: 2021/12/05 20:09:23 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	my_mlx_pixel_put(t_info *win, int x, int y, int color) // test
// {
// 	char	*dst;

// 	dst = win->img.addr + (y * win->img.size_l + x * (win->img.bpp / 8));
// 	*(unsigned int *)dst = color;
// }

// void	preset_player_direction(t_all *data, char s)
// {
// 	if (s == 'N')
// 		data->player.plr_direction = M_PI / 2;
// 	else if (s == 'E')
// 		data->player.plr_direction = 0;
// 	else if (s == 'S')
// 		data->player.plr_direction = 3 * M_PI / 2;
// 	else if (s == 'W')
// 		data->player.plr_direction = M_PI;
// }

// void data_preset(t_all *data)
// {
// 	data->win->img_width = 1280;
// 	data->win->img_height = 720;
// }

void	position_preset(t_info *info, t_player player)
{
	float m = 0;
	float n = 0;

	if (info->map_arr[player.y + 1][player.x] == '1' || \
		info->map_arr[player.y - 1][player.x] == '1')
		m = 0.5;
	if (info->map_arr[player.y][player.x - 1] == '1' || \
		info->map_arr[player.y][player.x - 1] == '1')
		n = 0.5;
	info->posX = player.x + n;
	info->posY = player.y + m;
}

void	directon_preset_1(t_info *info, t_player player)
{
	// Направление
	if (player.plr_direction == 'S')
	{
		info->dirX = 0.0;
		info->dirY = 1.0;
		info->planeX = -0.66;
		info->planeY = 0.0;
	}
	else if (player.plr_direction == 'E')
	{
		info->dirX = -1.0;
		info->dirY = 0.0;
		info->planeX = 0.0;
		info->planeY = -0.66;
	}
	else
		directon_preset_2(info, player);
}

void	directon_preset_2(t_info *info, t_player player)
{
	if (player.plr_direction == 'N')
	{
		info->dirX = 0.0;
		info->dirY = -1.0;
		info->planeX = 0.66;
		info->planeY = 0.0;
	}
	else if (player.plr_direction == 'W')
	{
		info->dirX = 1.0;
		info->dirY = 0.0;
		info->planeX = 0.0;
		info->planeY = 0.66;
	}
}
