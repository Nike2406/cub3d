/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 22:20:17 by prochell          #+#    #+#             */
/*   Updated: 2021/11/13 22:45:09 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Fix valid over borders
int	valid_symbol(char **arr, int i, int j, char s)
{
	// if (!arr[i - 1][j] || !arr[i][j - 1])
	// 	return (0);
	if (i > 0 || j > 0)
	{
		if (arr[i + 1][j] == s || \
			arr[i - 1][j] == s || \
			arr[i][j + 1] == s || \
			arr[i][j - 1] == s)
			return (1);
		return (0);
	}
	return (0);
}

void check_sympols(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'N' && map[i][j] != 'E' &&\
				map[i][j] != 'S' && map[i][j] != 'W' && \
				map[i][j] != ' ' && map[i][j] != '0' &&\
				map[i][j] != '1')
				map_err(ERR_SYMBOL);
			j++;
		}
		i++;
	}
}

void check_map(t_all *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0')
			{
				if (valid_symbol(data->map, i, j, ' '))
					map_err(ERR_MAP);
			}
			j++;
		}
		i++;
	}
	i = data->player.x;
	j = data->player.y;
	if (valid_symbol(data->map, i, j, ' '))
		map_err(ERR_MAP);
}

void check_player(t_all *data)
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
			if (data->map[i][j] == 'N' || data->map[i][j] == 'E' ||\
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
	check_map(data);
}
