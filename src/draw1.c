/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:41:16 by prochell          #+#    #+#             */
/*   Updated: 2021/11/21 18:50:37 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_player(t_win *win, int start_x, int start_y, int color)
{
	int	y;
	int	x;

	start_y = start_y + win->zoom / 4;
	start_x = start_x + win->zoom / 4;
	y = start_y;
	while (y < win->zoom / 2 + start_y)
	{
		x = start_x;
		while (x < win->zoom / 2 + start_x)
		{
			my_mlx_pixel_put(win, x, y, color);
			x++;
		}
		y++;
	}
}

void	print_rect(t_win *win, int start_x, int start_y, int color)
{
	int	x;
	int	y;

	y = start_y;
	while (y < start_y + win->zoom)
	{
		x = start_x;
		while (x < start_x + win->zoom)
		{
			my_mlx_pixel_put(win, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw(t_all *data)
{
	int	x;
	int	y;
	int	height;
	int	width;

	y = 0;
	height = get_height_arr(data->map);
	while (y < height)
	{
		width = get_width_arr(data->map[y]);
		x = 0;
		while (x < width && data->map[y][x]!= '\0')
		{
			if (data->map[y][x] == '1')
				print_rect(data->win, x * data->win->zoom, \
					y * data->win->zoom, 0xFFFFFF);
			x++;
		}
		y++;
	}
	print_player(data->win, data->player.y * data->win->zoom + data->win->shift_y, \
		data->player.x * data->win->zoom + data->win->shift_x, 0x00FF00);
}
