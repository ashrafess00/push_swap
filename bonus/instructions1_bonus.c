/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:10:47 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/25 16:13:31 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header_bonus.h"

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
