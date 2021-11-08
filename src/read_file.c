/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:33:42 by prochell          #+#    #+#             */
/*   Updated: 2021/11/08 21:21:40 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	read_file(char *file_name, t_cub3d *data)
{
	// int	fd;
	// int	i;

	data->height = get_height(file_name);
	printf("height is %d\n", data->height);
	// data->width = get_width(file_name);
	// fd = open(file_name, O_RDONLY);
	// if (fd < 0)
	// 	err(ERR_READING);
	// close(fd);
}
