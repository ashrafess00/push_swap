/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 22:25:37 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 22:38:11 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_header.h"

static void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->num_arr);
	free(stack_b->num_arr);
}

static void	free_arrs(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
}

void	free_all(t_stack *stack_a, t_stack *stack_b, char **numbers, char **instructions)
{
	free_arrs(numbers);
	free_arrs(instructions);
	free_stacks(stack_a, stack_b);
	free(numbers);
	free(instructions);
}