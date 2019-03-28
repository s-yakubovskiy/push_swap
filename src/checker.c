/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 11:48:24 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/27 15:41:48 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	int		*arr;
	int		size;
	Ring	*stack_a;
	Ring	*stack_b;
	char	*str;

	str = NULL;
	stack_a = createRing();
	stack_b = createRing();
	arr = make_arr(argv, argc, &size, &stack_a->bit);
	create_ring_stack(&stack_a, arr, size);
	checker_one(&stack_a, &stack_b, stack_a->bit, str);

	return (0);
}