/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:23:31 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/27 15:53:09 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	Ring	*stack_a;
	Ring	*stack_b;
	int		*arr;
	int		size;
	short	flag;

	size = 0;
	arr = make_arr(argv, argc, &size, &flag);
	stack_a = createRing();
	stack_b = createRing();
	create_ring_stack(&stack_a, arr, size);
	quicksort(arr, 0, size - 1);
	(*stack_a).sort = arr;
	algorithm_pre(&stack_a, &stack_b, arr, size);
	free_memory(&stack_a, &stack_b, size);
	free(arr);
	free(stack_a);
	free(stack_b);
	return (0);
}
