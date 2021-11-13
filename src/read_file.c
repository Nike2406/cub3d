/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:33:42 by prochell          #+#    #+#             */
/*   Updated: 2021/11/13 22:20:45 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	read_file(char *file_name, t_all *data)
{
	int		fd;
	char	*line;
	int		i;
	int		height;

	height = get_height(file_name);
	line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		common_err(ERR_READING);
	data->map = ft_calloc(height + 1, sizeof(char *));
	data->map[height] = NULL;
	if (!data->map)
		common_err(ERR_MALLOC);
	i = -1;
	while (++i < height)
	{
		get_next_line(fd, &line);
		data->map[i] = ft_strdup(line);
		free(line);
	}
	close(fd);
}
