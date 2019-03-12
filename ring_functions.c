//
// Created by Yoshiko Harwyn hoare on 2019-03-11.
//
#include "push_swap.h"

Node	*create_node(int num)
{
    Node *node;

    node = malloc(sizeof(Node));
    if (node == NULL)
        return (NULL);
    node->num = num;
    node->size = 1;
    node->prev = NULL;
    node->next = NULL;
    return (node);
}

int		push_back(Node **root, int num)
{
    Node *node;
    Node *prev_node;

    prev_node = *root;
    node = create_node(num);
    if (*root == NULL)
        *root = node;
    else
    {
        node->next = *root;
        (*root)->prev = node;
        if (prev_node->next == NULL)
            prev_node->next = node;
        else
        {
            while (prev_node->next != *root)
                prev_node = prev_node->next;
            prev_node->next = node;
        }
        node->prev = prev_node;
        (*root)->size++;
    }
    return (0);
}

int		push_top(Node **root, int num)
{
    Node *node;
    Node *last;

    node = create_node(num);
    if (*root == NULL)
    {
        *root = node;
        (*root)->next = node;
        (*root)->prev = node;
    }
    else
    {
        last = (*root)->prev;
        node->next = *root;
        node->prev = last;
        last->next = (*root)->prev = node;
        *root = node;
    }
    return (0);
}

void	print_node(Node **root)
{
    Node *current_node;
    current_node = *root;
    if (*root == NULL)
        return ;
    while (current_node->next != *root && (*root)->next != NULL)
    {
        printf("%d ", current_node->num);
        current_node = current_node->next;
    }
    printf("%d ", current_node->num);
}

Node	*rm_node(Node **root)
{
    Node *curr;
    Node *prev_1;

    curr = *root;
    prev_1 = curr;
    if (*root == NULL)
        return (NULL);
    if ((*root)->next->num == (*root)->num)
    {
        (*root) = NULL;
        free(curr);
        return (NULL);
    }
    prev_1 = (*root)->prev;
    while (prev_1->next != *root)
        prev_1 = prev_1->next;
    (*root) = (*root)->next;
    prev_1->next = *root;
    (*root)->prev = prev_1;
    free(curr);

    return (*root);
}



void	ft_swap_int(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}