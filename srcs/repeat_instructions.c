/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:39:09 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 23:44:10 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	repeat_pb(t_stack *stack_a, t_stack *stack_b, int c)
{
	while (c > 0)
	{
		push_b(stack_a, stack_b);
		c--;
	}
}

void	repeat_rotate(t_stack *stack, int c)
{
	while (c > 0)
	{
		rotate(stack);
		c--;
	}
}

void	repeat_reverse_rotate(t_stack *stack, int c)
{
	while (c > 0)
	{
		reverse_rotate(stack);
		c--;
	}
}

void	repeat_rr(t_stack *stack_a, t_stack *stack_b, int c)
{
	while (c > 0)
	{
		rotate_both(stack_a, stack_b);
		c--;
	}
}

void	repeat_rrr(t_stack *stack_a, t_stack *stack_b, int c)
{
	while (c > 0)
	{
		reverse_rotate_both(stack_a, stack_b);
		c--;
	}
}
