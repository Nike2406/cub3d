/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:22:16 by prochell          #+#    #+#             */
/*   Updated: 2021/11/14 21:10:14 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render(t_win *win)
{
	int		x;
	int		y;

	win->img_width = 640;
	win->img_height = 480;
	x = 100;
	y = 100;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->img_width, \
		win->img_height, "cub3d");
	win->img = mlx_new_image(win->mlx, win->img_width, \
		win->img_height);
	win->addr = mlx_get_data_addr(win->img, &win->bits_per_pixel,\
		&win->line_length, &win->endian);
	while (++y < 200)
	{
		x = 100;
		while (++x < 200)
			my_mlx_pixel_put(win, x, y, 0xFFFFFF);
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	mlx_loop(win->mlx);
}

int	main(int argc, char **argv)
{
	t_all	*data;

	if (argc != 2)
		common_err(ERR_ARGUMENTS);
	data = (t_all *)malloc(sizeof(t_all));
	if (!data)
		common_err(ERR_MALLOC);
	read_file(argv[1], data);
	check_map_validation(data);
	data->win = (t_win *)malloc(sizeof(t_win));
	if (!data->win)
		common_err(ERR_MALLOC);
	render(data->win);
	clean(data);
}
