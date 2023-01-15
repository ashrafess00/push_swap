/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_to_a_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:12:31 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/15 01:34:05 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	push_all_2_a(t_stacks *stacks, t_arrays *arrays, int num)
{
	int	i;
	int	ra;
	int	rra;

	i = b_pos_in_a(arrays, num);
	ra = arrays->top_a - i + 1;
	rra = i;
	if (ra >= rra)
		ra = -1;
	else
		rra = -1;
	while (ra-- > 0)
		rotate_a(stacks, arrays, 1);
	while (rra-- > 0)
		reverse_rotate_a(stacks, arrays, 1);
	push_a(stacks, arrays, 1);
}

void	push_all_2_b(t_stacks *stacks, t_arrays *arrays, t_pos pos)
{
	int	ia;
	int	ib;

	ia = pos.a_pos_in_a;
	ib = pos.a_pos_in_b;
	if (ia >= (arrays->top_a / 2) && ib >= (arrays->top_b / 2))
		rotate_with_rr(stacks, arrays, ia, ib);
	else if (ia <= (arrays->top_a / 2) && ib <= (arrays->top_b / 2))
		rotate_with_rrr(stacks, arrays, ia, ib);
	else if (ia >= (arrays->top_a / 2) && ib <= (arrays->top_b / 2))
		rotate_with_ra_rrb(stacks, arrays, ia, ib);
	else if (ia <= (arrays->top_a / 2) && ib >= (arrays->top_b / 2))
		rotate_with_rra_rb(stacks, arrays, ia, ib);
	push_b(stacks, arrays, 1);
}
