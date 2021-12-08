/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: signacia <signacia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:33:42 by prochell          #+#    #+#             */
/*   Updated: 2021/12/08 15:38:02 by signacia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	pre_parse()
// {
// 	// хейт+видф	
// }

int	parse_textures(t_all *data, char *str)
{
	int	x;

	if (ft_strncmp(str, "NO ", 3) == 0 || ft_strncmp(str, "SO ", 3) == 0
		|| ft_strncmp(str, "WE ", 3) == 0 || ft_strncmp(str, "EA ", 3) == 0)
	{
		if (ft_strncmp(str, "NO ", 3) == 0)
			x = 0;
		else if (ft_strncmp(str, "SO ", 3) == 0)
			x = 1;
		else if (ft_strncmp(str, "WE ", 3) == 0)
			x = 2;
		else
			x = 3;
		data->info->texture_addr[x] = ft_strtrim(str + 3, " \t");
		if (data->info->texture_addr[x] == NULL
			|| ft_strlen(data->info->texture_addr[x]) == 0)
			common_err(ERR_ARGUMENTS);
		return (1);
	}
	return (0);
}

int	ft_natoi(const char *str, int len)
{
	int	res;
	int	ptr;

	res = 0;
	ptr = 0;
	while (ptr < len)
	{
		res = res * 10 + str[ptr] - '0';
		ptr++;
	}
	return (res);
}

int	color_range(char *str, int *i, int *comma)
{
	int	temp;
	int	j;

	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	if (!ft_isdigit(str[*i]) || (str[*i] == '0' && ft_isdigit(str[*i + 1])))
		common_err(INVAL_COLOR);
	j = *i;
	while (ft_isdigit(str[*i]))
		(*i)++;
	temp = ft_natoi(str + j, *i - j);
	if (*i - j > 3 || temp > 255)
		common_err(INVAL_COLOR);
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
	if (*comma == 0 && str[*i] == '\0')
		return (temp);
	(*comma)--;
	if (str[*i] == ',')
	{
		(*i)++;
		return (temp);
	}
	common_err(INVAL_COLOR);
	return (0);
}

int	color_converting(char *str)
{
	int	i;
	int	temp;
	int	res;
	int	comma;

	i = 0;
	temp = 0;
	res = 0;
	comma = 2;
	while (1)
	{
		temp = color_range(str, &i, &comma);
		res = (res << 8) + temp;
		temp = 0;
		if (str[i] == '\0')
			break ;
	}
	free(str);
	return (res);
}

int	parse_colors(t_all *data, char *str)
{
	if (ft_strncmp(str, "F ", 2) == 0 || ft_strncmp(str, "C ", 2) == 0)
	{
		if (ft_strncmp(str, "F ", 2) == 0)
		{
			if (data->info->floor_color != -1)
				common_err(ERR_ARGUMENTS);
			data->info->floor_color = color_converting(ft_strtrim(str + 2, " \t"));
		}
		else
		{
			if (data->info->ceil_color != -1)
				common_err(ERR_ARGUMENTS);
			data->info->ceil_color = color_converting(ft_strtrim(str + 2, " \t"));
		}
		return (1);
	}
	return (0);
}

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

	// int x = 0, y;
	// while (data->map_arr[x])
	// {
	// 	y = 0;
	// 	while (data->map_arr[x][y])
	// 		printf("%c ", data->map_arr[x][y++]);
	// 	printf("\n");
	// 	x++;
	// }

	if (data->info->map_arr == NULL)
		map_err(ERR_NO_MAP);
}
