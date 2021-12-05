/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 22:20:17 by prochell          #+#    #+#             */
/*   Updated: 2021/12/04 23:57:20 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_uncorrect_postion(t_all *data, char s)
{
	int	i;
	int	j;

	i = 1;
	while (data->map_arr[i + 1])
	{
		j = 1;
		if (data->map_arr[i][0] == s)
			map_err(ERR_MAP);
		while (data->map_arr[i][j + 1])
		{
			if (data->map_arr[i][j] == s)
			{
				if (valid_symbol(data->map_arr, i, j, ' '))
					map_err(ERR_MAP);
			}
			j++;
		}
		if (data->map_arr[i][j] == s)
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

	player = 0;
	i = -1;
	while (data->map_arr[++i])
	{
		j = -1;
		while (data->map_arr[i][++j])
		{
			if (data->map_arr[i][j] == 'N' || data->map_arr[i][j] == 'E' || \
				data->map_arr[i][j] == 'S' || data->map_arr[i][j] == 'W')
			{
				preset_player_direction(data, data->map_arr[i][j]);
				player++;
				data->player.x = j;
				data->player.y = i;
				data->map_arr[i][j] = '0';
			}
		}
	}
	if (player != 1)
		map_err(ERR_PLAYER);
}

void	check_map_validation(t_all *data)
{
	check_sympols(data->map_arr);
	check_player(data);
	check_borders(data->map_arr, 0);
	check_borders(data->map_arr, get_height_arr(data->map_arr) - 1);
	check_uncorrect_postion(data, '0');
	check_uncorrect_postion(data, data->player.plr_direction);
	if (valid_symbol(data->map_arr, data->player.y, data->player.x, ' '))
		map_err(ERR_MAP);
	// check_plr_lock(data);
}
