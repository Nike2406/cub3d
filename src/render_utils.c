/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:48:20 by prochell          #+#    #+#             */
/*   Updated: 2021/11/14 20:58:19 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_win *win, int x, int y, int color) // test
{
	char	*dst;

	dst = win->addr + (y * win->line_length + x * (win->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
