/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:48:24 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/04/14 09:43:55 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*arr;
	int		size;
	t_ring	*stack_a;
	t_ring	*stack_b;
	char	*str;

	str = NULL;
	size = 0;
	stack_a = create_ring();
	stack_b = create_ring();
	arr = make_arr(argv, argc, &size, &stack_a->bit);
	create_ring_stack(&stack_a, arr, size);
	if (stack_a->current == NULL)
		return (1);
	checker_one(&stack_a, &stack_b, stack_a->bit, str);
	free_memory(&stack_a, &stack_b);
	ft_memdel((void **)&arr);
	ft_memdel((void **)&stack_a);
	ft_memdel((void **)&stack_b);
	return (0);
}
