/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:23:31 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/30 18:14:44 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_ring	*stack_a;
	t_ring	*stack_b;
	int		*arr;
	int		size;

	size = 0;
	stack_a = create_ring();
	stack_b = create_ring();
	arr = make_arr(argv, argc, &size, &stack_a->bit);
	create_ring_stack(&stack_a, arr, size);
	quicksort(arr, 0, size - 1);
	(*stack_a).sort = arr;
	algorithm_pre(&stack_a, &stack_b, arr, size);
	free_memory(&stack_a, &stack_b);
	free(arr);
	free(stack_a);
	free(stack_b);
	return (0);
}
