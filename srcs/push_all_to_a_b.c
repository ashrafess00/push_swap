/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_to_a_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:12:31 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/09 16:58:46 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	push_all_2_a(t_stack *stack_a, t_stack *stack_b, int num)
{
	int	i;
	int	ra;
	int	rra;

	i = b_pos_in_a(stack_a, num);
	ra = stack_a->top - i + 1;
	rra = i;
	if (ra >= rra)
		ra = -1;
	else
		rra = -1;
	while (ra-- > 0)
		rotate(stack_a);
	while (rra-- > 0)
		reverse_rotate(stack_a);
	push_a(stack_a, stack_b);
}

void	push_all_2_b(t_stack *stack_a, t_stack *stack_b, t_pos pos)
{
	int	ia;
	int	ib;

	ia = pos.a_pos_in_a;
	ib = pos.a_pos_in_b;
	if (ia >= (stack_a->top / 2) && ib >= (stack_b->top / 2))
		rotate_with_rr(stack_a, stack_b, ia, ib);
	else if (ia <= (stack_a->top / 2) && ib <= (stack_b->top / 2))
		rotate_with_rrr(stack_a, stack_b, ia, ib);
	else if (ia >= (stack_a->top / 2) && ib <= (stack_b->top / 2))
		rotate_with_ra_rrb(stack_a, stack_b, ia, ib);
	else if (ia <= (stack_a->top / 2) && ib >= (stack_b->top / 2))
		rotate_with_rra_rb(stack_a, stack_b, ia, ib);
	push_b(stack_a, stack_b);
}
