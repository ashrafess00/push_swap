/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:14:32 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/15 16:43:01 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header_bonus.h"

void	rotate_a(t_stacks *stacks, t_arrays *arrays, int print)
{
	int	last_num;
	int	i;

	last_num = arrays->numbers_a[arrays->top_a];
	i = arrays->top_a + 1;
	while (i-- > 0)
		arrays->numbers_a[i] = arrays->numbers_a[i - 1];
	arrays->numbers_a[0] = last_num;
	clear_stack(stacks, 'a');
	fill_stack(stacks, arrays, 'a');
	if (print)
		ft_printf("ra\n");
}

void	rotate_b(t_stacks *stacks, t_arrays *arrays, int print)
{
	int	first_num;
	int	i;

	first_num = arrays->numbers_b[arrays->top_b];
	i = arrays->top_b + 1;
	while (i-- > 0)
		arrays->numbers_b[i] = arrays->numbers_b[i - 1];
	arrays->numbers_b[0] = first_num;
	clear_stack(stacks, 'b');
	fill_stack(stacks, arrays, 'b');
	if (print)
		ft_printf("rb\n");
}

void	reverse_rotate_a(t_stacks *stacks, t_arrays *arrays, int print)
{
	int	last_num;
	int	i;

	last_num = arrays->numbers_a[0];
	i = 0;
	while (i < stacks->top_a)
	{
		arrays->numbers_a[i] = arrays->numbers_a[i + 1];
		i++;
	}
	arrays->numbers_a[stacks->top_a] = last_num;
	clear_stack(stacks, 'a');
	fill_stack(stacks, arrays, 'a');
	if (print)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_stacks *stacks, t_arrays *arrays, int print)
{
	int	last_num;
	int	i;

	last_num = arrays->numbers_b[0];
	i = 0;
	while (i < stacks->top_b)
	{
		arrays->numbers_b[i] = arrays->numbers_b[i + 1];
		i++;
	}
	arrays->numbers_b[stacks->top_b] = last_num;
	clear_stack(stacks, 'b');
	fill_stack(stacks, arrays, 'b');
	if (print)
		ft_printf("rrb\n");
}
