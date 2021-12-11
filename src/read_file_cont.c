/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_cont.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:35:45 by signacia          #+#    #+#             */
/*   Updated: 2021/12/11 18:54:48 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
			x = 3;
		else
			x = 2;
		if (data->info->texture_addr[x] != NULL)
			common_err(ERR_ARGUMENTS);
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
