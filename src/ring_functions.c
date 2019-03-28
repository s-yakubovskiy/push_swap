/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:54:31 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/27 15:47:32 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Ring* createRing(void)
{
	Ring	*tmp;

	tmp = (Ring*)malloc(sizeof(Ring));
	tmp->size = 1;
	tmp->bit = 0;
	tmp->current = NULL;
	tmp->sort = NULL;

	return (tmp);
}
Node	*create_node(int num)
{
	Node	*node;

	node = malloc(sizeof(Node));
	if (node == NULL)
		return (NULL);
	node->num = num;
	node->size = 1;
	node->prev = NULL;
	node->next = NULL;
	node->div = '@';
	return (node);
}

int		push_back(Ring **root, int num)
{
	Node	*node;
	Node	*prev_node;

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

int		push_top(Ring **root, int num, char div)
{
	Node	*node;
	Node	*last;

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
		last->next = (*root)->current->prev = node;
		(*root)->current = node;
		(*root)->current->div = div;
		(*root)->size++;
	}
	return (0);
}

Ring	*rm_node(Ring **root)
{
	Node	*curr;
	Node	*prev_1;

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
