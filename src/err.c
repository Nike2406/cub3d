/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: signacia <signacia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:25:51 by prochell          #+#    #+#             */
/*   Updated: 2021/12/11 15:29:20 by signacia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	common_err(int err)
{
	printf("Error\n");
	if (err == ERR_MALLOC)
		printf("Malloc failed!\n");
	else if (err == ERR_ARGUMENTS)
		printf("Arguments error!\n");
	else if (err == ERR_READING)
		printf("Reading failed!\n");
	else if (err == INVAL_COLOR)
		printf("Invalid color!\n");
	else if (err == INVAL_TEXTURE)
		printf("Invalid texture address!\n");
	exit(1);
}

void	map_err(int err)
{
	printf("Error\n");
	if (err == ERR_PLAYER)
		printf("It must be just one player!\n");
	else if (err == ERR_SYMBOL)
		printf("The map contains forbidden symbols!\n");
	else if (err == ERR_MAP)
		printf("The map is not valid!\n");
	else if (err == ERR_PLR_LOCK)
		printf("Player locked!\n");
	else if (err == ERR_NO_MAP)
		printf("No map!\n");
	exit(1);
}

int	keys_err(int code)
{
	if (code == 1)
		ft_putendl("Red button Alert!");
	exit(code);
	return (1);
}
