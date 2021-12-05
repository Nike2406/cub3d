/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:44:49 by prochell          #+#    #+#             */
/*   Updated: 2021/12/05 19:30:15 by prochell         ###   ########.fr       */
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

int	get_height_file(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	line = NULL;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		common_err(ERR_READING);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	if (*line != '\0')
		height++;
	free(line);
	close(fd);
	return (height);
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

int	get_width_file(char *file_name)
{
	char	*line;
	int		fd;
	int		width;
	int		tmp;

	line = NULL;
	width = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		common_err(ERR_READING);
	while (get_next_line(fd, &line))
	{
		tmp = get_width_arr(line);
		if (tmp > width)
			width = tmp;
		free(line);
	}
	free(line);
	close(fd);
	return (width);
}

int	get_width_arr(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

float	MOD(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

float	MAX(float a, float b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

