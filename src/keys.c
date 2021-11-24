/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:07:48 by prochell          #+#    #+#             */
/*   Updated: 2021/11/21 18:14:29 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	deal_key(int key, t_all *data)
{
	if (key == 126 || key == 13)
		data->win->shift_x -= 0.5;
	else if (key == 125 || key == 1)
		data->win->shift_x += 0.5;
	else if (key == 124 || key == 2)
		data->win->shift_y += 0.5;
	else if (key == 123 || key == 0)
		data->win->shift_y -= 0.5;
	else if (key == 53)
		exit(0);
	render(data->win, data);
	return (1);
}
