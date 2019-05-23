/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:54:09 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/29 14:49:22 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rra(t_ring **root)
{
	t_elem *prev_node;

	if ((*root)->current == NULL)
		return ;
	prev_node = (*root)->current->prev;
	(*root)->current = prev_node;
	ft_printf("rra\n");
}

void		ra(t_ring **root)
{
	t_elem *prev_node;

	if ((*root)->current == NULL)
		return ;
	prev_node = (*root)->current->next;
	(*root)->current = prev_node;
	ft_printf("ra\n");
}

static void	median_helper(int *q_sorted, int *eap, int *median, int len)
{
	if (EVEN(len))
	{
		*median = q_sorted[(len / 2) - 1];
		*eap = len - (len / 2);
	}
	else
	{
		*median = q_sorted[len / 2];
		*eap = len - (len / 2 + 1);
	}
}

void		list2arr(t_ring **root, int *median, int *eap)
{
	t_elem	*ptr;
	int		i;
	int		len;
	int		*q_sorted;

	i = -1;
	if ((*root)->current->div == 'A')
		len = deep_len_to_div(root);
	else
		len = (*root)->size;
	ptr = (*root)->current;
	q_sorted = malloc(sizeof(int) * len + 3);
	while (++i < len)
	{
		q_sorted[i] = ptr->num;
		ptr = ptr->next;
	}
	quicksort(q_sorted, 0, len - 1);
	median_helper(q_sorted, eap, median, len);
	free(q_sorted);
}

int			check_a_stack_sorted(t_ring **stack_a, t_ring **stack_b)
{
	t_elem	*ptr;
	int		size;

	ptr = (*stack_a)->current;
	size = (*stack_a)->size;
	while (--size)
	{
		if (ptr->num > ptr->next->num)
			return (-1);
		ptr = ptr->next;
	}
	if (B_SIZE == 0 || (*stack_b)->current == NULL)
		return (1);
	else
		return (-1);
}
