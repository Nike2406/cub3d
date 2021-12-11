/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: signacia <signacia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:44:49 by prochell          #+#    #+#             */
/*   Updated: 2021/12/11 17:09:16 by signacia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_height_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	clean(t_all *data)
{
	int	i;

	i = -1;
	while (data->info->map_arr[++i])
		free(data->info->map_arr[i]);
	free(data->info->map_arr);
	free(data);
}

int	get_width_arr(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
