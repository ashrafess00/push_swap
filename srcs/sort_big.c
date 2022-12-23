/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:38:14 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 23:36:58 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

static void	adapt(t_stack *stack_a)
{
	int	min;
	int	i;
	int	ra;
	int	rra;

	min = find_min(stack_a);
	i = b_pos_in_a(stack_a, min);
	ra = stack_a->top - i;
	rra = i + 1;
	if (ra < rra)
		rra = -1;
	else
		ra = -1;
	while (ra-- > 0)
		rotate(stack_a);
	while (rra-- > 0)
		reverse_rotate(stack_a);
}

static int	count_rotations(t_stack *stack_a, t_stack *stack_b, int num)
{
	int	ia;
	int	ib;
	int	count;

	count = 0;
	ia = a_pos_in_a(stack_a, num);
	ib = a_pos_in_b(stack_b, num);
	if (ia >= (stack_a->top / 2) && ib >= (stack_b->top / 2))
		count = ft_max(stack_a->top - ia, stack_b->top - ib + 1);
	else if (ia <= (stack_a->top / 2) && ib <= (stack_b->top / 2))
		count = ft_max(ia + 1, ib);
	else if (ia <= (stack_a->top / 2) && ib >= (stack_b->top / 2))
		count = ia + 1 + stack_b->top - ib + 1;
	else if (ia >= (stack_a->top / 2) && ib <= (stack_b->top / 2))
		count = stack_a->top - ia + ib;
	return (count + 1);
}

static int	cheaper_num(t_stack *stack_a, t_stack *stack_b)
{
	int	s_t;
	int	c;
	int	index;
	int	c2;

	s_t = stack_a->top;
	c = count_rotations(stack_a, stack_b, stack_a->num_arr[s_t]);
	index = s_t;
	s_t--;
	while (s_t >= 0 && c != 1)
	{
		c2 = count_rotations(stack_a, stack_b, stack_a->num_arr[s_t]);
		if (c > c2)
		{
			c = c2;
			index = s_t;
		}
		s_t--;
	}
	return (stack_a->num_arr[index]);
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int	s_t_a;
	int	cheaper;
	int	s_t_b;

	repeat_pb(stack_a, stack_b, 2);
	s_t_a = stack_a->top;
	while (s_t_a >= 3)
	{
		cheaper = cheaper_num(stack_a, stack_b);
		push_all_2_b(stack_a, stack_b, cheaper);
		s_t_a--;
	}
	sort_3(stack_a);
	s_t_b = stack_b->top;
	while (s_t_b > -1)
	{
		push_all_2_a(stack_a, stack_b, stack_b->num_arr[s_t_b]);
		s_t_b--;
	}
	adapt(stack_a);
}
