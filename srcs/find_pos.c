/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:00:06 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/20 21:45:04 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

static int	find_max(t_arrays *arrays, char stack)
{
	int	max;
	int	s_t;

	max = 0;
	if (stack == 'a')
	{
		s_t = arrays->top_a;
		max = arrays->numbers_a[s_t];
		while (--s_t >= 0)
		{
			if (arrays->numbers_a[s_t] > max)
				max = arrays->numbers_a[s_t];
		}
	}
	else if (stack == 'b')
	{
		s_t = arrays->top_b;
		max = arrays->numbers_b[s_t];
		while (--s_t >= 0)
		{
			if (arrays->numbers_b[s_t] > max)
				max = arrays->numbers_b[s_t];
		}
	}
	return (max);
}

int	find_min(t_arrays *arrays, char stack)
{
	int	min;
	int	s_t;

	min = 0;
	if (stack == 'a')
	{
		s_t = arrays->top_a;
		min = arrays->numbers_a[s_t];
		while (--s_t >= 0)
		{
			if (arrays->numbers_a[s_t] < min)
				min = arrays->numbers_a[s_t];
		}
	}
	else if (stack == 'b')
	{
		s_t = arrays->top_b;
		min = arrays->numbers_b[s_t];
		while (--s_t >= 0)
		{
			if (arrays->numbers_b[s_t] < min)
				min = arrays->numbers_b[s_t];
		}
	}
	return (min);
}

int	a_pos_in_a(t_arrays *arrays, int num)
{
	int	i;

	i = arrays->top_a;
	while (arrays->numbers_a[i] != num && i > -1)
		i--;
	return (i);
}

int	a_pos_in_b(t_arrays *arrays, int num)
{
	int	s_t;
	int	max;
	int	min;

	max = find_max(arrays, 'b');
	min = find_min(arrays, 'b');
	s_t = arrays->top_b;
	if (num > max || num < min)
	{
		num = max;
		while (arrays->numbers_b[s_t] != num && s_t > -1)
			s_t--;
		return (s_t + 1);
	}
	if (arrays->numbers_b[0] > num && arrays->numbers_b[s_t] < num)
		return (s_t + 1);
	while (s_t > 0)
	{
		if (arrays->numbers_b[s_t] > num && arrays->numbers_b[s_t - 1] < num)
			return (s_t);
		s_t--;
	}
	return (s_t);
}

int	b_pos_in_a(t_arrays *arrays, int num)
{
	int	s_t;
	int	max;
	int	min;

	max = find_max(arrays, 'a');
	min = find_min(arrays, 'a');
	s_t = arrays->top_a;
	if (num > max || num < min)
	{
		num = min;
		while (arrays->numbers_a[s_t] != num && s_t > -1)
			s_t--;
		return (s_t + 1);
	}
	if (arrays->numbers_a[0] < num && arrays->numbers_a[s_t] > num)
		return (s_t + 1);
	while (s_t > 0)
	{
		if (arrays->numbers_a[s_t] <= num && arrays->numbers_a[s_t - 1] >= num)
			return (s_t);
		s_t--;
	}
	return (s_t);
}
