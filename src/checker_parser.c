/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 08:00:43 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/27 16:34:09 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	checker_two_2(Ring **stack_a, Ring **stack_b, char *str, short flag)
{
	if (ft_strequ(str, "ra"))
	{
		ra_(stack_a);
		flag == 2 ? print_stacks(*stack_a, *stack_b) : 0;
	}
	else if (ft_strequ(str, "rb"))
	{
		rb_(stack_b);
		flag == 2 ? print_stacks(*stack_a, *stack_b) : 0;
	}
	else if (ft_strequ(str, "rra"))
	{
		rra_(stack_a);
		flag == 2 ? print_stacks(*stack_a, *stack_b) : 0;
	}
	else if (ft_strequ(str, "rrb"))
	{
		rrb_(stack_b);
		flag == 2 ? print_stacks(*stack_a, *stack_b) : 0;
	}
	else
	{
		ft_printf("Error\n");
		exit(10);
	}
}

static void	checker_two(Ring **stack_a, Ring **stack_b, char *str, short flag)
{
	while (get_next_line(0, &str) == 1)
	{
		if (ft_strequ(str, "pa"))
		{
			pa_(stack_a, stack_b);
			flag == 2 ? print_stacks(*stack_a, *stack_b) : 0;
		}
		else if (ft_strequ(str, "pb"))
		{
			pb_(stack_a, stack_b);
			flag == 2 ? print_stacks(*stack_a, *stack_b) : 0;
		}
		else if (ft_strequ(str, "sa"))
		{
			sa_(stack_a);
			flag == 2 ? print_stacks(*stack_a, *stack_b) : 0;
		}
		else if (ft_strequ(str, "sb"))
		{
			sb_(stack_b);
			flag == 2 ? print_stacks(*stack_a, *stack_b) : 0;
		}
		else
			checker_two_2(stack_a, stack_b, str, flag);
	}
}

static void	checker_four_2(Ring **stack_a, Ring **stack_b, char *str)
{
	if (ft_strequ(str, "ra"))
	{
		ra_(stack_a);
		python_parser(*stack_a, *stack_b);
	}
	else if (ft_strequ(str, "rb"))
	{
		rb_(stack_b);
		python_parser(*stack_a, *stack_b);
	}
	else if (ft_strequ(str, "rra"))
	{
		rra_(stack_a);
		python_parser(*stack_a, *stack_b);
	}
	else if (ft_strequ(str, "rrb"))
	{
		rrb_(stack_b);
		python_parser(*stack_a, *stack_b);
	}
}

static void	checker_four(Ring **stack_a, Ring **stack_b, char *str)
{
	while (get_next_line(0, &str) == 1)
	{
		if (ft_strequ(str, "pa"))
		{
			pa_(stack_a, stack_b);
			python_parser(*stack_a, *stack_b);
		}
		else if (ft_strequ(str, "pb"))
		{
			pb_(stack_a, stack_b);
			python_parser(*stack_a, *stack_b);
		}
		else if (ft_strequ(str, "sa"))
		{
			sa_(stack_a);
			python_parser(*stack_a, *stack_b);
		}
		else if (ft_strequ(str, "sb"))
		{
			sb_(stack_b);
			python_parser(*stack_a, *stack_b);
		}
		else
			checker_four_2(stack_a, stack_b, str);
	}
}

void		checker_one(Ring **stack_a, Ring **stack_b, short flag, char *str)
{
	if (flag == 0 || flag == 1 || flag == 2)
		checker_two(stack_a, stack_b, str, flag);
	else
	{
		checker_four(stack_a, stack_b, str);
		return ;
	}
	if (check_A_stack_sorted(stack_a) == 1)
		ft_printf(_G_"OK\n"_R_);
	else
		ft_printf(_RED_"KO\n"_R_);
}
