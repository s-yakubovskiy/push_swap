/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:59:57 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/30 18:58:33 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_arr;
	char	*begining;

	if (s == NULL || f == NULL)
		return (NULL);
	if ((new_arr = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	begining = new_arr;
	while (*s != '\0')
		*new_arr++ = (f)(*(s++));
	*new_arr = '\0';
	return (begining);
}
