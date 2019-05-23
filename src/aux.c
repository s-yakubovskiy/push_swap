/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:16:15 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/31 08:38:39 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stacks_ext(t_ring *stack_a, t_ring *stack_b, int min, int max)
{
	t_elem	*ptr1;
	t_elem	*ptr2;

	ptr1 = stack_a->current;
	ptr2 = stack_b->current;
	while (--max >= 0)
	{
		if (min > 0)
			ft_printf("|%10d   |     |%10d  |\n", ptr1->num, ptr2->num);
		else
		{
			if (stack_a->size >= stack_b->size)
				ft_printf("|%10d   |     |%10c  |\n", ptr1->num, '_');
			else
				ft_printf("|%10c   |     |%10d  |\n", '_', ptr2->num);
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		min--;
	}
}

static void	print_stacks_ext2(t_ring *stack_a, t_ring *stack_b,
		t_elem **ptr1, t_elem **ptr2)
{
	int		max;
	int		min;

	min = _MIN(stack_a->size, stack_b->size);
	max = _MAX(stack_a->size, stack_b->size);
	if (stack_a->current == NULL)
	{
		while (--max >= 0)
		{
			ft_printf("|%10c   |     |%10d  |\n", '_', (*ptr2)->num);
			*ptr2 = (*ptr2)->next;
		}
	}
	else if (stack_b->current == NULL)
	{
		while (--max >= 0)
		{
			ft_printf(_M_"|%10d   |     |%10c  |\n"_R_, (*ptr1)->num, '_');
			*ptr1 = (*ptr1)->next;
		}
	}
	else
		print_stacks_ext(stack_a, stack_b, min, max);
}

void		print_stacks(t_ring *stack_a, t_ring *stack_b)
{
	t_elem	*ptr1;
	t_elem	*ptr2;

	ft_printf(_C_"\n|%10s   |     |%10s  |\n"_R_,
			"STACK_A", "STACK_B");
	ptr1 = stack_a->current;
	ptr2 = stack_b->current;
	print_stacks_ext2(stack_a, stack_b, &ptr1, &ptr2);
}

void		find_minmax(t_ring **stack, int *min, int *max)
{
	int					i;
	t_elem				*ptr;

	i = 0;
	ptr = TOP(*stack);
	*min = (*stack)->current->num;
	*max = (*stack)->current->num;
	while (i < (*stack)->size)
	{
		*min = _MIN(*min, ptr->num);
		*max = _MAX(*max, ptr->num);
		ptr = ptr->next;
		i++;
	}
}

int			*check_duplicate(int *arr, int size)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	while (++i < size)
	{
		j = arr[i];
		while (k < size - 1)
		{
			if (arr[k] == j && k != i)
			{
				ft_printf(_C_ "Error\n"_R_);
				ft_memdel((void **)&arr);
				exit(88);
			}
			k++;
		}
		k = 0;
	}
	return (arr);
}
