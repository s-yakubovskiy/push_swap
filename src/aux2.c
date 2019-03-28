/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:16:25 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/27 16:19:31 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_index(Ring **stack_a)
{
	int		min;

	min = (*stack_a)->current->prev->num;
	while (min != *(*stack_a)->sort)
	{
		((*stack_a)->sort)++;
	}
	((*stack_a)->sort)++;
}

int		deep_len_to_div_up(Ring **stack_b)
{
	int		i;
	Node	*ptr;

	i = 0;
	B_DIV_BOT == 'A' ? B_DIV_BOT = '@' : 0;
	ptr = (*stack_b)->current->prev;
	while (1)
	{
		if (ptr->div == 'A' || ptr->div == 'z' || ptr->div == '$')
			break ;
		i++;
		ptr = ptr->prev;
	}
	return (i);
}

int		deep_len_to_div(Ring **stack)
{
	int		i;
	Node	*ptr;

	i = 1;
	ptr = (*stack)->current;
	ptr = ptr->next;
	while (1)
	{
		if (ptr->div == 'A' || ptr->div == 'z' || ptr->div == '^')
			break ;
		i++;
		ptr = ptr->next;
	}
	return (i);
}

void	free_memory(Ring **stack_a, Ring **stack_b, int len)
{
	Node	*ptr;
	int		size;
	Node	*rem;

	ptr = (*stack_a)->current;
	size = (*stack_a)->size;
	((*stack_a)->sort -= size);
	while (--size >= 0)
	{
		rem = ptr->next;
		free(ptr);
		ptr = rem;
	}
	ptr = (*stack_b)->current;
	size = (*stack_b)->size;
	if (size >= 1)
	{
		while (--size >= 0)
		{
			rem = ptr->next;
			free(ptr);
			ptr = rem;
		}
	}
}

void	check_stack_a(Ring **stack_a)
{
	if ((*stack_a)->current->next->num == CUR_MIN)
		sa(stack_a);
	while (A_TOP == *(*stack_a)->sort)
	{
		ra(stack_a);
		A_DIV_BOT = '$';
		((*stack_a)->sort)++;
	}
}
