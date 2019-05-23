/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 08:00:43 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/04/14 09:29:32 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checker_two_3(t_ring **stack_a, t_ring **stack_b, char *str)
{
	if (ft_strequ(str, "rrb"))
		rrb_(stack_b);
	else if (ft_strequ(str, "rr"))
		rr_(stack_a, stack_b);
	else if (ft_strequ(str, "rb"))
		rb_(stack_b);
	else if (ft_strequ(str, "rra"))
		rra_(stack_a);
	else if (ft_strequ(str, "rrr"))
		rrr_(stack_a, stack_b);
	else if (ft_strequ(str, "ss"))
		ss_(stack_a, stack_b);
	else
		return (-1);
	return (0);
}

static int	checker_two(t_ring **stack_a, t_ring **stack_b,
		char *str, short flag)
{
	while (get_next_line(0, &str) == 1)
	{
		if (ft_strequ(str, "pa"))
			pa_(stack_a, stack_b);
		else if (ft_strequ(str, "pb"))
			pb_(stack_a, stack_b);
		else if (ft_strequ(str, "sa"))
			sa_(stack_a);
		else if (ft_strequ(str, "sb"))
			sb_(stack_b);
		else if (ft_strequ(str, "ra"))
			ra_(stack_a);
		else
		{
			if (checker_two_3(stack_a, stack_b, str) == -1)
			{
				ft_memdel((void **)&str);
				return (-1);
			}
		}
		flag == 2 ? print_stacks(*stack_a, *stack_b) : 0;
		ft_memdel((void **)&str);
	}
	ft_memdel((void **)&str);
	return (0);
}

static void	checker_four_2(t_ring **stack_a, t_ring **stack_b, char *str)
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

static void	checker_four(t_ring **stack_a, t_ring **stack_b, char *str)
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

void		checker_one(t_ring **stack_a, t_ring **stack_b,
		short flag, char *str)
{
	if (flag == 0 || flag == 1 || flag == 2)
	{
		if (checker_two(stack_a, stack_b, str, flag) == -1)
		{
			ft_memdel((void **)&str);
			ft_printf(_C_"!!!Error\n"_R_);
			return ;
		}
		else
		{
			if (check_a_stack_sorted(stack_a, stack_b) == 1)
				ft_printf(_G_"OK\n"_R_);
			else
				ft_printf(_RED_"KO\n"_R_);
		}
	}
	else
		checker_four(stack_a, stack_b, str);
}
