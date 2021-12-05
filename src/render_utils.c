/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:48:20 by prochell          #+#    #+#             */
/*   Updated: 2021/12/05 18:52:12 by prochell         ###   ########.fr       */
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
