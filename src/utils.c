/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:44:49 by prochell          #+#    #+#             */
/*   Updated: 2021/11/08 21:23:58 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_height(char *file_name)
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

int	get_width(char *file_name)
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
