/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:45:03 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/30 18:58:33 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*src;
	char	*search;
	size_t	g;
	size_t	i;

	src = (char *)haystack;
	search = (char *)needle;
	i = -1;
	g = 0;
	if (ft_strlen(search) == 0)
		return (src);
	while (src[++i] != '\0')
		if (src[i] == search[g])
		{
			++g;
			if (search[g] == '\0')
				return (src + (i - g) + 1);
		}
		else
		{
			i = i - g;
			g = 0;
		}
	return (NULL);
}
