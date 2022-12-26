/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_stacks_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:38:11 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/25 20:07:09 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header_bonus.h"

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
	free_arrs(nums);
}
