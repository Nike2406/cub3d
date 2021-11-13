/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:33:42 by prochell          #+#    #+#             */
/*   Updated: 2021/11/13 19:57:43 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	fill_matrix(int *z_line, char *line)
// {
// 	char	**nums;
// 	int		i;

// 	nums = ft_split(line, ' ');
// 	i = 0;
// 	while (nums[i])
// 	{
// 		z_line[i] = ft_atoi(nums[i]);
// 		free(nums[i]);
// 		i++;
// 	}
// 	free(nums);
// }

void	read_file(char *file_name, t_all *data)
{
	int		fd;
	char	*line;
	int		i;
	int		height;
	// int		width;

	height = get_height(file_name);
	// width = get_width(file_name);
	// printf("height - %d, width - %d\n", height, width);
	line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		common_err(ERR_READING);
	data->map = ft_calloc(height + 1, sizeof(char *));
	data->map[height] = NULL;
	// i = 0;
	// while (i <= height)
	// {
	// 	data->map[i] = (char *)malloc(width + 1);
	// 	i++;
	// }
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
