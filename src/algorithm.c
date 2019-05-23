/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:16:37 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/29 14:34:27 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		queer_sort(t_ring **stack_a, t_ring **stack_b)
{
	int			median;
	int			eap;
	static int	check;

	if (check == 0)
	{
		list2arr(stack_a, &median, &eap);
		split_half(stack_a, stack_b, median, eap);
		(*stack_b)->current->div = 'A';
		check++;
	}
	if (A_SIZE > 3)
	{
		list2arr(stack_a, &median, &eap);
		split_half(stack_a, stack_b, median, eap);
		queer_sort(stack_a, stack_b);
	}
	else
		sort_three_a(stack_a);
}

void		queer_sort_b(t_ring **stack_a, t_ring **stack_b)
{
	int		i;

	A_DIV = '^';
	A_DIV_BOT = '$';
	B_DIV_BOT = '$';
	B_DIV = '^';
	while (B_SIZE >= 1)
	{
		i = check_for_splits(stack_a, stack_b);
		if (B_SIZE <= 1 && A_DIV == '^')
			break ;
		if (i == 1)
			split_b_top(stack_a, stack_b);
		else if (i == 2)
			split_a_top(stack_a, stack_b);
		else if (i == 4)
			split_b_bot(stack_a, stack_b);
	}
	if (*((*stack_a)->sort) == 0)
		((*stack_a)->sort)--;
	check_stack_a(stack_a);
	check_if_top_min(stack_a, stack_b);
}

static void	three_sort_fast(t_ring **stack_a)
{
	if ((*stack_a)->current->prev->num == CUR_MIN)
	{
		if (A_TOP > (*stack_a)->current->next->num)
			sa(stack_a);
		rra(stack_a);
	}
	else if (A_TOP == CUR_MIN)
	{
		if ((*stack_a)->current->prev->num < (*stack_a)->current->next->num)
		{
			ra(stack_a);
			sa(stack_a);
			rra(stack_a);
		}
	}
	else
	{
		if (A_TOP < (*stack_a)->current->prev->num)
			sa(stack_a);
		else
			ra(stack_a);
	}
}

void		algorithm_pre(t_ring **stack_a, t_ring **stack_b,
		int *arr, int size)
{
	if (check_a_stack_sorted(stack_a, stack_b) == 1)
		return ;
	if (size > 3)
	{
		queer_sort(stack_a, stack_b);
		find_min_index(stack_a);
		queer_sort_b(stack_a, stack_b);
	}
	else
	{
		if (arr == NULL)
			exit(-9);
		if (size == 3)
		{
			three_sort_fast(stack_a);
			return ;
		}
		else if (size == 1)
			;
		else if (size == 2)
			if (A_TOP > (*stack_a)->current->next->num)
				sa(stack_a);
		return ;
	}
}
