/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 08:19:41 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/27 15:50:00 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*check_duplicate(int *arr, int size)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;

	while (++i < size)
	{
		j = arr[i];
		while (k < size - 1)
		{
			if (arr[k] == j && k != i)
			{
				ft_printf(_C_ "Error\n"_R_);
				exit (88);
			}
			k++;
		}
		k = 0;
	}
	return (arr);
}

static void str2num_ext(char *str, int *start, char *wd, int *i)
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
			exit (59);
		}
	}
}

int     	str2num(char *str, int *start)
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
	if (ft_strlen(wd) >= 10 && ft_atoi_true(wd) == -1)
	{
		ft_printf(_C_ "Error\n"_R_);
		exit (56);
	}
	i = ft_atoi(wd);
	free(wd);
	return (i);
}

static void	check_conditions(char *argv[], short *flag, int argc, int *i)
{
	if (argc < 2)
		exit (1);
	else if (ft_strequ(argv[1], "-v") && ft_strequ(argv[2], "-o"))
	{
		*flag = 3;
		(*i)+= 2;
	}
	else if (ft_strequ(argv[1], "-v") && ft_strequ(argv[2], "-p"))
	{
		*flag = 4;
		(*i)+= 2;
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

int			*make_arr(char *argv[], int argc, int *size, short *flag)
{
	int		*stack;
	int		i;
	int		j;

	i = 0;
	stack = malloc(sizeof(int) * 20000);
	check_conditions(argv, flag, argc, &i);
	while(++i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			while (ISSPACE(argv[i][j]) && argv[i][j] != '\0')
				j++;
			if (argv[i][j] == '\0')
				break ;
			else if (!ISNUM(argv[i][j]) && argv[i][j] != '-')
			{
				ft_printf("Error\n");
				exit(55);
			}
			stack[(*size)] = str2num(argv[i], &j);
			(*size)++;
		}
	}
	return (check_duplicate(stack, *size));
}