/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:22:16 by prochell          #+#    #+#             */
/*   Updated: 2021/11/30 20:47:07 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_hook(t_all *data)
{
	mlx_hook(data->win->win, 2, 1L<<0, deal_key, data);
	mlx_hook(data->win->win, 17, 0, keys_err, data);
}

void	first_render(t_win *win, t_all *data)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->img_width, \
		win->img_height, "cub3d");
	win->img = mlx_new_image(win->mlx, win->img_width, \
		win->img_height);
	win->addr = mlx_get_data_addr(win->img, &win->bits_per_pixel,\
		&win->line_length, &win->endian);
	draw(data);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	get_hook(data);
	mlx_loop(win->mlx);
}

void	render(t_win *win, t_all *data)
{
	void	*tmp;

	tmp = win->img;
	win->img = mlx_new_image(win->mlx, win->img_width, \
		win->img_height);
	win->addr = mlx_get_data_addr(win->img, &win->bits_per_pixel,\
		&win->line_length, &win->endian);
	mlx_clear_window(win->mlx, win->win);
	draw(data);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	get_hook(data);
	mlx_destroy_image(win->mlx, tmp);
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
	start_lodev_version(data->map);
	// int i = -1;
	// while (data->map[++i])
	// 	printf("%s\n", data->map[i]);
	// data_preset(data);
	// first_render(data->win, data);
	clean(data);
}
