/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:33:42 by prochell          #+#    #+#             */
/*   Updated: 2021/12/04 23:09:50 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	read_file(char *file_name, t_all *data)
{
	int		fd;
	char	*line;
	int		i;

	data->map.height = get_height_file(file_name);
	data->map.width = get_width_file(file_name);
	line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		common_err(ERR_READING);
	data->map_arr = ft_calloc(data->map.height + 1, sizeof(char *));
	i = -1;
	while (++i < data->map.height)
	{
		data->map_arr[i] = ft_calloc(data->map.width + 1, sizeof(char));
		ft_memset(data->map_arr[i], ' ', data->map.width);
	}
	if (!data->map_arr)
		common_err(ERR_MALLOC);
	i = -1;
	while (++i < data->map.height)
	{
		get_next_line(fd, &line);
		ft_memcpy(data->map_arr[i], line, ft_strlen(line));

		free(line);
	}
	close(fd);
}
