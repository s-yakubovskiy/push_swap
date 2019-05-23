/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:19:41 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/04/14 11:36:02 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	str2num_ext(char *str, int *start, char *wd, int *i)
{
	if (str[(*start)] == '-')
	{
		if (ISNUM(str[(*start) + 1]))
		{
			wd[(*i)++] = '-';
			(*start)++;
		}
		else
		{
			ft_printf(_C_ "Error\n"_R_);
			ft_memdel((void **)&wd);
			exit(59);
		}
	}
}

int			str2num(char *str, int *start)
{
	int		i;
	char	*wd;

	i = 0;
	wd = ft_strnew(20);
	str2num_ext(str, start, wd, &i);
	while (ISNUM(str[(*start)]))
	{
		wd[i] = str[(*start)];
		i++;
		(*start)++;
	}
	if (str[*start] == '-')
	{
		ft_printf(_C_ "Error\n"_R_);
		exit(55);
	}
	if (ft_strlen(wd) >= 10 && ft_atoi_true(wd) == -1)
	{
		ft_printf(_C_ "Error\n"_R_);
		exit(56);
	}
	i = ft_atoi(wd);
	free(wd);
	return (i);
}

static void	check_conditions(char *argv[], short *flag, int argc, int *i)
{
	if (argc < 2)
		exit(1);
	else if (ft_strequ(argv[1], "-v") && ft_strequ(argv[2], "-o"))
	{
		*flag = 3;
		(*i) += 2;
	}
	else if (ft_strequ(argv[1], "-v") && ft_strequ(argv[2], "-p"))
	{
		*flag = 4;
		(*i) += 2;
	}
	else if (ft_strequ(argv[1], "-v"))
	{
		*flag = 1;
		(*i)++;
	}
	else if (ft_strequ(argv[1], "-o"))
	{
		*flag = 2;
		(*i)++;
	}
}

int			make_arr2(char *argv[], int *i, int *j, int *stack)
{
	if (argv[*i][*j] == '\0')
		return (-1);
	else if (!ISNUM(argv[*i][*j]) && argv[*i][*j] != '-')
	{
		ft_printf(_C_"Error\n"_R_);
		ft_memdel((void **)&stack);
		exit(55);
	}
	return (0);
}

int			*make_arr(char *argv[], int argc, int *size, short *flag)
{
	int		*stack;
	int		i;
	int		j;

	i = 0;
	stack = ft_memalloc(sizeof(int) * 20000);
	check_conditions(argv, flag, argc, &i);
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			while (ISSPACE(argv[i][j]) && argv[i][j] != '\0')
				j++;
			if (make_arr2(argv, &i, &j, stack) == -1)
				break ;
			stack[(*size)] = str2num(argv[i], &j);
			(*size)++;
		}
	}
	return (check_duplicate(stack, *size));
}
