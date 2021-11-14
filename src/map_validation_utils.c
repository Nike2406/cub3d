/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:04:12 by prochell          #+#    #+#             */
/*   Updated: 2021/11/14 19:04:44 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	valid_symbol(char **arr, int i, int j, char s)
{
	if (arr[i + 1][j] == s || \
		arr[i - 1][j] == s || \
		arr[i][j + 1] == s || \
		arr[i][j - 1] == s)
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
