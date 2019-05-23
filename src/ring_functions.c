/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:54:31 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/29 16:28:56 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ring	*create_ring(void)
{
	t_ring	*tmp;

	tmp = (t_ring*)malloc(sizeof(t_ring));
	tmp->size = 1;
	tmp->bit = 0;
	tmp->current = NULL;
	tmp->sort = NULL;
	return (tmp);
}

t_elem	*create_node(int num)
{
	t_elem	*node;

	node = malloc(sizeof(t_elem));
	if (node == NULL)
		return (NULL);
	node->num = num;
	node->size = 1;
	node->prev = NULL;
	node->next = NULL;
	node->div = '@';
	return (node);
}

int		push_back(t_ring **root, int num)
{
	t_elem	*node;
	t_elem	*prev_node;

	prev_node = (*root)->current;
	node = create_node(num);
	if ((*root)->current == NULL)
		(*root)->current = node;
	else
	{
		node->next = (*root)->current;
		(*root)->current->prev = node;
		if (prev_node->next == NULL)
			prev_node->next = node;
		else
		{
			while (prev_node->next != (*root)->current)
				prev_node = prev_node->next;
			prev_node->next = node;
		}
		node->prev = prev_node;
		(*root)->size++;
	}
	return (0);
}

int		push_top(t_ring **root, int num, char div)
{
	t_elem	*node;
	t_elem	*last;

	node = create_node(num);
	if ((*root)->current == NULL)
	{
		(*root)->current = node;
		(*root)->current->div = div;
		(*root)->current->next = node;
		(*root)->current->prev = node;
	}
	else
	{
		last = (*root)->current->prev;
		node->next = (*root)->current;
		node->prev = last;
		(*root)->current->prev = node;
		last->next = (*root)->current->prev;
		(*root)->current = node;
		(*root)->current->div = div;
		(*root)->size++;
	}
	return (0);
}

t_ring	*rm_node(t_ring **root)
{
	t_elem	*curr;
	t_elem	*prev_1;

	curr = (*root)->current;
	if ((*root)->current == NULL)
		return (NULL);
	if ((*root)->current->next->num == (*root)->current->num)
	{
		(*root)->current = NULL;
		free(curr);
		return (NULL);
	}
	prev_1 = (*root)->current->prev;
	while (prev_1->next != (*root)->current)
		prev_1 = prev_1->next;
	(*root)->current = (*root)->current->next;
	prev_1->next = (*root)->current;
	(*root)->current->prev = prev_1;
	free(curr);
	(*root)->size--;
	return (*root);
}
