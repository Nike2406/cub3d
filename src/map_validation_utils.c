/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:04:12 by prochell          #+#    #+#             */
/*   Updated: 2021/12/05 20:50:46 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	valid_symbol(char **arr, int i, int j, char s)
{
	if (arr[i + 1][j] == s || !arr[i + 1][j] || \
		arr[i - 1][j] == s || !arr[i - 1][j] || \
		arr[i][j + 1] == s || !arr[i][j + 1] || \
		arr[i][j - 1] == s || !arr[i][j - 1])
		return (1);
	return (0);
}

void	check_borders(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == '0')
			map_err(ERR_MAP);
		j++;
	}
}

void	check_plr_lock(t_all *data)
{
	int	x;
	int	y;

	x = data->player.x;
	y = data->player.y;
	if (data->info->map_arr[x + 1][y] == '1' && \
		data->info->map_arr[x - 1][y] == '1' && \
		data->info->map_arr[x][y + 1] == '1' && \
		data->info->map_arr[x][y - 1] == '1')
		map_err(ERR_PLR_LOCK);
}
