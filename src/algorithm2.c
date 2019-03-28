/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:33:27 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/27 16:13:37 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		split_half(Ring **stack_a, Ring **stack_b, int median, int eap)
{
	while (eap > 0)
	{
		if (A_TOP <= median)
			ra(stack_a);
		else
		{
			pb(stack_a, stack_b);
			eap--;
		}
	}
	(*stack_b)->current->div = 'A';
}

static void	sort_three_a2(Ring **stack, int min, int max, Node *ptr)
{
	if (ptr->num == max)
	{
		if (ptr->prev->num == min)
		{
			ra(stack);
			sa(stack);
		}
		else
			ra(stack);
	}
	else
	{
		if (ptr->next->num == min)
			sa(stack);
		else
		{
			rra(stack);
		}
	}
}

void		sort_three_a(Ring **stack)
{
	Node	*ptr;
	int		min;
	int		max;

	find_minmax(stack, &min, &max);
	ptr = (*stack)->current;
	if ((*stack)->size == 2)
	{
		if ((*stack)->current->num == max)
			sa(stack);
		return ;
	}
	else if (ptr->num == min)
	{
		if (ptr->prev->num == max)
			return ;
		else
		{
			rra(stack);
			sa(stack);
		}
	}
	else
		sort_three_a2(stack, min, max, ptr);
}

int			partition_hoare(int *arr, int start, int end)
{
	int		i;
	int		pivot;
	int		j;

	pivot = arr[end];
	i = start;
	j = end - 1;
	while (1)
	{
		while (arr[i] < pivot)
		{
			i++;
		}
		while (arr[j] >= pivot)
		{
			j--;
			if (j <= i)
				break ;
		}
		if (i >= j)
			break ;
		ft_swap_int(&arr[i], &arr[j]);
	}
	ft_swap_int(&arr[end], &arr[i]);
	return (i);
}

void		quicksort(int *arr, int start, int end)
{
	int		pndex;

	pndex = 0;
	if (start < end)
	{
		pndex = partition_hoare(arr, start, end);
		quicksort(arr, start, pndex - 1);
		quicksort(arr, pndex + 1, end);
	}
}
