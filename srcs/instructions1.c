/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:51:40 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 19:48:09 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int	is_a_sorted(t_stack *stack_a)
{
	int	s_t;
	int	s_t2;

	s_t = stack_a->top;
	while (s_t >= 0)
	{
		s_t2 = s_t - 1;
		while (s_t2 >= 0)
		{
			if (stack_a->num_arr[s_t] > stack_a->num_arr[s_t2])
				return (0);
			s_t2--;
		}
		s_t--;
	}
	return (1);
}

void	initiate_stacks(t_stack *stack_a, t_stack *stack_b, int size)
{
	stack_a->top = -1;
	stack_b->top = -1;
	stack_a->num_arr = malloc(size * sizeof(int));
	stack_b->num_arr = malloc(size * sizeof(int));
	stack_a->which_stack = 1;
	stack_b->which_stack = 0;
}

int	fill_a(t_stack *stack_a, char **numbers, int c)
{
	int	num;
	int	i;

	num = 0;
	i = -1;
	while (--c >= 0)
	{
		stack_a->top++;
		num = ft_atoi(numbers[c]);
		stack_a->num_arr[stack_a->top] = num;
	}
	if (is_a_sorted(stack_a))
		return (0);
	return (1);
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
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

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
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
