/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:51:40 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/20 21:47:06 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header_bonus.h"

void	swap_a(t_stacks *stacks, t_arrays *arrays, int print)
{
	int	tmp;

	pop(stacks, 'a');
	pop(stacks, 'a');
	tmp = arrays->numbers_a[arrays->top_a - 1];
	arrays->numbers_a[arrays->top_a - 1] = arrays->numbers_a[arrays->top_a];
	arrays->numbers_a[arrays->top_a] = tmp;
	push(stacks, arrays->numbers_a[arrays->top_a - 1], 'a');
	push(stacks, arrays->numbers_a[arrays->top_a], 'a');
	if (print)
		ft_printf("sa\n");
}

void	swap_b(t_stacks *stacks, t_arrays *arrays, int print)
{
	int	tmp;

	pop(stacks, 'b');
	pop(stacks, 'b');
	tmp = arrays->numbers_b[arrays->top_b - 1];
	arrays->numbers_b[arrays->top_b - 1] = arrays->numbers_b[arrays->top_b];
	arrays->numbers_b[arrays->top_b] = tmp;
	push(stacks, arrays->numbers_b[arrays->top_b - 1], 'b');
	push(stacks, arrays->numbers_b[arrays->top_b], 'b');
	if (print)
		ft_printf("sb\n");
}

void	push_a(t_stacks *stacks, t_arrays *arrays, int print)
{
	arrays->top_a += 1;
	arrays->numbers_a[arrays->top_a] = arrays->numbers_b[arrays->top_b];
	arrays->top_b -= 1;
	pop(stacks, 'b');
	push(stacks, arrays->numbers_a[arrays->top_a], 'a');
	if (print)
		ft_printf("pa\n");
}

void	push_b(t_stacks *stacks, t_arrays *arrays, int print)
{
	arrays->top_b += 1;
	arrays->numbers_b[arrays->top_b] = arrays->numbers_a[arrays->top_a];
	arrays->top_a -= 1;
	pop(stacks, 'a');
	push(stacks, arrays->numbers_b[arrays->top_b], 'b');
	if (print)
		ft_printf("pb\n");
}
