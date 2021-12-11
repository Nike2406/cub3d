/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: signacia <signacia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:58:28 by prochell          #+#    #+#             */
/*   Updated: 2021/12/11 17:34:01 by signacia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_side_position(t_raycasting *ray_c, t_info *info)
{
	if (ray_c->raydirx < 0)
	{
		ray_c->stepx = -1;
		ray_c->sidedistx = (info->posx - ray_c->mapx) * \
			ray_c->deltadistx;
	}
	else
	{
		ray_c->stepx = 1;
		ray_c->sidedistx = (ray_c->mapx + 1.0 - info->posx) * \
			ray_c->deltadistx;
	}
	if (ray_c->raydiry < 0)
	{
		ray_c->stepy = -1;
		ray_c->sidedisty = (info->posy - ray_c->mapy) * \
			ray_c->deltadisty;
	}
	else
	{
		ray_c->stepy = 1;
		ray_c->sidedisty = (ray_c->mapy + 1.0 - info->posy) * \
			ray_c->deltadisty;
	}
}

void	get_ray_hit(t_raycasting *ray_c, t_info *info)
{
	ray_c->hit = 0;
	while (ray_c->hit == 0)
	{
		if (ray_c->sidedistx < ray_c->sidedisty)
		{
			ray_c->sidedistx += ray_c->deltadistx;
			ray_c->mapx += ray_c->stepx;
			ray_c->side = '0';
		}
		else
		{
			ray_c->sidedisty += ray_c->deltadisty;
			ray_c->mapy += ray_c->stepy;
			ray_c->side = '1';
		}
		if (info->map_arr[ray_c->mapy][ray_c->mapx] == '1')
			ray_c->hit = 1;
	}
	if (ray_c->side == '0')
		ray_c->perpwalldist = (ray_c->sidedistx - ray_c->deltadistx);
	else
		ray_c->perpwalldist = (ray_c->sidedisty - ray_c->deltadisty);
}

static void	get_texture_side(t_raycasting *ray_c)
{
	if (ray_c->side == '1' && ray_c->stepy < 0)
		ray_c->texnum = 0;
	else if (ray_c->side == '1' && ray_c->stepy > 0)
		ray_c->texnum = 1;
	else if (ray_c->side == '0' && ray_c->stepx > 0)
		ray_c->texnum = 2;
	else if (ray_c->side == '0' && ray_c->stepx < 0)
		ray_c->texnum = 3;
}

void	get_texture_params(t_raycasting *ray_c, t_info *info)
{
	ray_c->lineheight = (int)(WIN_HEIGHT / ray_c->perpwalldist);
	ray_c->drawstart = -ray_c->lineheight / 2 + WIN_HEIGHT / 2;
	if (ray_c->drawstart < 0)
		ray_c->drawstart = 0;
	ray_c->drawend = ray_c->lineheight / 2 + WIN_HEIGHT / 2;
	if (ray_c->drawend >= WIN_HEIGHT)
		ray_c->drawend = WIN_HEIGHT - 1;
	get_texture_side(ray_c);
	if (ray_c->side == '0')
		ray_c->wallx = info->posy + ray_c->perpwalldist * ray_c->raydiry;
	else
		ray_c->wallx = info->posx + ray_c->perpwalldist * ray_c->raydirx;
	ray_c->wallx -= floor(ray_c->wallx);
	ray_c->texx = (int)(ray_c->wallx * (double)TEXWIDTH);
	if (ray_c->side == '0' && ray_c->raydirx > 0)
		ray_c->texx = TEXWIDTH - ray_c->texx - 1;
	if (ray_c->side == '1' && ray_c->raydiry < 0)
		ray_c->texx = TEXWIDTH - ray_c->texx - 1;
	ray_c->step = 1.0 * TEXHEIGHT / ray_c->lineheight;
	ray_c->texpos = (ray_c->drawstart - WIN_HEIGHT / 2 + \
		ray_c->lineheight / 2) * ray_c->step;
}

void	fill_verticals(t_raycasting *ray_c, t_info *info, int x)
{
	int	texy;
	int	color;
	int	y;

	y = -1;
	while (++y < ray_c->drawstart)
		info->buf[y][x] = info->ceil_color;
	y = ray_c->drawstart - 1;
	while (++y <= ray_c->drawend)
	{
		texy = (int)ray_c->texpos & (TEXHEIGHT - 1);
		ray_c->texpos += ray_c->step;
		color = info->texture[ray_c->texnum % 4][TEXHEIGHT * \
			texy + ray_c->texx];
		if (ray_c->side == '1')
			color = (color >> 1) & 8355711;
		info->buf[y][x] = color;
	}
	while (++y < WIN_HEIGHT)
		info->buf[y][x] = info->floor_color;
}
