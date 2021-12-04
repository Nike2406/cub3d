// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   draw1.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/11/21 12:41:16 by prochell          #+#    #+#             */
// /*   Updated: 2021/11/28 19:43:45 by prochell         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../cub3d.h"

// void	print_player(t_win *win, int start_x, int start_y, int color)
// {
// 	int	y;
// 	int	x;

// 	// впозицонирование точки по центру
// 	start_y = start_y + win->zoom / 4;
// 	start_x = start_x + win->zoom / 4;
// 	y = start_y;
// 	while (y < win->zoom / 2 + start_y)
// 	{
// 		x = start_x;
// 		while (x < win->zoom / 2 + start_x)
// 		{
// 			my_mlx_pixel_put(win, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	player_layer(t_all *data)
// {
// 	int	tmp_x;
// 	int	tmp_y;

// 	tmp_y = data->player.y;
// 	tmp_x = data->player.x;
// 	while (data->map[(int)(tmp_y / data->win->zoom)]\
// 		[(int)(tmp_x / data->win->zoom)] != '1')
// 	{
// 		// printf("x-%d, y-%d", data->player.x, data->player.y);
// 		tmp_x += cos(data->player.plr_direction);
// 		tmp_y += sin(data->player.plr_direction);
// 		my_mlx_pixel_put(data->win, tmp_x, tmp_y, 0x00FF00);
// 	}
// }

// void	print_rect(t_win *win, int start_x, int start_y, int color)
// {
// 	int	x;
// 	int	y;

// 	y = start_y;
// 	while (y < start_y + win->zoom)
// 	{
// 		x = start_x;
// 		while (x < start_x + win->zoom)
// 		{
// 			my_mlx_pixel_put(win, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw(t_all *data)
// {
// 	int	x;
// 	int	y;
// 	int	height;
// 	int	width;

// 	y = 0;
// 	height = get_height_arr(data->map);
// 	while (y < height)
// 	{
// 		width = get_width_arr(data->map[y]);
// 		x = 0;
// 		while (x < width && data->map[y][x]!= '\0')
// 		{
// 			if (data->map[y][x] == '1')
// 				print_rect(data->win, x * data->win->zoom, \
// 					y * data->win->zoom, 0xFFFFFF);
// 			x++;
// 		}
// 		y++;
// 	}
// 	print_player(data->win, data->player.y * data->win->zoom + data->win->shift_y, \
// 		data->player.x * data->win->zoom + data->win->shift_x, 0x00FF00);
// 	player_layer(data);
// }
