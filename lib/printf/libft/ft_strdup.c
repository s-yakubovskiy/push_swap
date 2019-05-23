/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:21:29 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/30 18:58:33 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buff;
	int		i;

	i = -1;
	buff = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s1 == NULL || buff == NULL)
		return (NULL);
	while (s1[++i])
		buff[i] = s1[i];
	buff[i] = '\0';
	return (buff);
}
