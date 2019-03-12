//
// Created by Yoshiko Harwyn hoare on 2019-03-11.
//
#include "push_swap.h"

Node	*rra(Node **root)
{
    Node *prev_node;

    prev_node = (*root)->prev;
    *root = prev_node;
    return (*root);
}

Node	*ra(Node **root)
{
    Node *prev_node;

    prev_node = (*root)->next;
    *root = prev_node;
    return (*root);
}

Node	*rrb(Node **root)
{
    Node *prev_node;

    prev_node = (*root)->prev;
    *root = prev_node;
    return (*root);
}

Node	*rb(Node **root)
{
    Node *prev_node;

    prev_node = (*root)->next;
    *root = prev_node;
    return (*root);
}


Node	*sa(Node **root)
{
    ft_swap_int(&(*root)->num, &(*root)->next->num);
    return (*root);
}

Node	*sb(Node **root)
{
    ft_swap_int(&(*root)->num, &(*root)->next->num);
    return (*root);
}

void	pa(Node **stack_a, Node **stack_b)
{
    if (*stack_b == NULL)
        return ;
    push_top(stack_a, (*stack_b)->num);
    rm_node(stack_b);
}

void	pb(Node **stack_a, Node **stack_b)
{
    if (*stack_a == NULL)
        return ;
    push_top(stack_b, (*stack_a)->num);
    rm_node(stack_a);
}

