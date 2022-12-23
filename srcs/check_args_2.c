/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:59:26 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 23:04:54 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int	is_number(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ' '
			&& !(s[i] == '-' && ft_isdigit(s[i + 1])))
			return (0);
	}
	return (1);
}

int	is_duplicated(char **nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
	{
		j = i + 1;
		while (nums[j])
		{
			if (ft_strcmp(nums[i], nums[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_a_sorted(t_stack *stack_a)
{
	int	s_t;
	int	s_t2;

	s_t = stack_a->top;
	while (s_t >= 0)
	{
		s_t2 = s_t - 1;
		while (s_t2 >= 0)
		{
			if (stack_a->num_arr[s_t] > stack_a->num_arr[s_t2])
				return (0);
			s_t2--;
		}
		s_t--;
	}
	return (1);
}
