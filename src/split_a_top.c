/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_a_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 10:22:44 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/27 15:48:44 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	deep_a_top(Ring **stack_a, Ring **stack_b, int *deep)
{
	if ((*deep) == 2)
		check_if_top_min(stack_a, stack_b);
	else if ((*deep) == 3)
	{
		pb(stack_a, stack_b);
		while (--(*deep))
			check_if_top_min(stack_a, stack_b);
	}
	else if ((*deep) == 4)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		while (--(*deep))
			check_if_top_min(stack_a, stack_b);
	}
	else if ((*deep) == 5)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		rb(stack_b);
		while (--(*deep))
			check_if_top_min(stack_a, stack_b);
	}
}

static void	deep_a_top_lot(Ring **stack_a, Ring **stack_b, int *median)
{
	while (A_DIV != '^')
	{
		if (A_TOP == CUR_MIN)
		{
			ra(stack_a);
			A_DIV_BOT = '$';
			((*stack_a)->sort)++;
		}
		else if ((*stack_a)->current->next->num == CUR_MIN)
		{
			sa(stack_a);
			ra(stack_a);
			A_DIV_BOT = '$';
			((*stack_a)->sort)++;
		}
		else
		{
			if ((*stack_a)->current->num <= *median)
				pb(stack_a, stack_b);
			else
			{
				pb(stack_a, stack_b);
				rb(stack_b);
			}
		}
	}
}

static void	deep_a_check_if(Ring **stack_a, Ring **stack_b, int mem, int mem2)
{
	if (mem2 != B_TOP)
		B_DIV = 'A';
	if ((mem == (*stack_b)->current->prev->num && B_DIV_BOT != 'A')
		|| B_DIV_BOT == '$')
		B_DIV_BOT = '$';
	else
		B_DIV_BOT = 'A';
}
void	split_a_top(Ring **stack_a, Ring **stack_b)
{
	int		median;
	int		deep;
	int		mem;
	int		mem2;

	deep = deep_len_to_div(stack_a);
	mem = (*stack_b)->current->prev->num;
	mem2 = B_TOP;
	A_DIV == 'A' ? A_DIV = '@' : 0;
	if (deep == 1 && A_DIV_BOT == '$')
	{
		ra(stack_a);
		A_DIV_BOT = '$';
	}
	else if (deep <= 5)
		deep_a_top(stack_a, stack_b, &deep);
	else
	{
		list2arr_light(stack_a, &median);
		deep_a_top_lot(stack_a, stack_b, &median);
		check_if_top_min(stack_a, stack_b);
		deep_a_check_if(stack_a, stack_b, mem, mem2);
	}
}