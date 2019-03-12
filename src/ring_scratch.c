#include <stdio.h>
#include <stdlib.h>

typedef struct 		_Node
{
	int				num;
	int 			size;
	struct _Node	*prev;
	struct _Node	*next;
}					Node;

int		push_back(Node **root, int num);
int		push_top(Node **root, int num);
Node	*create_node(int num);
void	print_node(Node **root);
Node	*ra(Node **root);
Node	*rra(Node **root);
Node	*sa(Node **root);
Node	*sb(Node **root);
Node	*rm_node(Node **root);
void	ft_swap_int(int *a, int *b);
void	pa(Node **stack_a, Node **stack_b);
void	pb(Node **stack_a, Node **stack_b);



int		main(void)
{
	Node *stack_a;
	Node *stack_b;
	int size;
	int num;
	int rotate;
	int i;

	stack_a = NULL;
	stack_b = NULL;
	

	push_back(&stack_a, 1);
	push_back(&stack_a, 2);
	push_back(&stack_a, 3);
	push_back(&stack_a, 4);
	push_back(&stack_a, 5);
	
	push_back(&stack_b, 12);
	push_back(&stack_b, 13);
	push_back(&stack_b, 14);
	push_back(&stack_b, 15);
	push_back(&stack_b, 16);

	printf("Stack A\n");

	print_node(&stack_a);
	// printf("\n\nafter rotating\n");

	// ra(&stack_a);
	// ra(&stack_a);
	// rra(&stack_a);
	// rra(&stack_a);
	// sa(&stack_a);

	// print_node(&stack_a);

	printf("\n\nStack B\n");
	print_node(&stack_b);


	printf("\n\nPUSH commands\nStack A\n");
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	print_node(&stack_a);

	printf("\n\nStack B\n");
	print_node(&stack_b);

	// printf("\nafter rotating\n\n");
	// rra(&stack_b);
	// print_node(&stack_b);
	// printf("\nafter deleting\n\n");
		// printf(">>%d\n", (stack_a)->size);

	// rm_node(&stack_b);
	// rm_node(&stack_b);
	// rm_node(&stack_b);
	// rm_node(&stack_b);
	// rm_node(&stack_b);
	// rm_node(&stack_b);
	// print_node(&stack_b);

	// printf(">>%d\n", (stack_a)->size);

	// printf("\nafter rotating\n\n");

}

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

	last = (*root)->prev;
	node = create_node(num);
	if (*root == NULL)
		*root = node;
	else
	{
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
	while (current_node->next != *root)
	{
		printf("%d ", current_node->num);
		current_node = current_node->next;
	}
	printf("%d ", current_node->num);
}

Node	*ra(Node **root)
{
	Node *prev_node;

	prev_node = (*root)->prev;
	*root = prev_node;
	return (*root);
}

Node	*rra(Node **root)
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
	push_top(stack_a, (*stack_b)->num);
	rm_node(stack_b);
}

void	pb(Node **stack_a, Node **stack_b)
{
	push_top(stack_b, (*stack_a)->num);
	rm_node(stack_a);
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


/*

int		main(void)
{
	Node *root;
	int size;
	int num;
	int rotate;
	int i;

	root = NULL;
	scanf("%d %d", &size, &rotate);

	for (i = 0; i < size; i++)
	{
		scanf("%d", &num);
		if (push_back(&root, num) == 1)
			return (1);
	}
	print_node(&root);
	printf("\nafter rotating\n\n");
	rotate_node(&root);
	print_node(&root);
}

*/