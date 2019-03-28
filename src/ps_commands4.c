/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:54:21 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/27 16:36:57 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(Ring **root)
{
	Node *prev_node;

	prev_node = (*root)->current->prev;
	(*root)->current = prev_node;
	ft_printf("rrb\n");
}

void	rb(Ring **root)
{
	Node *prev_node;

	prev_node = (*root)->current->next;
	(*root)->current = prev_node;
	ft_printf("rb\n");
}

void	sa(Ring **root)
{
	ft_swap(&(*root)->current->div, &(*root)->current->next->div);
	ft_swap_int(&(*root)->current->num, &(*root)->current->next->num);
	ft_printf("sa\n");
}

void	sb(Ring **root)
{
	ft_swap(&(*root)->current->div, &(*root)->current->next->div);
	ft_swap_int(&(*root)->current->num, &(*root)->current->next->num);
	ft_printf("sb\n");
}

void	pa(Ring **stack_a, Ring **stack_b)
{
	if ((*stack_b)->current == NULL)
		return ;
	push_top(stack_a, (*stack_b)->current->num, (*stack_b)->current->div);
	rm_node(stack_b);
	ft_printf("pa\n");
}
