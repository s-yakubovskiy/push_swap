/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:54:15 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/29 14:29:58 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_ring **stack_a, t_ring **stack_b)
{
	if ((*stack_a)->current == NULL)
		return ;
	push_top(stack_b, (*stack_a)->current->num, (*stack_a)->current->div);
	rm_node(stack_a);
	ft_printf("pb\n");
}

void	create_ring_stack(t_ring **root, int *arr, int size)
{
	int i;

	i = -1;
	while (++i < size)
		push_back(root, arr[i]);
}

void	rra_(t_ring **root)
{
	t_elem *prev_node;

	if ((*root)->current == NULL)
		return ;
	prev_node = (*root)->current->prev;
	(*root)->current = prev_node;
}

void	ra_(t_ring **root)
{
	t_elem *prev_node;

	if ((*root)->current == NULL)
		return ;
	prev_node = (*root)->current->next;
	(*root)->current = prev_node;
}

void	rrb_(t_ring **root)
{
	t_elem *prev_node;

	if ((*root)->current == NULL)
		return ;
	prev_node = (*root)->current->prev;
	(*root)->current = prev_node;
}
