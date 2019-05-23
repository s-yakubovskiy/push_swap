/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:14:05 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/29 09:58:49 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb_(t_ring **root)
{
	t_elem *prev_node;

	if ((*root)->current == NULL)
		return ;
	prev_node = (*root)->current->next;
	(*root)->current = prev_node;
}

void	sa_(t_ring **root)
{
	if ((*root)->current == NULL)
		return ;
	ft_swap(&(*root)->current->div, &(*root)->current->next->div);
	ft_swap_int(&(*root)->current->num, &(*root)->current->next->num);
}

void	sb_(t_ring **root)
{
	if ((*root)->current == NULL)
		return ;
	ft_swap(&(*root)->current->div, &(*root)->current->next->div);
	ft_swap_int(&(*root)->current->num, &(*root)->current->next->num);
}

void	pa_(t_ring **stack_a, t_ring **stack_b)
{
	if ((*stack_b)->current == NULL)
		return ;
	push_top(stack_a, (*stack_b)->current->num, (*stack_b)->current->div);
	rm_node(stack_b);
}

void	pb_(t_ring **stack_a, t_ring **stack_b)
{
	if ((*stack_a)->current == NULL)
		return ;
	push_top(stack_b, (*stack_a)->current->num, (*stack_a)->current->div);
	rm_node(stack_a);
}
