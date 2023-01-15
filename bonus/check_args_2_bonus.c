/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:59:26 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/15 18:45:17 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header_bonus.h"

int	is_number(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ' '
			&& !(s[i] == '-' && ft_isdigit(s[i + 1]))
			&& !(s[i] == '+' && ft_isdigit(s[i + 1])))
			return (0);
	}
	return (1);
}

int	is_duplicated(int *nums)
{
	int	i;
	int	j;

	i = 1;
	while (i <= nums[0])
	{
		j = i + 1;
		while (j <= nums[0])
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_a_sorted(t_arrays *arrays)
{
	int	s_t;
	int	s_t2;

	s_t = arrays->top_a;
	while (s_t >= 0)
	{
		s_t2 = s_t - 1;
		while (s_t2 >= 0)
		{
			if (arrays->numbers_a[s_t] > arrays->numbers_a[s_t2])
				return (0);
			s_t2--;
		}
		s_t--;
	}
	return (1);
}

int	is_instruction(char *ins)
{
	if (!ft_strcmp(ins, "sa\n") || !ft_strcmp(ins, "sb\n")
		|| !ft_strcmp(ins, "ss\n") || !ft_strcmp(ins, "pa\n")
		|| !ft_strcmp(ins, "pb\n") || !ft_strcmp(ins, "ra\n")
		|| !ft_strcmp(ins, "ra\n") || !ft_strcmp(ins, "rb\n")
		|| !ft_strcmp(ins, "rr\n") || !ft_strcmp(ins, "rra\n")
		|| !ft_strcmp(ins, "rrb\n") || !ft_strcmp(ins, "rrr\n") || ins[0] == '\n')
		return (1);
	return (0);
}
