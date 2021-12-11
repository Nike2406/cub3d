/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lodev_ver_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:53:36 by prochell          #+#    #+#             */
/*   Updated: 2021/12/11 20:11:34 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycasting_preset(t_raycasting *ray_c, t_info *info, int x)
{
	ray_c->camerax = 2 * x / (double)WIN_WIDTH - 1;
	ray_c->raydirx = info->dirx + info->planex * ray_c->camerax;
	ray_c->raydiry = info->diry + info->planey * ray_c->camerax;
	ray_c->mapx = (int)info->posx;
	ray_c->mapy = (int)info->posy;
	ray_c->deltadistx = fabs(1 / ray_c->raydirx);
	ray_c->deltadisty = fabs(1 / ray_c->raydiry);
}

void	draw_lodev(t_info *info)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_HEIGHT)
	{
		x = -1;
		while (++x < WIN_WIDTH)
			info->img.data[y * WIN_WIDTH + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	calc(t_info *info)
{
	int				x;
	t_raycasting	*raycasting;

	raycasting = (t_raycasting *)malloc(sizeof(t_raycasting));
	if (!raycasting)
		common_err(ERR_MALLOC);
	x = 0;
	while (x < WIN_WIDTH)
	{
		raycasting_preset(raycasting, info, x);
		get_side_position(raycasting, info);
		get_ray_hit(raycasting, info);
		get_texture_params(raycasting, info);
		fill_verticals(raycasting, info, x);
		x++;
	}
	free(raycasting);
}

int	main_loop(t_info *info)
{
	calc(info);
	print_map(info);
	draw_lodev(info);
	return (0);
}
