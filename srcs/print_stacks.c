/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:16:59 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 23:45:53 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	print_stacks(t_stack stack_a, t_stack stack_b)
{
	int	a;
	int	b;
	int	bigger;

	a = stack_a.top;
	b = stack_b.top;
	if (a >= b)
		bigger = a;
	else
		bigger = b;
	while (bigger >= 0)
	{
		if (stack_a.top >= bigger)
			ft_printf("%d", stack_a.num_arr[bigger]);
		ft_printf("\t\t");
		if (stack_b.top >= bigger)
			printf("%d", stack_b.num_arr[bigger]);
		ft_printf("\n");
		bigger--;
	}
	ft_printf("--------\t--------\nstack_a\t\tstack_b\n");
}
