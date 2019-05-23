/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 10:06:00 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/04/14 10:07:13 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstnew_light(int fd)
{
	t_node		*root;

	if (!(root = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	(fd >= 0) ? root->fd = fd : 0;
	root->data = NULL;
	root->next = NULL;
	root->n = 0;
	return (root);
}
