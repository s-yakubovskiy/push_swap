/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:52:40 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/30 18:58:33 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_arr;
	char	*fresh;

	if (s == NULL)
		return (NULL);
	fresh = ft_strnew(len);
	if (fresh == NULL)
		return (NULL);
	new_arr = fresh;
	while (s[start] != '\0' && len-- != 0)
		*(fresh++) = s[start++];
	*fresh = '\0';
	return (new_arr);
}
