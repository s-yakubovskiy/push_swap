/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:41:22 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/27 16:52:24 by yharwyn-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/printf/ft_printf.h"
# include "../lib/printf/libft/get_next_line.h"

/*
** 		MACROS
*/

# define A_TOP ((*stack_a)->current->num)
# define B_TOP ((*stack_b)->current->num)
# define TOP(a) (((a)->current))
# define A_SIZE ((*stack_a)->size)
# define B_SIZE ((*stack_b)->size)
# define B_DIV ((*stack_b)->current->div)
# define A_DIV ((*stack_a)->current->div)
# define A_DIV_BOT ((*stack_a)->current->prev->div)
# define B_DIV_BOT ((*stack_b)->current->prev->div)
# define CUR_MIN ((*stack_a)->sort[0])
# define ISNUM(x) (x >= '0' && x <= '9')
# define ISSPACE(x) (x == ' ' || x == '\n')
# define _MIN(a,b) (((a)<(b))?(a):(b))
# define _MAX(a,b) (((a)>(b))?(a):(b))
# define EVEN(a) (((a)%(2) == 0) ? (1):(0))

/*
** 		COLOURS
*/

# define _C_ "\033[1;96m"
# define _G_ "\033[1;92m"
# define _R_ "\x1b[0m"
# define _RED_ "\033[0;105m"
# define _M_ "\033[1;33m"

/*
** 		STRUCTS
*/

typedef struct		g_Node
{
	int				num;
	int				size;
	char			div;
	struct g_Node	*prev;
	struct g_Node	*next;
}					Node;

typedef struct		g_Ring
{
	unsigned int	size;
	int				*sort;
	short			bit;
	Node			*current;
}					Ring;

/*
** 		NODE FUNCTIONS
*/

Ring*				createRing(void);
int					push_back(Ring **ring, int num);
int					push_top(Ring **ring, int num, char div);
Node				*create_node(int num);
void				print_node(Ring **root);
Ring				*rm_node(Ring **root);
void				create_ring_stack(Ring **root, int *arr, int size);

/*
** 		PUSH_SWAP FUNCS
*/

void				ra(Ring **root);
void				rra(Ring **root);
void				rb(Ring **root);
void				rrb(Ring **root);
void				sa(Ring **root);
void				sb(Ring **root);
void				pb(Ring **stack_a, Ring **stack_b);
void				pa(Ring **stack_a, Ring **stack_b);
void				ra_(Ring **root);
void				rra_(Ring **root);
void				rb_(Ring **root);
void				rrb_(Ring **root);
void				sa_(Ring **root);
void				sb_(Ring **root);
void				pb_(Ring **stack_a, Ring **stack_b);
void				pa_(Ring **stack_a, Ring **stack_b);

/*
** 		VALIDATE_FUNCS
*/

int					str2num(char *str, int *start);
int					*make_arr(char *argv[], int argc, int *size, short *flag);
int					*check_duplicate(int *arr, int size);

/*
** 		ALGORITHM_FUNCS
*/

void				algorithm_pre(Ring **stack_a, Ring **stack_b, int *arr, int size);
void				list2arr(Ring **root, int *median, int *eap);
void				sort_three_a(Ring **stack);
void				queer_sort_b(Ring **stack_a, Ring **stack_b);
void				find_minmax(Ring **stack, int *min, int *max);
void				split_half(Ring **stack_a, Ring **stack_b, int median, int eap);
void				queer_sort(Ring **stack_a, Ring **stack_b);

/*
** 		ALGORITHM_2_FUNCS
*/

void				split_b_top(Ring **stack_a, Ring **stack_b);
void				split_b_bot(Ring **stack_a, Ring **stack_b);
void				split_a_top(Ring **stack_a, Ring **stack_b);

/*
** 		AUX FUNCS
*/

void				ft_swap_int(int *a, int *b);
void				print_arr(int *arr, int size);
void				quicksort(int *arr, int start, int end);
int					partition_hoare(int *arr, int start, int end);
void				print_stacks(Ring *stack_a, Ring *stack_b);
void				find_min_index(Ring **stack_a);
int					deep_len_to_div_up(Ring **stack_b);
int					deep_len_to_div(Ring **stack);
void				check_if_top_min(Ring **stack_a, Ring **stack_b);
void				free_memory(Ring **stack_a, Ring **stack_b, int len);
void				check_stack_a(Ring **stack_a);
int					check_A_stack_sorted(Ring **stack_a);
void				python_parser(Ring *stack_a, Ring *stack_b);

/*
** 		SPLITS_CHECK_FUNCS
*/

int					find_ends(Ring **root);
void				list2arr_from_bot_light(Ring **root, 
	int *median, int *deep);
void				list2arr_light(Ring **root, int *median);
int					check_for_splits(Ring **stack_a, Ring **stack_b);
void				checker_one(Ring **stack_a, Ring **stack_b, 
	short flag, char *str);
int					ft_atoi_true(const char *str);

#endif
