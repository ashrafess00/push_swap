/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:12:05 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/15 19:06:38 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	swap_both(t_stacks *stacks, t_arrays *arrays, int print)
{
	swap_a(stacks, arrays, 0);
	swap_b(stacks, arrays, 0);
	if (print)
		ft_printf("ss\n");
}

void	rotate_both(t_stacks *stacks, t_arrays *arrays, int print)
{
	rotate_a(stacks, arrays, 0);
	rotate_b(stacks, arrays, 0);
	if (print)
		ft_printf("rr\n");
}

void	reverse_rotate_both(t_stacks *stacks, t_arrays *arrays, int print)
{
	reverse_rotate_a(stacks, arrays, 0);
	reverse_rotate_b(stacks, arrays, 0);
	if (print)
		ft_printf("rrr\n");
}
