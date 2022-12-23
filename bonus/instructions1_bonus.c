/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:10:47 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 23:26:12 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_header.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->top != -1)
	{
		temp = stack->num_arr[stack->top - 1];
		stack->num_arr[stack->top - 1] = stack->num_arr[stack->top];
		stack->num_arr[stack->top] = temp;
	}
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	temp = stack_a->num_arr[stack_a->top - 1];
	stack_a->num_arr[stack_a->top - 1] = stack_a->num_arr[stack_a->top];
	stack_a->num_arr[stack_a->top] = temp;
	temp = stack_b->num_arr[stack_b->top - 1];
	stack_b->num_arr[stack_b->top - 1] = stack_b->num_arr[stack_b->top];
	stack_b->num_arr[stack_b->top] = temp;
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->top > -1)
	{
		stack_a->top += 1;
		stack_a->num_arr[stack_a->top] = stack_b->num_arr[stack_b->top];
		stack_b->top -= 1;
	}
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top > -1)
	{
		stack_b->top += 1;
		stack_b->num_arr[stack_b->top] = stack_a->num_arr[stack_a->top];
		stack_a->top -= 1;
	}
}

void	rotate(t_stack *stack)
{
	int	last_num;
	int	i;

	last_num = stack->num_arr[stack->top];
	i = stack->top + 1;
	while (i-- > 0)
		stack->num_arr[i] = stack->num_arr[i - 1];
	stack->num_arr[0] = last_num;
}

void	reverse_rotate(t_stack *stack)
{
	int	first_num;
	int	i;

	first_num = stack->num_arr[0];
	i = 0;
	while (i < stack->top)
	{
		stack->num_arr[i] = stack->num_arr[i + 1];
		i++;
	}
	stack->num_arr[stack->top] = first_num;
}