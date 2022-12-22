/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_with.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:53:28 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/22 19:36:56 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/my_header.h"

void	rotate_with_rr(t_stack *stack_a, t_stack *stack_b, int ia, int ib)
{
	int	ra;
	int rb;
	
	ra = stack_a->top - ia;
	rb = stack_b->top - ib + 1;
	if (ra <= rb)
	{
		repeat_rr(stack_a, stack_b, ra);
		repeat_rotate(stack_b, rb - ra);
	}
	else
	{
		repeat_rr(stack_a, stack_b, rb);
		repeat_rotate(stack_a, ra - rb);
	}
}

void	rotate_with_rrr(t_stack *stack_a, t_stack *stack_b, int ia, int ib)
{
	int	rra;
	int rrb;
	
	rra = ia + 1;
	rrb = ib;
	if (rra <= rrb)
	{
		repeat_rrr(stack_a, stack_b, rra);
		repeat_reverse_rotate(stack_b, rrb - rra);
	}
	else
	{
		repeat_rrr(stack_a, stack_b, rrb);
		repeat_reverse_rotate(stack_a, rra - rrb);
	}
}

void	rotate_with_ra_rrb(t_stack *stack_a, t_stack *stack_b, int ia, int ib)
{
	int ra;
	int	rrb;

	ra = stack_a->top - ia;
	rrb = ib;
	repeat_rotate(stack_a, ra);
	repeat_reverse_rotate(stack_b, rrb);
}

void	rotate_with_rra_rb(t_stack *stack_a, t_stack *stack_b, int ia, int ib)
{
	int rra;
	int	rb;

	rra = ia + 1;
	rb = stack_b->top - ib + 1;
	repeat_reverse_rotate(stack_a, rra);
	repeat_rotate(stack_b, rb);
}
