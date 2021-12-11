/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:22:16 by prochell          #+#    #+#             */
/*   Updated: 2021/12/11 21:27:33 by prochell         ###   ########.fr       */
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
	data->info = (t_info *)malloc(sizeof(t_info));
	if (!data->info)
		common_err(ERR_MALLOC);
	data->info->movespeed = 0.08;
	data->info->rotspeed = 0.08;
	parsing_qube(argv[1], data);
	check_map_validation(data);
	start_lodev_version(data->info, data->player);
	clean(data);
}
