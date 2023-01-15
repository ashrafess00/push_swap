/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_instructions1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:39:09 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/15 01:33:35 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	repeat_pb(t_stacks *stacks, t_arrays *arrays, int c)
{
	while (c > 0)
	{
		push_b(stacks, arrays, 1);
		c--;
	}
}

void	repeat_rotate_a(t_stacks *stacks, t_arrays *arrays, int c)
{
	while (c > 0)
	{
		rotate_a(stacks, arrays, 1);
		c--;
	}
}

void	repeat_rotate_b(t_stacks *stacks, t_arrays *arrays, int c)
{
	while (c > 0)
	{
		rotate_b(stacks, arrays, 1);
		c--;
	}
}
