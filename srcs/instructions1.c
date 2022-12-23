/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:51:40 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 22:54:33 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	swap(t_stack *stack)
{
	int	temp;

	temp = stack->num_arr[stack->top - 1];
	stack->num_arr[stack->top - 1] = stack->num_arr[stack->top];
	stack->num_arr[stack->top] = temp;
	if (stack->which_stack)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
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
	ft_printf("ss\n");
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->top += 1;
	stack_a->num_arr[stack_a->top] = stack_b->num_arr[stack_b->top];
	stack_b->top -= 1;
	ft_printf("pa\n");
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->top += 1;
	stack_b->num_arr[stack_b->top] = stack_a->num_arr[stack_a->top];
	stack_a->top -= 1;
	ft_printf("pb\n");
}
