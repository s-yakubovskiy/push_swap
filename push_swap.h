/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:41:22 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/11 13:30:28 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include "libft.h"
# include "lib/printf/ft_printf.h"

// # define PILE_B_LAST (pile_b->nbr)[pile_b->size - 1]
// # define PILE_A_LAST (pile_a->nbr)[pile_a->size - 1]
# define TRUE 1
# define FALSE 0

# define ISNUM(x) (x >= '0' && x <= '9')

# define ISSPACE(x) (x == ' ' || x == '\n')
// # define INT_MAX 2147483647


typedef struct		_Node
{
	int				num;
	int 			size;
	struct _Node	*prev;
	struct _Node	*next;
}					Node;

/*
** 		NODE FUNCTIONS
*/

int		push_back(Node **root, int num);
int		push_top(Node **root, int num);
Node	*create_node(int num);
void	print_node(Node **root);
Node	*rm_node(Node **root);

/*
** 		PUSH_SWAP FUNCS
*/

Node	*ra(Node **root);
Node	*rra(Node **root);
Node	*rb(Node **root);
Node	*rrb(Node **root);
Node	*sa(Node **root);
Node	*sb(Node **root);
void	pb(Node **stack_a, Node **stack_b);
void	pa(Node **stack_a, Node **stack_b);

/*
** 		VALIDATE_FUNCS
*/

int     str2num(char *str, int *start);
int		*make_stack(char *argv[], int argc);



/*
** 		AUX FUNCS
*/

void	ft_swap_int(int *a, int *b);
void	print_arr(int *arr, int size);


#endif
