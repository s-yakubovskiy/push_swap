//
// Created by Yoshiko Harwyn hoare on 2019-03-12.
//

#include "push_swap.h"

void	print_arr(int *arr, int size)
{
    int i;

    i = -1;
    while (++i < size)
        ft_printf("%d ", arr[i]);
}

int     str2num(char *str, int *start)
{
    int i;
    char *wd;

    i = 0;
    wd = ft_strnew(20);
    if (str[(*start)] == '-')
    {
        wd[i++] = '-';
        (*start)++;
    }
    while (ISNUM(str[(*start)]))
    {
        wd[i] = str[(*start)];
        i++;
        (*start)++;
    }
    if (ft_strlen(wd) > 10)
        exit (56);
    i = ft_atoi(wd);
    return (i);
}

int		*make_stack(char *argv[], int argc)
{
    int		*stack;
    char    *str;
    int		i;
    int		j;
    int     k;

    i = 0;
    k = 0;
    stack = malloc(sizeof(int) * 3000);
    while(argv[++i])
    {
        str = argv[i];
        j = 0;
        while(str[j])
        {
            while (ISSPACE(str[j]) && str[j] != '\0')
                j++;
            if (str[j] == '\0')
                break ;
            else if (!ISNUM(str[j]) && str[j] != '-')
                exit(55);
            stack[k] = str2num(str, &j);
            k++;
        }
    }
    return (stack);
}