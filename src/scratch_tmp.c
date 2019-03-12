////
//// Created by Yoshiko Harwyn hoare on 2019-03-11.
////
//
///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   main.c                                             :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2019/02/28 18:23:31 by yharwyn-          #+#    #+#             */
///*   Updated: 2019/03/10 12:58:59 by yharwyn-         ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "push_swap.h"
//
//void	print_arr(int *arr, int size)
//{
//    int i;
//
//    i = -1;
//    while (++i < size)
//        ft_printf("%d ", arr[i]);
//}
//
//
//// int		ft_atoi(const char *str)
//// {
//// 	int					i;
//// 	unsigned long long	res;
//// 	int					sign;
//
//// 	i = 0;
//// 	res = 0;
//// 	sign = 1;
//// 	if (*str == '\0')
//// 		return (0);
//// 	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\n' || \
//// 		str[i] == '\f' || str[i] == '\t' || str[i] == '\r')
//// 		++i;
//// 	(str[i] == '-') ? sign *= -1 : sign;
//// 	if (str[i] == '-' || str[i] == '+')
//// 		i++;
//// 	while (str[i] >= '0' && str[i] <= '9')
//// 	{
//// 		res = (res * 10) + str[i] - 48;
//// 		++i;
//// 	}
//// 	if (res > 9223372036854775807)
//// 	{
//// 		return (sign < 0) ? 0 : -1;
//// 	}
//// 	return ((int)res * sign);
//// }
//
//
//
//
//
//
//int		check_digit(char *str)
//{
//    int i;
//
//    i = 0;
//    if (ft_strlen(str) > 10)
//        return (-1);
//    while (str[i] != '\0')
//    {
//        if (ISNUM(str[i]) || str[i] == '-')
//            i++;
//        else if (str[i] == ' ')
//        {
//            printf("i:%dbl!!!\n", i);
//            return (2);
//        }
//        else
//            return (-1);
//    }
//
//    return (1);
//}
//
//int		*check_dupl(int *stack, int size)
//{
//    int i;
//    int j;
//
//    i = 0;
//    while (i < size)
//    {
//        j = 0;
//        while (j < size)
//        {
//            if (stack[i] == stack[j] && i != j)
//                return (NULL);
//            j++;
//        }
//        i++;
//    }
//    return (stack);
//}
//
//int		*make_stack(char *argv[], int argc)
//{
//    int		*stack;
//    int		i;
//    int		j;
//    char	**split;
//    int		k;
//
//    stack = malloc(sizeof(int) * argc + 1);
//    i = 1;
//    j = 0;
//    k = 0;
//    while (argv[i])
//    {
//        if (check_digit(argv[i]) == -1)
//            return (NULL);
//        else if (check_digit(argv[i]) == 2)
//        {
//            printf("I IS:%d %s\n", i, argv[i]);
//            split = ft_strsplit(argv[i], ' ');
//            while (split[k + 1] != '\0')
//            {
//                stack[j] = ft_atoi(split[k]);
//                j++;
//                k++;
//
//                printf("\ncycle split:%s\n stack:%d", split[k], stack[j]);
//            }
//            i++;
//            break ;
//        }
//        stack[j] = ft_atoi(argv[i]);
//        j++;
//        i++;
//    }
//    return (check_dupl(stack, argc - 1));
//}
//
////
////int	main(int argc, char *argv[])
////{
////    Node *stack_a;
////    Node *stack_b;
////
////    stack_a = NULL;
////    stack_b = NULL;
////
////
////    /*
////
////	if ((arr = make_stack(argv, argc)) != NULL)
////		print_arr(make_stack(argv, argc), argc - 1);
////
////
////     */
////    return(0);
////}