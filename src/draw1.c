/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:41:16 by prochell          #+#    #+#             */
/*   Updated: 2021/11/21 16:14:36 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	bresenham(t_all *data, t_point *p, t_point *p1)
// {
// 	double	x_step;
// 	double	y_step;
// 	long	max;

// 	// get_position(data, p, p1);
// 	p->x *= data->win->zoom;
// 	p->y *= data->win->zoom;
// 	p1->x *= data->win->zoom;
// 	p1->y *= data->win->zoom;

// 	x_step = p1->x - p->x;
// 	y_step = p1->y - p->y;
// 	max = MAX(MOD(x_step), MOD(y_step));
// 	x_step /= max;
// 	y_step /= max;

// 	while ((int)(p->x - p1->x) || (int)(p->y - p1->y))
// 	{
// 		if ((p->x >= 0 && p->x <= data->win->img_width) && \
// 		(p->y >= 0 && p->y < data->win->img_height))
// 			my_mlx_pixel_put(data->win, p->x, p->y, 0xFFFFFF);
// 		p->x += x_step;
// 		p->y += y_step;
// 	}
// }

// void	pre_brase(int f, t_point *p, t_point *p1, int x, int y)
// {
// 	p->x = x;
// 	p->y = y;
// 	if (!f)
// 	{
// 		p1->x = p->x + 1;
// 		p1->y = p->y;
// 	}
// 	else
// 	{
// 		p1->x = p->x;
// 		p1->y = p->y + 1;
// 	}
// }

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
}

// void	draw(t_all *data)
// {
// 	t_point	p;
// 	t_point	p1;
// 	int	x;
// 	int	y;
// 	int	height;
// 	int	width;

// 	height = get_height_arr(data->map);
// 	y = -1;
// 	while (++y < height)
// 	{
// 		x = -1;
// 		width = get_width_arr(data->map[y]);
// 		while (++x < width)
// 		{
// 			if (x < width - 1)
// 			{
// 				pre_brase(0, &p, &p1, x, y);
// 				bresenham(data, &p, &p1);
// 			}
// 			if (y < height - 1)
// 			{
// 				pre_brase(1, &p, &p1, x, y);
// 				bresenham(data, &p, &p1);
// 			}
// 		}
// 	}
// }
