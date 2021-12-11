/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: signacia <signacia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:36:10 by signacia          #+#    #+#             */
/*   Updated: 2021/12/11 16:38:39 by signacia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_map(t_all *data, char *line)
{
	int		i;
	char	**tmp;

	i = 0;
	if (data->info->map_arr != NULL)
	{
		while (data->info->map_arr[i])
			i++;
		tmp = (char **)ft_calloc(i + 2, sizeof(char *));
		if (!tmp)
			common_err(ERR_MALLOC);
		tmp[i + 1] = NULL;
		tmp[i] = ft_strdup(line);
		if (!tmp[i])
			common_err(ERR_MALLOC);
		while (i-- > 0)
			tmp[i] = data->info->map_arr[i];
		free(data->info->map_arr);
		data->info->map_arr = tmp;
		return ;
	}
	data->info->map_arr = (char **)ft_calloc(2, sizeof(char *));
	data->info->map_arr[0] = ft_strdup(line);
	data->info->map_arr[1] = NULL;
}

int	init_map(t_all *data, char *line)
{
	int	i;

	i = 0;
	while (i < 4)
		if (data->info->texture_addr[i++] == NULL)
			common_err(ERR_ARGUMENTS);
	if (data->info->floor_color == -1 || data->info->ceil_color == -1)
		common_err(ERR_ARGUMENTS);
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '1')
	{
		parse_map(data, line);
		return (1);
	}
	else
		common_err(ERR_ARGUMENTS);
	return (0);
}

void	read_next_line(t_all *data, char *line)
{
	int	i;

	if (line == NULL)
		common_err(ERR_ARGUMENTS);
	if (data->info->map_arr != NULL)
	{
		parse_map(data, line);
		return ;
	}
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else if (parse_textures(data, line + i))
			break ;
		else if (parse_colors(data, line + i))
			break ;
		else if (init_map(data, line))
			break ;
	}
}

void	parsing_qube(char *file_name, t_all *data)
{
	int		ret;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		common_err(ERR_READING);
	data->info->map_arr = NULL;
	data->info->texture_addr = (char **)ft_calloc(sizeof(char *), 4);
	data->info->floor_color = -1;
	data->info->ceil_color = -1;
	while (1)
	{
		ret = get_next_line(fd, &line);
		read_next_line(data, line);
		free(line);
		if (ret == 0)
			break ;
	}
	close(fd);
	if (data->info->map_arr == NULL)
		map_err(ERR_NO_MAP);
}
