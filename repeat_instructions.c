/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:39:09 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/19 19:05:52 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	repeat_ra(t_stack *stack_a, int c)
{
	while (c > 0)
	{
		rotate(stack_a);
		c--;
	}
}

void	repeat_rb(t_stack *stack_b, int c)
{
	while (c > 0)
	{
		rotate(stack_b);
		c--;
	}
}

void	repeat_rra(t_stack *stack_a, int c)
{
	while (c > 0)
	{
		reverse_rotate(stack_a);
		c--;
	}
}

void	repeat_rrb(t_stack *stack_b, int c)
{
	while (c > 0)
	{
		reverse_rotate(stack_b);
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