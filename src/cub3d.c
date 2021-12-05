/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:22:16 by prochell          #+#    #+#             */
/*   Updated: 2021/12/05 18:24:07 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_all	*data;

	if (argc != 2)
		common_err(ERR_ARGUMENTS);
	data = (t_all *)malloc(sizeof(t_all));
	if (!data)
		common_err(ERR_MALLOC);
	read_file(argv[1], data);
	check_map_validation(data);
	data->win = (t_win *)malloc(sizeof(t_win));
	if (!data->win)
		common_err(ERR_MALLOC);
	start_lodev_version(data->map_arr, data);
	// int i = -1;
	// while (data->map_arr[++i])
	// 	printf("%s\n", data->map_arr[i]);
	// data_preset(data);
	// first_render(data->win, data);
	clean(data);
}
