/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:25:51 by prochell          #+#    #+#             */
/*   Updated: 2021/11/13 18:30:26 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	common_err(int err)
{
	if (err == ERR_MALLOC)
		printf("Malloc failed!");
	else if (err == ERR_ARGUMENTS)
		printf("Arguments error!");
	else if (err == ERR_READING)
		printf("Reading failed!");
	exit(1);
}
