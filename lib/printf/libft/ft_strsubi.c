/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 08:41:28 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/30 18:58:33 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubi(char const *s, unsigned int start, unsigned int end)
{
	char	*new_arr;
	char	*fresh;

	fresh = (char *)malloc((end - start) + 2);
	if (fresh == NULL)
		return (NULL);
	new_arr = fresh;
	while (s[start] != '\0' && start <= end)
		*(fresh++) = s[start++];
	*fresh = '\0';
	return (new_arr);
}
