/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:25:51 by prochell          #+#    #+#             */
/*   Updated: 2021/11/14 20:46:14 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	common_err(int err)
{
	if (err == ERR_MALLOC)
		printf("Malloc failed!\n");
	else if (err == ERR_ARGUMENTS)
		printf("Arguments error!\n");
	else if (err == ERR_READING)
		printf("Reading failed!\n");
	exit(1);
}

void	map_err(int err)
{
	if (err == ERR_PLAYER)
		printf("It must be just one player!\n");
	else if (err == ERR_SYMBOL)
		printf("The map contains forbidden symbols!\n");
	else if (err == ERR_MAP)
		printf("The map is not valid!\n");
	exit(1);
}
