/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:52:15 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/25 17:14:17 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	initiate_stacks(t_stack *stack_a, t_stack *stack_b, char **nums, int s)
{
	int	num;
	int	i;

	stack_a->top = -1;
	stack_b->top = -1;
	stack_a->num_arr = malloc(s * sizeof(int));
	stack_b->num_arr = malloc(s * sizeof(int));
	stack_a->which_stack = 1;
	stack_b->which_stack = 0;
	num = 0;
	i = -1;
	while (--s >= 0)
	{
		stack_a->top++;
		num = ft_atoi(nums[s]);
		stack_a->num_arr[stack_a->top] = num;
	}
	if (is_a_sorted(stack_a))
	{
		free_stacks(stack_a, stack_b);
		free_arrs(nums);
		exit(0);
	}
	free_arrs(nums);
}
