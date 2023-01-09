/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:38:14 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/09 17:01:39 by aessaoud         ###   ########.fr       */
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

static int	count_rotations(t_stack *stack_a, t_stack *stack_b, int num,
t_pos *pos)
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
	pos->a_pos_in_a = ia;
	pos->a_pos_in_b = ib;
	return (count + 1);
}

static int	compare_rotaion_counts(int *rotaion_count, int *rotaion_count_nxt,
t_pos *pos)
{
	if (*rotaion_count > *rotaion_count_nxt)
	{
		*rotaion_count = *rotaion_count_nxt;
		pos->a_pos_in_a_tmp = pos->a_pos_in_a;
		pos->a_pos_in_b_tmp = pos->a_pos_in_b;
		return (1);
	}
	else
	{
		pos->a_pos_in_a = pos->a_pos_in_a_tmp;
		pos->a_pos_in_b = pos->a_pos_in_b_tmp;
		return (0);
	}
}

static int	get_less_ins_i(t_stack *stack_a, t_stack *stack_b, t_pos *pos)
{
	int	s_t;
	int	rotaion_count;
	int	index;
	int	rotaion_count_nxt;

	s_t = stack_a->top;
	rotaion_count = count_rotations(stack_a, stack_b,
			stack_a->num_arr[s_t], pos);
	index = s_t;
	pos->a_pos_in_a_tmp = pos->a_pos_in_a;
	pos->a_pos_in_b_tmp = pos->a_pos_in_b;
	if (rotaion_count == 1)
		return (index);
	s_t--;
	while (s_t >= 0 && rotaion_count != 1)
	{
		if (rotaion_count == 1)
			return (index);
		rotaion_count_nxt = count_rotations(stack_a, stack_b,
				stack_a->num_arr[s_t], pos);
		if (compare_rotaion_counts(&rotaion_count, &rotaion_count_nxt, pos))
			index = s_t;
		s_t--;
	}
	return (index);
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	int		s_t_a;
	int		less_ins_i;
	int		s_t_b;
	t_pos	pos;

	repeat_pb(stack_a, stack_b, 2);
	s_t_a = stack_a->top;
	while (s_t_a >= 3)
	{
		less_ins_i = get_less_ins_i(stack_a, stack_b, &pos);
		push_all_2_b(stack_a, stack_b, pos);
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
