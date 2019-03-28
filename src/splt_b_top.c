/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splt_b_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 10:21:12 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/27 15:49:21 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void deep_checker(Ring **stack_a, Ring **stack_b, int *deep)
{
	if (*deep == 2 && A_DIV == '^' && A_DIV_BOT == '$')
		check_if_top_min(stack_a, stack_b);
	else if (*deep == 5 && A_DIV == '^' && A_DIV_BOT == '$')
	{
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		rb(stack_b);
		while (--(*deep))
			check_if_top_min(stack_a, stack_b);
	}
	else if (*deep == 4 && A_DIV == '^' && A_DIV_BOT == '$')
	{
		pa(stack_a, stack_b);
		pa(stack_a, stack_b);
		while (--(*deep))
			check_if_top_min(stack_a, stack_b);
	}
	else if (*deep == 3 && A_DIV == '^' && A_DIV_BOT == '$')
	{
		pa(stack_a, stack_b);
		while (--(*deep))
			check_if_top_min(stack_a, stack_b);
	}
}

static void	deep_checker2(Ring **stack_a, Ring **stack_b, int *deep)
{
	int		median;

	median = 0;
	list2arr_light(stack_b, &median);
	B_DIV == '^' ? B_DIV = '@' : 0;
	B_DIV == 'A' ? B_DIV = '@' : 0;
	while (B_DIV != 'A' && --(*deep) >= 0)
	{
		if (B_TOP <= median)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
		check_stack_a(stack_a);
	}
	if (B_DIV == 'A')
		B_DIV = 'A';
	else
		B_DIV = '^';
	check_if_top_min(stack_a, stack_b);
}

static void	deep_checker3(Ring **stack_a, Ring **stack_b, int *mem, char *c)
{
	if (find_ends(stack_b) == -1)
		B_DIV_BOT = '$';
	else
		B_DIV_BOT = 'A';
	A_DIV != '^' ? A_DIV = 'A' : 0;
	if (*mem == 0)
		B_DIV_BOT = '$';
	if (*c == '^' && B_DIV == 'A')
		B_DIV = '^';
}

void		split_b_top(Ring **stack_a, Ring **stack_b)
{
	int		deep;
	int		mem;
	char	c;

	c = B_DIV;
	mem = (*stack_b)->current->prev->num ;
	deep = deep_len_to_div(stack_b);
	if (deep == B_SIZE)
		mem = 0;
	if (deep <= 5)
		deep_checker(stack_a,stack_b, &deep);
	else
	{
		deep_checker2(stack_a, stack_b, &deep);
		if (B_SIZE <= 1)
			return ;
		else
			deep_checker3(stack_a, stack_b, &mem, &c);
	}
}