/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:48:20 by prochell          #+#    #+#             */
/*   Updated: 2021/11/28 19:33:18 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_win *win, int x, int y, int color) // test
{
	char	*dst;

	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void data_preset(t_all *data)
{
	data->win->img_width = 1280;
	data->win->img_height = 720;
	data->win->zoom = 20;
	data->win->shift_x = 0;
	data->win->shift_y = 0;
	// data->win->render_flag = 0;
}

void	preset_player_direction(t_all *data, char s)
{
	if (s == 'N')
		data->player.plr_direction = M_PI / 2;
	else if (s == 'E')
		data->player.plr_direction = 0;
	else if (s == 'S')
		data->player.plr_direction = 3 * M_PI / 2;
	else if (s == 'W')
		data->player.plr_direction = M_PI;
}
