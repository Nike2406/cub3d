/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 22:20:17 by prochell          #+#    #+#             */
/*   Updated: 2021/11/14 19:06:22 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map(t_all *data)
{
	int	i;
	int	j;

	i = 1;
	while (data->map[i + 1])
	{
		j = 1;
		if (data->map[i][0] == '0')
			map_err(ERR_MAP);
		while (data->map[i][j + 1])
		{
			if (data->map[i][j] == '0')
			{
				if (valid_symbol(data->map, i, j, ' '))
					map_err(ERR_MAP);
			}
			j++;
		}
		if (data->map[i][j] == '0')
			map_err(ERR_MAP);
		i++;
	}
}

void	check_sympols(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'N' && map[i][j] != 'E' && \
				map[i][j] != 'S' && map[i][j] != 'W' && \
				map[i][j] != ' ' && map[i][j] != '0' && \
				map[i][j] != '1')
				map_err(ERR_SYMBOL);
			j++;
		}
		i++;
	}
}

void	check_player(t_all *data)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E' || \
				data->map[i][j] == 'S' || data->map[i][j] == 'W')
			{
				player++;
				data->player.x = i;
				data->player.y = j;
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		map_err(ERR_PLAYER);
}

void	check_map_validation(t_all *data)
{
	check_sympols(data->map);
	check_player(data);
	check_borders(data->map, 0);
	check_borders(data->map, get_height_arr(data->map) - 1);
	check_map(data);
	if (valid_symbol(data->map, data->player.x, data->player.y, ' '))
		map_err(ERR_MAP);
}
