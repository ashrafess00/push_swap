/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_with.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:53:28 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/15 00:08:44 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	rotate_with_rr(t_stacks *stacks, t_arrays *arrays, int ia, int ib)
{
	int	ra;
	int	rb;

	ra = arrays->top_a - ia;
	rb = arrays->top_b - ib + 1;
	if (ra <= rb)
	{
		repeat_rr(stacks, arrays, ra);
		repeat_rotate_b(stacks, arrays, rb - ra);
	}
	else
	{
		repeat_rr(stacks, arrays, rb);
		repeat_rotate_a(stacks, arrays, ra - rb);
	}
}

void	rotate_with_rrr(t_stacks *stacks, t_arrays *arrays, int ia, int ib)
{
	int	rra;
	int	rrb;

	rra = ia + 1;
	rrb = ib;
	if (rra <= rrb)
	{
		repeat_rrr(stacks, arrays, rra);
		repeat_reverse_rotate_b(stacks, arrays, rrb - rra);
	}
	else
	{
		repeat_rrr(stacks, arrays, rrb);
		repeat_reverse_rotate_a(stacks, arrays, rra - rrb);
	}
}

void	rotate_with_ra_rrb(t_stacks *stacks, t_arrays *arrays, int ia, int ib)
{
	int	ra;
	int	rrb;

	ra = arrays->top_a - ia;
	rrb = ib;
	repeat_rotate_a(stacks, arrays, ra);
	repeat_reverse_rotate_b(stacks, arrays, rrb);
}

void	rotate_with_rra_rb(t_stacks *stacks, t_arrays *arrays, int ia, int ib)
{
	int	rra;
	int	rb;

	rra = ia + 1;
	rb = arrays->top_b - ib + 1;
	repeat_reverse_rotate_a(stacks, arrays, rra);
	repeat_rotate_b(stacks, arrays, rb);
}
