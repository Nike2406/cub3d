/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:22:16 by prochell          #+#    #+#             */
/*   Updated: 2021/11/21 12:16:01 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_hook(t_win *win)
{
	mlx_hook(win->win, 2, 1L<<0, deal_key, win);
	mlx_hook(win->win, 17, 0, keys_err, win);
}

void	render(t_win *win)
{
	int		x;
	int		y;
	// void	*tmp;

	win->img_width = 640;
	win->img_height = 480;
	x = 100;
	y = 100;
	// tmp = win->img;
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

	get_hook(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	// mlx_destroy_image(win->mlx, tmp);
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

	// int i = -1;
	// while (data->map[++i])
	// 	printf("%s\n", data->map[i]);

	check_map_validation(data);
	data->win = (t_win *)malloc(sizeof(t_win));
	if (!data->win)
		common_err(ERR_MALLOC);
	render(data->win);
	clean(data);
}
