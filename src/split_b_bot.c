/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_b_bot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 10:22:17 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/27 15:49:02 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void deep_checker_b(Ring **stack_a, Ring **stack_b, int *deep)
{
	if (*deep == 2 )
	{
		rrb(stack_b);
		rrb(stack_b);
		while (--(*deep))
			check_if_top_min(stack_a, stack_b);
	}
	else
		rrb(stack_b);
	check_if_top_min(stack_a, stack_b);
}

static void sort_lot_b(Ring **stack_a, Ring **stack_b, int *deep, int median)
{
	list2arr_from_bot_light(stack_b, &median, &(*deep));
	while (B_DIV_BOT != '$' && B_DIV_BOT != 'A')
	{
		if ((*stack_b)->current->prev->num == (*stack_a)->sort[0])
		{
			rrb(stack_b);
			pa(stack_a, stack_b);
			ra(stack_a);
			A_DIV_BOT = '$';
			((*stack_a)->sort)++;
		}
		else
		{
			if ((*stack_b)->current->prev->num <= median)
			{
				rrb(stack_b);
				pa(stack_a, stack_b);
			}
			else
			{
				rrb(stack_b);
				B_DIV = '@';
			}
		}
	}
}

void	split_b_bot(Ring **stack_a, Ring **stack_b)
{
	int		median;
	int		deep;
	int		mem;

	mem = B_TOP;
	median = 0;
	deep = deep_len_to_div_up(stack_b);
	if (deep < 3 && A_DIV == '^' && A_DIV_BOT == '$' && B_DIV == '^')
		deep_checker_b(stack_a, stack_b, &deep);
	else
	{
		sort_lot_b(stack_a, stack_b, &deep, median);
		check_if_top_min(stack_a, stack_b);
		if (B_SIZE == 0)
			return ;
		if (B_DIV_BOT == 'A')
			B_DIV_BOT = 'A';
		else
			B_DIV_BOT = '$';
		if (mem == B_TOP && B_DIV != 'A')
			B_DIV = '^';
		else
			B_DIV = 'A';
	}
}