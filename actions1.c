/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:51:40 by aessaoud          #+#    #+#             */
/*   Updated: 2022/11/29 18:14:12 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

t_stack_a	*cr_stack_a(int size)
{
	t_stack_a	*new_stack;

	new_stack = malloc(sizeof(struct s_stack_a));
	new_stack->top = -1;
	new_stack->size = size;
	new_stack->num_arr = (int *)malloc(sizeof(int) * size);
	return (new_stack);
}

t_stack_b	*cr_stack_b(int size)
{
	t_stack_b	*new_stack;

	new_stack = malloc(sizeof(struct s_stack_b));
	new_stack->top = -1;
	new_stack->size = size;
	new_stack->num_arr = (int *)malloc(sizeof(int) * size);
	return (new_stack);
}

void	fill_a(t_stack_a *stack_a, char **args, int c)
{
	int	num;
	int	i;
	
	num = 0;
	while (--c >= 1)
	{
		stack_a->top++;
		stack_a->num_arr[stack_a->top] = ft_atoi(args[c]);
	}
}

void	swap_a(t_stack_a *stack_a)
{
	int	temp;

	temp = stack_a->num_arr[stack_a->top - 1];
	stack_a->num_arr[stack_a->top - 1] = stack_a->num_arr[stack_a->top];
	stack_a->num_arr[stack_a->top] = temp;
}

void	swap_b(t_stack_b *stack_b)
{
	int	temp;

	temp = stack_b->num_arr[stack_b->top - 1];
	stack_b->num_arr[stack_b->top - 1] = stack_b->num_arr[stack_b->top];
	stack_b->num_arr[stack_b->top] = temp;
}

void	print_nums_a(t_stack_a *stack_a)
{
	int	i;

	i = stack_a->top;
	while (i >= 0)
	{
		printf("ii -- %d\n", stack_a->num_arr[i]);
		i--;
	}
}

void	print_nums_b(t_stack_b *stack_b)
{
	int	i;

	i = stack_b->top;
	while (i >= 0)
	{
		printf("ii -- %d\n", stack_b->num_arr[i]);
		i--;
	}
}

void	push_a(t_stack_a *stack_a, t_stack_b *stack_b)
{
	stack_a->top += 1;
	stack_a->num_arr[stack_a->top] = stack_b->num_arr[stack_b->top];
	stack_b->top -= 1;
}

void	push_b(t_stack_a *stack_a, t_stack_b *stack_b)
{
	stack_b->top += 1;
	stack_b->num_arr[stack_b->top] = stack_a->num_arr[stack_a->top];
	stack_a->top -= 1;
}

void	rotate_a(t_stack_a *stack_a)
{
	int	last_num;
	int	i;

	last_num = stack_a->num_arr[stack_a->top];
	i = stack_a->top + 1;
	while (i-- > 0)
		stack_a->num_arr[i] = stack_a->num_arr[i - 1];
	stack_a->num_arr[0] = last_num;
}

void	reverse_rotate_a(t_stack_a *stack_a)
{
	int	first_num;
	int	i;

	first_num = stack_a->num_arr[0];
	i = 0;
	while (i < stack_a->top)
	{
		stack_a->num_arr[i] = stack_a->num_arr[i + 1];
		i++;
	}
	stack_a->num_arr[stack_a->top] = first_num;
}

void	rotate_b(t_stack_b *stack_b)
{
	int	last_num;
	int	i;

	last_num = stack_b->num_arr[stack_b->top];
	i = stack_b->top + 1;
	while (i-- > 0)
		stack_b->num_arr[i] = stack_b->num_arr[i - 1];
	stack_b->num_arr[0] = last_num;
}

void	reverse_rotate_b(t_stack_b *stack_b)
{
	int	first_num;
	int	i;

	first_num = stack_b->num_arr[0];
	i = 0;
	while (i < stack_b->top)
	{
		stack_b->num_arr[i] = stack_b->num_arr[i + 1];
		i++;
	}
	stack_b->num_arr[stack_b->top] = first_num;
}

int	is_sorted(t_stack_a stack_a)