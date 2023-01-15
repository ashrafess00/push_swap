/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:54:52 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/15 01:33:43 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	push(t_stacks *stacks, int num, char stack)
{
	if (stack == 'a')
	{
		stacks->top_a++;
		stacks->numbers_a[stacks->top_a] = num;
	}
	else if (stack == 'b')
	{
		stacks->top_b++;
		stacks->numbers_b[stacks->top_b] = num;
	}
}

void	pop(t_stacks *stacks, char stack)
{
	if (stack == 'a')
	{
		if (stacks->top_a != -1)
			stacks->top_a--;
	}
	else if (stack == 'b')
	{
		if (stacks->top_b != -1)
			stacks->top_b--;
	}
}

void	clear_stack(t_stacks *stacks, char stack)
{
	if (stack == 'a')
	{
		while (stacks->top_a != -1)
			pop(stacks, 'a');
	}
	else if (stack == 'b')
	{
		while (stacks->top_b != -1)
			pop(stacks, 'b');
	}
}

void	fill_stack(t_stacks *stacks, t_arrays *arrays, char stack)
{
	int	i;

	if (stack == 'a')
	{
		i = -1;
		while (++i <= arrays->top_a)
			push(stacks, arrays->numbers_a[i], 'a');
	}
	else if (stack == 'b')
	{
		i = -1;
		while (++i <= arrays->top_b)
			push(stacks, arrays->numbers_b[i], 'b');
	}
}
