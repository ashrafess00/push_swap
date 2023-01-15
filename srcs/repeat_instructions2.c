/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_instructions2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:32:31 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/15 01:33:27 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	repeat_reverse_rotate_a(t_stacks *stacks, t_arrays *arrays, int c)
{
	while (c > 0)
	{
		reverse_rotate_a(stacks, arrays, 1);
		c--;
	}
}

void	repeat_reverse_rotate_b(t_stacks *stacks, t_arrays *arrays, int c)
{
	while (c > 0)
	{
		reverse_rotate_b(stacks, arrays, 1);
		c--;
	}
}

void	repeat_rr(t_stacks *stacks, t_arrays *arrays, int c)
{
	while (c > 0)
	{
		rotate_both(stacks, arrays, 1);
		c--;
	}
}

void	repeat_rrr(t_stacks *stacks, t_arrays *arrays, int c)
{
	while (c > 0)
	{
		reverse_rotate_both(stacks, arrays, 1);
		c--;
	}
}
