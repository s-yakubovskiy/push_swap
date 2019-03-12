/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:23:31 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/10 12:58:59 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"




int	main(int argc, char *argv[])
{
    Node    *stack_a;
    Node    *stack_b;
    int     *arr;

    stack_a = NULL;
    stack_b = NULL;

    arr = make_stack(argv, argc);
    print_arr(arr, 11);

	return(0);
}