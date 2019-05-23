/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:16:25 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/04/14 09:45:57 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			deep_len_to_div_up(t_ring **stack_b)
{
	int		i;
	t_elem	*ptr;

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

int			deep_len_to_div(t_ring **stack)
{
	int		i;
	t_elem	*ptr;

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

static void	free_memory2(t_ring **stack_b)
{
	t_elem	*ptr;
	int		size;
	t_elem	*rem;

	if ((*stack_b)->current == NULL)
		return ;
	ptr = (*stack_b)->current;
	size = (*stack_b)->size;
	if (size >= 1)
	{
		while (--size >= 0)
		{
			rem = ptr->next;
			ft_memdel((void **)&ptr);
			ptr = rem;
		}
	}
}

void		free_memory(t_ring **stack_a, t_ring **stack_b)
{
	t_elem	*ptr;
	int		size;
	t_elem	*rem;

	if ((*stack_a)->current == NULL)
		return (free_memory2(stack_b));
	ptr = (*stack_a)->current;
	size = (*stack_a)->size;
	((*stack_a)->sort -= size);
	while (--size >= 0)
	{
		rem = ptr->next;
		ft_memdel((void **)&ptr);
		ptr = rem;
	}
	free_memory2(stack_b);
}

void		check_stack_a(t_ring **stack_a)
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
