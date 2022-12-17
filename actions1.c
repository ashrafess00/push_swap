/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:51:40 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/16 20:18:05 by aessaoud         ###   ########.fr       */
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
	new_stack->instructions = (int **) malloc(6 * sizeof(int *));
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
	ft_printf("sa\n");
}

void	swap_b(t_stack_b *stack_b)
{
	int	temp;

	temp = stack_b->num_arr[stack_b->top - 1];
	stack_b->num_arr[stack_b->top - 1] = stack_b->num_arr[stack_b->top];
	stack_b->num_arr[stack_b->top] = temp;
	ft_printf("sb\n");
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
	ft_printf("pa\n");
}

void	push_b(t_stack_a *stack_a, t_stack_b *stack_b)
{
	stack_b->top += 1;
	stack_b->num_arr[stack_b->top] = stack_a->num_arr[stack_a->top];
	stack_a->top -= 1;
	ft_printf("pb\n");
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
	ft_printf("ra\n");
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
	ft_printf("rb\n");
}

void	rotate_both(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int	last_num_a;
	int	last_num_b;
	int	i;

	last_num_a = stack_b->num_arr[stack_b->top];
	i = stack_b->top + 1;
	while (i-- > 0)
		stack_b->num_arr[i] = stack_b->num_arr[i - 1];
	stack_b->num_arr[0] = last_num_a;
	

	last_num_b = stack_a->num_arr[stack_a->top];
	i = stack_a->top + 1;
	while (i-- > 0)
		stack_a->num_arr[i] = stack_a->num_arr[i - 1];
	stack_a->num_arr[0] = last_num_b;
	ft_printf("rr\n");
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
	ft_printf("rra\n");
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
	ft_printf("rrb\n");
}

void	reverse_rotate_both(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int	first_num_a;
	int	first_num_b;
	int	i;

	first_num_a = stack_a->num_arr[0];
	i = 0;
	while (i < stack_a->top)
	{
		stack_a->num_arr[i] = stack_a->num_arr[i + 1];
		i++;
	}
	stack_a->num_arr[stack_a->top] = first_num_a;

	first_num_b = stack_b->num_arr[0];
	i = 0;
	while (i < stack_b->top)
	{
		stack_b->num_arr[i] = stack_b->num_arr[i + 1];
		i++;
	}
	stack_b->num_arr[stack_b->top] = first_num_b;
	ft_printf("rrr\n");
}
