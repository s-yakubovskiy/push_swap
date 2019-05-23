/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:44:20 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/04/14 10:10:24 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 128
# define MALLCHECK(x) if (!x) return (-1);

# if (BUFF_SIZE <= 0)
#  error BUFF_SIZE must be > 0
# endif

int					get_next_line(const int fd, char **line);

#endif
