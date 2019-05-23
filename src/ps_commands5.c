/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 10:06:42 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/29 14:52:22 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_ring **stack_a, t_ring **stack_b)
{
	if ((*stack_a)->current == NULL || (*stack_b)->current == NULL)
		return ;
	ft_swap(&(*stack_a)->current->div, &(*stack_a)->current->next->div);
	ft_swap_int(&(*stack_a)->current->num, &(*stack_a)->current->next->num);
	ft_swap(&(*stack_b)->current->div, &(*stack_b)->current->next->div);
	ft_swap_int(&(*stack_b)->current->num, &(*stack_b)->current->next->num);
	ft_printf("ss\n");
}

void	ss_(t_ring **stack_a, t_ring **stack_b)
{
	if ((*stack_a)->current == NULL || (*stack_b)->current == NULL)
		return ;
	ft_swap(&(*stack_a)->current->div, &(*stack_a)->current->next->div);
	ft_swap_int(&(*stack_a)->current->num, &(*stack_a)->current->next->num);
	ft_swap(&(*stack_b)->current->div, &(*stack_b)->current->next->div);
	ft_swap_int(&(*stack_b)->current->num, &(*stack_b)->current->next->num);
}

void	rr_(t_ring **stack_a, t_ring **stack_b)
{
	t_elem *prev_node1;
	t_elem *prev_node2;

	if ((*stack_a)->current == NULL || (*stack_b)->current == NULL)
		return ;
	prev_node1 = (*stack_a)->current->next;
	(*stack_a)->current = prev_node1;
	prev_node2 = (*stack_b)->current->next;
	(*stack_b)->current = prev_node2;
}

void	rr(t_ring **stack_a, t_ring **stack_b)
{
	t_elem *prev_node1;
	t_elem *prev_node2;

	if ((*stack_a)->current == NULL || (*stack_b)->current == NULL)
		return ;
	prev_node1 = (*stack_a)->current->next;
	(*stack_a)->current = prev_node1;
	prev_node2 = (*stack_b)->current->next;
	(*stack_b)->current = prev_node2;
	ft_printf("rr\n");
}

void	rrr_(t_ring **stack_a, t_ring **stack_b)
{
	t_elem *prev_node1;
	t_elem *prev_node2;

	if ((*stack_a)->current == NULL || (*stack_b)->current == NULL)
		return ;
	prev_node1 = (*stack_a)->current->prev;
	(*stack_a)->current = prev_node1;
	prev_node2 = (*stack_b)->current->prev;
	(*stack_b)->current = prev_node2;
}
