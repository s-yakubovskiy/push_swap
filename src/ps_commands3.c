/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:54:15 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/27 16:36:30 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(Ring **stack_a, Ring **stack_b)
{
	if ((*stack_a)->current == NULL)
		return ;
	push_top(stack_b, (*stack_a)->current->num, (*stack_a)->current->div);
	rm_node(stack_a);
	ft_printf("pb\n");
}

void	create_ring_stack(Ring **root, int *arr, int size)
{
	int i;

	i = -1;
	while (++i < size)
		push_back(root, arr[i]);
}

void	rra_(Ring **root)
{
	Node *prev_node;

	prev_node = (*root)->current->prev;
	(*root)->current = prev_node;
}

void	ra_(Ring **root)
{
	Node *prev_node;

	prev_node = (*root)->current->next;
	(*root)->current = prev_node;
}

void	rrb_(Ring **root)
{
	Node *prev_node;

	prev_node = (*root)->current->prev;
	(*root)->current = prev_node;
}
