/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: signacia <signacia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 22:20:17 by prochell          #+#    #+#             */
/*   Updated: 2021/12/11 15:50:46 by signacia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_uncorrect_postion(t_all *data, char s)
{
	int	i;
	int	j;

	i = 1;
	while (data->info->map_arr[i + 1])
	{
		j = 1;
		if (data->info->map_arr[i][0] == s)
			map_err(ERR_MAP);
		while (data->info->map_arr[i][j + 1])
		{
			if (data->info->map_arr[i][j] == s)
			{
				if (valid_symbol(data->info->map_arr, i, j, ' '))
					map_err(ERR_MAP);
			}
			j++;
		}
		if (data->info->map_arr[i][j] == s)
			map_err(ERR_MAP);
		i++;
	}
}

void	check_sympols(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != 'N' && map[i][j] != 'E' && \
				map[i][j] != 'S' && map[i][j] != 'W' && \
				map[i][j] != ' ' && map[i][j] != '0' && \
				map[i][j] != '1')
				map_err(ERR_SYMBOL);
		}
	}
}

void	check_player(t_all *data)
{
	int	i;
	int	j;
	int	player;
	int	x;

	player = 0;
	i = -1;
	while (data->info->map_arr[++i])
	{
		j = -1;
		while (data->info->map_arr[i][++j])
		{
			x = data->info->map_arr[i][j];
			if (x == 'N' || x == 'E' || x == 'S' || x == 'W')
			{
				data->player.plr_direction = data->info->map_arr[i][j];
				player++;
				data->player.x = j;
				data->player.y = i;
				data->info->map_arr[i][j] = '0';
			}
		}
	}
	if (player != 1)
		map_err(ERR_PLAYER);
}

void	check_map_validation(t_all *data)
{
	check_sympols(data->info->map_arr);
	check_player(data);
	check_borders(data->info->map_arr, 0);
	check_borders(data->info->map_arr, get_height_arr(data->info->map_arr) - 1);
	check_uncorrect_postion(data, '0');
	check_uncorrect_postion(data, data->player.plr_direction);
	if (valid_symbol(data->info->map_arr, data->player.y, data->player.x, ' '))
		map_err(ERR_MAP);
}
