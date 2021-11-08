/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:33:23 by prochell          #+#    #+#             */
/*   Updated: 2021/08/01 12:42:17 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define BUFFER_SIZE 10000

int		get_next_line(int fd, char **line);
char	*chk_reminder(char **reminder, char **line);
int		chk_rules(char **buf, int fd, char **line);
void	get_tmp_chr(char **tmp_chr, char **reminder);

#endif


// #ifndef GET_NEXT_LINE_H
// # define GET_NEXT_LINE_H
// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 32
// # endif
// # include <unistd.h>
// # include <stdlib.h>

// int		get_next_line(int fd, char **line);
// // char	*ft_strchr(char *string, int c);
// size_t	ft_strlen(const char *s);
// // char	*ft_strdup(char *src);
// #endif