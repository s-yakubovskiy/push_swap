/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:16:06 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/29 09:13:22 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	top_min1(t_ring **stack_a, t_ring **stack_b)
{
	if ((*stack_a)->current->next->num == CUR_MIN)
		sa(stack_a);
	if ((*stack_b)->current->next->num == CUR_MIN && B_SIZE > 1)
		sb(stack_b);
	while (A_TOP == CUR_MIN)
	{
		ra(stack_a);
		(*stack_a)->current->prev->div = '$';
		((*stack_a)->sort)++;
		if ((*stack_a)->current->next->num == CUR_MIN)
		{
			if ((*stack_a)->current->next->div == '^')
				(*stack_a)->current->next->next->div = '^';
			else if ((*stack_a)->current->next->div == 'A')
				(*stack_a)->current->next->next->div = 'A';
			sa(stack_a);
		}
	}
}

static void	top_min2(t_ring **stack_a, t_ring **stack_b)
{
	if ((*stack_b)->current->div == '^')
		(*stack_b)->current->next->div = '^';
	else if ((*stack_b)->current->div == 'A' &&
		(*stack_b)->current->next->div != '^')
		(*stack_b)->current->next->div = 'A';
	pa(stack_a, stack_b);
	ra(stack_a);
	A_DIV_BOT = '$';
	((*stack_a)->sort)++;
	if ((*stack_b)->current->next->num == CUR_MIN)
	{
		if ((*stack_b)->current->next->div == '^')
			(*stack_b)->current->next->next->div = '^';
		else if ((*stack_b)->current->next->div == 'A')
			(*stack_b)->current->next->next->div = 'A';
		sb(stack_b);
	}
}

static void	top_min3(t_ring **stack_a, t_ring **stack_b)
{
	if (B_DIV_BOT == '$')
		(*stack_b)->current->prev->prev->div = '$';
	else if (B_DIV_BOT == 'A' && (*stack_b)->current->prev->prev->div != '$')
		(*stack_b)->current->prev->prev->div = 'A';
	rrb(stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
	A_DIV_BOT = '$';
	((*stack_a)->sort)++;
}

static void	micropush(t_ring **stack_a, t_ring **stack_b)
{
	pa(stack_a, stack_b);
	ra(stack_a);
	((*stack_a)->sort)++;
	A_DIV_BOT = '$';
}

void		check_if_top_min(t_ring **stack_a, t_ring **stack_b)
{
	if (B_SIZE != 0)
	{
		top_min1(stack_a, stack_b);
		while (B_TOP == CUR_MIN && B_SIZE > 0)
		{
			if (B_SIZE == 1)
			{
				if (B_TOP == CUR_MIN)
					micropush(stack_a, stack_b);
				B_SIZE = 0;
				return ;
			}
			top_min2(stack_a, stack_b);
		}
		while ((*stack_b)->current->prev->num == CUR_MIN && B_SIZE > 0)
		{
			if (B_SIZE == 1)
			{
				(B_TOP == CUR_MIN) ? micropush(stack_a, stack_b) : 0;
				B_SIZE = 0;
				return ;
			}
			top_min3(stack_a, stack_b);
		}
	}
}
