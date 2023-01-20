/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:38:14 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/20 21:44:14 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

static void	adapt(t_stacks *stacks, t_arrays *arrays)
{
	int	min;
	int	i;
	int	ra;
	int	rra;

	min = find_min(arrays, 'a');
	i = b_pos_in_a(arrays, min);
	ra = arrays->top_a - i;
	rra = i + 1;
	if (ra < rra)
		rra = -1;
	else
		ra = -1;
	while (ra-- > 0)
		rotate_a(stacks, arrays, 1);
	while (rra-- > 0)
		reverse_rotate_a(stacks, arrays, 1);
}

static int	count_rotations(t_arrays *arrays, int num, t_pos *pos)
{
	int	ia;
	int	ib;
	int	count;

	count = 0;
	ia = a_pos_in_a(arrays, num);
	ib = a_pos_in_b(arrays, num);
	if (ia >= (arrays->top_a / 2) && ib >= (arrays->top_b / 2))
		count = ft_max(arrays->top_a - ia, arrays->top_b - ib + 1);
	else if (ia <= (arrays->top_a / 2) && ib <= (arrays->top_b / 2))
		count = ft_max(ia + 1, ib);
	else if (ia <= (arrays->top_a / 2) && ib >= (arrays->top_b / 2))
		count = ia + 1 + arrays->top_b - ib + 1;
	else if (ia >= (arrays->top_a / 2) && ib <= (arrays->top_b / 2))
		count = arrays->top_a - ia + ib;
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

static int	get_less_ins_i(t_arrays *arrays, t_pos *pos)
{
	int	s_t;
	int	rotaion_count;
	int	index;
	int	rotaion_count_nxt;

	s_t = arrays->top_a;
	rotaion_count = count_rotations(arrays, arrays->numbers_a[s_t], pos);
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
		rotaion_count_nxt = count_rotations(arrays,
				arrays->numbers_a[s_t], pos);
		if (compare_rotaion_counts(&rotaion_count, &rotaion_count_nxt, pos))
			index = s_t;
		s_t--;
	}
	return (index);
}

void	sort_big(t_stacks *stacks, t_arrays *arrays)
{
	int		s_t_a;
	int		s_t_b;
	t_pos	pos;

	repeat_pb(stacks, arrays, 2);
	s_t_a = arrays->top_a;
	while (s_t_a >= 3)
	{
		get_less_ins_i(arrays, &pos);
		push_all_2_b(stacks, arrays, pos);
		s_t_a--;
	}
	sort_3(stacks, arrays);
	s_t_b = arrays->top_b;
	while (s_t_b > -1)
	{
		push_all_2_a(stacks, arrays, arrays->numbers_b[s_t_b]);
		s_t_b--;
	}
	adapt(stacks, arrays);
}
