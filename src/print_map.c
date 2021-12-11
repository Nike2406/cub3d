/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:15:13 by prochell          #+#    #+#             */
/*   Updated: 2021/12/11 21:41:48 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_player(t_info *info, int start_x, int start_y, int color)
{
	info->buf[start_y][start_x] = color;
	info->buf[start_y - 1][start_x] = color;
	info->buf[start_y - 1][start_x - 1] = color;
	info->buf[start_y - 1][start_x + 1] = color;
	info->buf[start_y - 2][start_x] = color;
	info->buf[start_y + 1][start_x] = color;
	info->buf[start_y + 1][start_x - 1] = color;
	info->buf[start_y + 1][start_x + 1] = color;
	info->buf[start_y + 2][start_x] = color;
	info->buf[start_y][start_x - 1] = color;
	info->buf[start_y][start_x - 2] = color;
	info->buf[start_y][start_x + 1] = color;
	info->buf[start_y][start_x + 2] = color;
}

void	print_rect(t_info *info, int start_x, int start_y, int color)
{
	int	x;
	int	y;

	y = start_y;
	while (y < start_y + info->zoom)
	{
		x = start_x;
		while (x < start_x + info->zoom)
		{
			info->buf[y][x] = color;
			x++;
		}
		y++;
	}
}

void	print_map(t_info *info)
{
	int	x;
	int	y;
	int	height;
	int	width;

	info->zoom = WIN_HEIGHT / 70;
	y = 0;
	height = get_height_arr(info->map_arr);
	while (y < height)
	{
		width = get_width_arr(info->map_arr[y]);
		x = 0;
		while (x < width && info->map_arr[y][x] != '\0')
		{
			if (info->map_arr[y][x] == '1')
			{
				print_rect(info, x * info->zoom + (WIN_WIDTH / 100), \
					y * info->zoom + (WIN_HEIGHT / 100), 0xFFFFFF);
			}
			x++;
		}
		y++;
	}
	print_player(info, info->posx * info->zoom + (WIN_WIDTH / 100), \
		info->posy * info->zoom + (WIN_HEIGHT / 100), 0x00FF00);
}
