/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:52:15 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 22:57:05 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	initiate_stacks(t_stack *stack_a, t_stack *stack_b, int size)
{
	stack_a->top = -1;
	stack_b->top = -1;
	stack_a->num_arr = malloc(size * sizeof(int));
	stack_b->num_arr = malloc(size * sizeof(int));
	stack_a->which_stack = 1;
	stack_b->which_stack = 0;
}

int	fill_a(t_stack *stack_a, char **numbers, int c)
{
	int	num;
	int	i;

	num = 0;
	i = -1;
	while (--c >= 0)
	{
		stack_a->top++;
		num = ft_atoi(numbers[c]);
		stack_a->num_arr[stack_a->top] = num;
	}
	if (is_a_sorted(stack_a))
		return (0);
	return (1);
}
