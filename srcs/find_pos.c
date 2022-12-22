/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:00:06 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/22 19:36:56 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/my_header.h"

static int	find_max(t_stack *stack)
{
	int	max;
	int	s_t;
	int	s_tt;

	s_t = stack->top;
	max = stack->num_arr[s_t];
	while (s_t >= 0)
	{
		int	s_tt = s_t - 1;
		while (s_tt >= 0)
		{
			if (max < stack->num_arr[s_tt])
				max = stack->num_arr[s_tt];
			s_tt--;
		}
		s_t--;
	}
	return(max);
}
int	find_min(t_stack *stack)
{
	int	min;
	int	s_t;
	int	s_tt;

	s_t = stack->top;
	min = stack->num_arr[s_t];
	while (s_t >= 0)
	{
		int	s_tt = s_t - 1;
		while (s_tt >= 0)
		{
			if (min > stack->num_arr[s_tt])
				min = stack->num_arr[s_tt];
			s_tt--;
		}
		s_t--;
	}
	return(min);
}

int a_pos_in_a(t_stack *stack_a, int num)
{
	int	i;

	i = stack_a->top;
	while (stack_a->num_arr[i] != num && i > -1)
		i--;
	return (i);
}

int	a_pos_in_b(t_stack *stack_b, int num)
{
	int	s_t;
	int	max;
	int	min;

	max = find_max(stack_b);
	min = find_min(stack_b);
	s_t = stack_b->top;
	if (num > max || num < min)
	{
		num = max;
		while (stack_b->num_arr[s_t] != num && s_t > -1)
			s_t--;
		return (s_t + 1);
	}
	if (stack_b->num_arr[0] > num && stack_b->num_arr[s_t] < num)
		return (s_t + 1);
	while (s_t > 0)
	{
		if (stack_b->num_arr[s_t] > num && stack_b->num_arr[s_t - 1] < num)
			return (s_t);
		s_t--;
	}
	return (s_t);
}

int	b_pos_in_a(t_stack *stack_a, int num)
{
	int	s_t;
	int	max;
	int	min;

	max = find_max(stack_a);
	min = find_min(stack_a);
	s_t = stack_a->top;
	if (num > max || num < min)
	{
		num = min;
		while (stack_a->num_arr[s_t] != num && s_t > -1)
			s_t--;
		return (s_t + 1);
	}
	if (stack_a->num_arr[0] < num && stack_a->num_arr[s_t] > num)
		return (s_t + 1);
	while (s_t > 0)
	{
		if (stack_a->num_arr[s_t] <= num && stack_a->num_arr[s_t - 1] >= num)
			return (s_t);
		s_t--;
	}
	return (s_t);
}
