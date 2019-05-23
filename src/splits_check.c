/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splits_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:56:25 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/29 15:42:18 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list2arr_light(t_ring **root, int *median)
{
	t_elem	*ptr;
	int		i;
	int		len;
	int		*q_sorted;

	i = -1;
	len = deep_len_to_div(root);
	ptr = (*root)->current;
	q_sorted = malloc(sizeof(int) * len + 3);
	while (++i < len)
	{
		q_sorted[i] = ptr->num;
		ptr = ptr->next;
	}
	quicksort(q_sorted, 0, len - 1);
	if (EVEN(len))
		*median = q_sorted[(len / 2) - 1];
	else
		*median = q_sorted[len / 2];
	free(q_sorted);
}

void	list2arr_from_bot_light(t_ring **root, int *median, int *deep)
{
	t_elem	*ptr;
	int		i;
	int		*q_sorted;

	i = -1;
	ptr = (*root)->current->prev;
	q_sorted = malloc(sizeof(int) * (*deep) + 3);
	while (++i < (*deep))
	{
		q_sorted[i] = ptr->num;
		ptr = ptr->prev;
	}
	quicksort(q_sorted, 0, (*deep) - 1);
	if (EVEN((*deep)))
		*median = q_sorted[((*deep) / 2) - 1];
	else
		*median = q_sorted[(*deep) / 2];
	free(q_sorted);
}

int		find_ends(t_ring **root)
{
	t_elem	*ptr;
	int		i;
	int		size;

	i = 1;
	size = (*root)->size;
	ptr = (*root)->current->prev->prev;
	while (++i < size - 1)
	{
		if (ptr->div == '$')
			return (1);
		ptr = ptr->prev;
	}
	return (-1);
}

int		check_for_splits(t_ring **stack_a, t_ring **stack_b)
{
	if (B_DIV == 'A' && B_DIV_BOT == 'A' && A_DIV == '^')
	{
		if (B_TOP < (*stack_b)->current->prev->num)
			return (1);
		else
			return (4);
	}
	if (A_DIV == '^' && A_DIV_BOT == '$' && B_DIV == '^' && B_DIV_BOT == '$')
		return (1);
	if (A_DIV == '^' && A_DIV_BOT == '$' && B_DIV == 'A')
		return (1);
	else if (A_DIV != '^')
		return (2);
	else if (B_DIV_BOT != '$' && A_DIV == '^' && B_DIV == '^')
		return (4);
	else
		return (0);
}
