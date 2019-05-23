/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yharwyn- <yharwyn-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:41:22 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/31 07:57:51 by yharwyn-         ###   ########.fr       */
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

typedef struct		s_elem
{
	int				num;
	int				size;
	char			div;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_ring
{
	int				size;
	int				*sort;
	short			bit;
	t_elem			*current;
}					t_ring;

/*
** 		NODE FUNCTIONS
*/

t_ring				*create_ring(void);
int					push_back(t_ring **ring, int num);
int					push_top(t_ring **ring, int num, char div);
t_elem				*create_node(int num);
t_ring				*rm_node(t_ring **root);
void				create_ring_stack(t_ring **root, int *arr, int size);

/*
** 		PUSH_SWAP FUNCS
*/

void				ra(t_ring **root);
void				rra(t_ring **root);
void				rb(t_ring **root);
void				rrb(t_ring **root);
void				sa(t_ring **root);
void				sb(t_ring **root);
void				pb(t_ring **stack_a, t_ring **stack_b);
void				pa(t_ring **stack_a, t_ring **stack_b);
void				ra_(t_ring **root);
void				rra_(t_ring **root);
void				rb_(t_ring **root);
void				rrb_(t_ring **root);
void				sa_(t_ring **root);
void				sb_(t_ring **root);
void				pb_(t_ring **stack_a, t_ring **stack_b);
void				pa_(t_ring **stack_a, t_ring **stack_b);

/*
** 		VALIDATE_FUNCS
*/

int					str2num(char *str, int *start);
int					*make_arr(char *argv[], int argc, int *size, short *flag);
int					*check_duplicate(int *arr, int size);

/*
** 		ALGORITHM_FUNCS
*/

void				algorithm_pre(t_ring **stack_a, t_ring **stack_b, int *arr,
		int size);
void				list2arr(t_ring **root, int *median, int *eap);
void				sort_three_a(t_ring **stack);
void				queer_sort_b(t_ring **stack_a, t_ring **stack_b);
void				find_minmax(t_ring **stack, int *min, int *max);
void				split_half(t_ring **stack_a, t_ring **stack_b, int median,
		int eap);
void				queer_sort(t_ring **stack_a, t_ring **stack_b);
void				ss_(t_ring **stack_a, t_ring **stack_b);
void				rr_(t_ring **stack_a, t_ring **stack_b);
void				rrr_(t_ring **stack_a, t_ring **stack_b);

/*
** 		ALGORITHM_2_FUNCS
*/

void				split_b_top(t_ring **stack_a, t_ring **stack_b);
void				split_b_bot(t_ring **stack_a, t_ring **stack_b);
void				split_a_top(t_ring **stack_a, t_ring **stack_b);

/*
** 		AUX FUNCS
*/

void				ft_swap_int(int *a, int *b);
void				quicksort(int *arr, int start, int end);
int					partition_hoare(int *arr, int start, int end);
void				print_stacks(t_ring *stack_a, t_ring *stack_b);
void				find_min_index(t_ring **stack_a);
int					deep_len_to_div_up(t_ring **stack_b);
int					deep_len_to_div(t_ring **stack);
void				check_if_top_min(t_ring **stack_a, t_ring **stack_b);
void				free_memory(t_ring **stack_a, t_ring **stack_b);
void				check_stack_a(t_ring **stack_a);
int					check_a_stack_sorted(t_ring **stack_a, t_ring **stack_b);
void				python_parser(t_ring *stack_a, t_ring *stack_b);

/*
** 		SPLITS_CHECK_FUNCS
*/

int					find_ends(t_ring **root);
void				list2arr_from_bot_light(t_ring **root,
	int *median, int *deep);
void				list2arr_light(t_ring **root, int *median);
int					check_for_splits(t_ring **stack_a, t_ring **stack_b);
void				checker_one(t_ring **stack_a, t_ring **stack_b,
	short flag, char *str);
int					ft_atoi_true(const char *str);

#endif
