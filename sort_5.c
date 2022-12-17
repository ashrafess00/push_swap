/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:06:40 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/16 18:35:50 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int	i_pos(t_stack_a *stack_a, int num)
{
	int	i;

	i = stack_a->top;
	while (stack_a->num_arr[i] < num &&  i > -1)
		i--;
	return (i + 1);
}

void	sort_5(t_stack_a *stack_a, t_stack_b *stack_b)
{
	int	i;
	int	dr;
	
	i = 1;
	while (++i < stack_a->top + 1)
		push_b(stack_a, stack_b);
	sort_3(stack_a, stack_b);
	if (stack_b->num_arr[stack_b->top] > stack_b->num_arr[stack_b->top - 1])
		swap_b(stack_b);
	while (stack_b->top != -1)
	{
		dr = i_pos(stack_a, stack_b->num_arr[stack_b->top]);
		if (dr == 0)
		{
			push_a(stack_a, stack_b);
			rotate_a(stack_a);
		}
		else if (dr == stack_a->top)
			push_a(stack_a, stack_b);
		else if (dr == stack_a->top)
		{
			push_a(stack_a, stack_b);
			swap_a(stack_a);
		}
		// printf("(%d)\n", dr);
		break;
	}
}