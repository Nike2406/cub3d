/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:33:42 by prochell          #+#    #+#             */
/*   Updated: 2021/11/13 21:13:00 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void check_player(char **map)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' ||\
				map[i][j] == 'S' || map[i][j] == 'W')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		map_err(ERR_PLAYER);
}

int	check_map_validation(char **map)
{
	check_player(map);
	return (0);
}

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
