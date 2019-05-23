/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:21:30 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/30 18:58:33 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while ((src[i] != '\0' || dst[i] != '\0') && i < len)
	{
		if (src[i] == '\0')
		{
			dst[i] = src[i];
			++i;
			break ;
		}
		dst[i] = src[i];
		++i;
	}
	if (i < len - 1)
		while (dst[i] != '\0' && i < len)
		{
			dst[i] = '\0';
			++i;
		}
	return (dst);
}
