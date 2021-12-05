/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:58:28 by prochell          #+#    #+#             */
/*   Updated: 2021/12/05 21:43:36 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	raycasting_preset(t_raycasting *ray_c, t_info *info, int x)
{
	ray_c->cameraX = 2 * x / (double)win_width - 1;
	ray_c->rayDirX = info->dirX + info->planeX * ray_c->cameraX;
	ray_c->rayDirY = info->dirY + info->planeY * ray_c->cameraX;
	ray_c->mapX = (int)info->posX;
	ray_c->mapY = (int)info->posY;
	ray_c->deltaDistX = fabs(1 / ray_c->rayDirX);
	ray_c->deltaDistY = fabs(1 / ray_c->rayDirY);
}

void	get_side_position(t_raycasting *ray_c, t_info *info)
{
	if (ray_c->rayDirX < 0)
	{
		ray_c->stepX = -1;
		ray_c->sideDistX = (info->posX - ray_c->mapX) * \
			ray_c->deltaDistX;
	}
	else
	{
		ray_c->stepX = 1;
		ray_c->sideDistX = (ray_c->mapX + 1.0 - info->posX) * \
			ray_c->deltaDistX;
	}
	if (ray_c->rayDirY < 0)
	{
		ray_c->stepY = -1;
		ray_c->sideDistY = (info->posY - ray_c->mapY) * \
			ray_c->deltaDistY;
	}
	else
	{
		ray_c->stepY = 1;
		ray_c->sideDistY = (ray_c->mapY + 1.0 - info->posY) * \
			ray_c->deltaDistY;
	}
}

void	get_ray_hit(t_raycasting *ray_c, t_info *info)
{
	ray_c->hit = 0;
	while (ray_c->hit == 0)
	{
		if (ray_c->sideDistX < ray_c->sideDistY)
		{
			ray_c->sideDistX += ray_c->deltaDistX;
			ray_c->mapX += ray_c->stepX;
			ray_c->side = '0';
		}
		else
		{
			ray_c->sideDistY += ray_c->deltaDistY;
			ray_c->mapY += ray_c->stepY;
			ray_c->side = '1';
		}
		if (info->map_arr[ray_c->mapY][ray_c->mapX] == '1')
			ray_c->hit = 1;
	}
	if (ray_c->side == '0')
		ray_c->perpWallDist = (ray_c->sideDistX - ray_c->deltaDistX);
	else
		ray_c->perpWallDist = (ray_c->sideDistY - ray_c->deltaDistY);
}

void	get_texture_params(t_raycasting *ray_c, t_info *info)
{
	ray_c->lineHeight = (int)(win_height / ray_c->perpWallDist);
	ray_c->drawStart = -ray_c->lineHeight / 2 + win_height / 2;
	if(ray_c->drawStart < 0)
		ray_c->drawStart = 0;
	ray_c->drawEnd = ray_c->lineHeight / 2 + win_height / 2;
	if(ray_c->drawEnd >= win_height)
		ray_c->drawEnd = win_height - 1;
	ray_c->texNum = info->map_arr[ray_c->mapY][ray_c->mapX];
	if (ray_c->side == '0')
		ray_c->wallX = info->posY + ray_c->perpWallDist * ray_c->rayDirY;
	else
		ray_c->wallX = info->posX + ray_c->perpWallDist * ray_c->rayDirX;
	ray_c->wallX -= floor(ray_c->wallX);

	ray_c->texX = (int)(ray_c->wallX * (double)texWidth);
	if (ray_c->side == '0' && ray_c->rayDirX > 0)
		ray_c->texX = texWidth - ray_c->texX - 1;
	if (ray_c->side == '1' && ray_c->rayDirY < 0)
		ray_c->texX = texWidth - ray_c->texX - 1;
	ray_c->step = 1.0 * texHeight / ray_c->lineHeight;
	ray_c->texPos = (ray_c->drawStart - win_height / 2 + \
		ray_c->lineHeight / 2) * ray_c->step;
}

void	fill_verticals(t_raycasting *ray_c, t_info *info, int x)
{
	int	texY;
	int	color;
	int	y;

	y = -1;
	while (++y < ray_c->drawStart)
		info->buf[y][x] = 0xFF0000;
	y = ray_c->drawStart - 1;
	while (++y <= ray_c->drawEnd)
	{
		texY = (int)ray_c->texPos & (texHeight - 1);
		ray_c->texPos += ray_c->step;
		color = info->texture[ray_c->texNum % 8][texHeight * \
			texY + ray_c->texX];
		if (ray_c->side == '1')
			color = (color >> 1) & 8355711;
		info->buf[y][x] = color;
	}
	while (++y < win_height)
		info->buf[y][x] = 0x00FF00;
}
