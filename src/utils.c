/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:44:49 by prochell          #+#    #+#             */
/*   Updated: 2021/11/14 18:07:16 by prochell         ###   ########.fr       */
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

int	get_width_arr(char *arr)
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

int	get_width_file(char *file_name)
{
	char	*line;
	int		fd;
	int		width;

	line = NULL;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		common_err(ERR_READING);
	while (get_next_line(fd, &line))
	{
		width = ft_wdcounter(line, ' ');
		free(line);
	}
	free(line);
	close(fd);
	return (width);
}
