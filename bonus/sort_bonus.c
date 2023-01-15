/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:18:21 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/15 18:51:35 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header_bonus.h"

static void	_instructions_3(t_stacks *stacks, t_arrays *arrays, char *ins)
{
	if (!ft_strcmp(ins, "ra"))
		rotate_a(stacks, arrays, 0);
	else if (!ft_strcmp(ins, "rb"))
		rotate_b(stacks, arrays, 0);
	else if (!ft_strcmp(ins, "rr"))
		rotate_both(stacks, arrays, 0);
	else if (!ft_strcmp(ins, "rra"))
		reverse_rotate_a(stacks, arrays, 0);
	else if (!ft_strcmp(ins, "rrb"))
		reverse_rotate_b(stacks, arrays, 0);
	else if (!ft_strcmp(ins, "rrr"))
		reverse_rotate_both(stacks, arrays, 0);
}

static void	_instructions_2(t_stacks *stacks, t_arrays *arrays, char *ins)
{
	if (!ft_strcmp(ins, "pa"))
		push_a(stacks, arrays, 0);
	else if (!ft_strcmp(ins, "pb"))
		push_b(stacks, arrays, 0);
}

static void	_instructions_1(t_stacks *stacks, t_arrays *arrays, char *ins)
{
	if (!ft_strcmp(ins, "sa"))
		swap_a(stacks, arrays, 0);
	else if (!ft_strcmp(ins, "sb"))
		swap_b(stacks, arrays, 0);
	else if (!ft_strcmp(ins, "ss"))
		swap_both(stacks, arrays, 0);
}

void	sort_with_(t_stacks *stacks, t_arrays *arrays, char **instructions)
{
	int	i;

	i = -1;
	while (instructions[++i])
	{
		_instructions_1(stacks, arrays, instructions[i]);
		_instructions_2(stacks, arrays, instructions[i]);
		_instructions_3(stacks, arrays, instructions[i]);
	}
	free_elements(NULL, NULL, instructions, NULL);
}
