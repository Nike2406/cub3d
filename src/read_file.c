/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:33:42 by prochell          #+#    #+#             */
/*   Updated: 2021/11/13 19:02:42 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_all *data)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		common_err(ERR_READING);
	data->map = (char **)malloc(get_height(file_name) + 1);
	if (!data->map)
		common_err(ERR_MALLOC);
	i = 0;
	while (i <= get_height(file_name))
	{
		get_next_line(fd, &line);
		data->map[i] = line;
		// free(line);
		i++;
	}
	close(fd);
}
