/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:18:21 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/25 20:26:34 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header_bonus.h"

static void	_instructions_3(t_stack *stack_a, t_stack *stack_b, char *ins)
{
	if (!ft_strcmp(ins, "ra"))
		rotate(stack_a);
	else if (!ft_strcmp(ins, "rb"))
		rotate(stack_b);
	else if (!ft_strcmp(ins, "rr"))
		rotate_both(stack_a, stack_b);
	else if (!ft_strcmp(ins, "rra"))
		reverse_rotate(stack_a);
	else if (!ft_strcmp(ins, "rrb"))
		reverse_rotate(stack_b);
	else if (!ft_strcmp(ins, "rrr"))
		reverse_rotate_both(stack_a, stack_b);
}

static void	_instructions_2(t_stack *stack_a, t_stack *stack_b, char *ins)
{
	if (!ft_strcmp(ins, "pa"))
		push_a(stack_a, stack_b);
	else if (!ft_strcmp(ins, "pb"))
		push_b(stack_a, stack_b);
}

static void	_instructions_1(t_stack *stack_a, t_stack *stack_b, char *ins)
{
	if (!ft_strcmp(ins, "sa"))
		swap(stack_a);
	else if (!ft_strcmp(ins, "sb"))
		swap(stack_b);
	else if (!ft_strcmp(ins, "ss"))
		swap_both(stack_a, stack_b);
}

void	sort_with_(t_stack *stack_a, t_stack *stack_b, char **instructions)
{
	int	i;

	i = -1;
	while (instructions[++i])
	{
		_instructions_1(stack_a, stack_b, instructions[i]);
		_instructions_2(stack_a, stack_b, instructions[i]);
		_instructions_3(stack_a, stack_b, instructions[i]);
	}
	free_arrs(instructions);
}
