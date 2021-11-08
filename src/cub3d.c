/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:22:16 by prochell          #+#    #+#             */
/*   Updated: 2021/11/08 20:41:05 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d	*data;

	if (argc != 2)
		common_err(ERR_ARGUMENTS);
	data = (t_cub3d *)malloc(sizeof(t_cub3d));
	if (!data)
		common_err(ERR_MALLOC);
	read_file(argv[1], data);
}
