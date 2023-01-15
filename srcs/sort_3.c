/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:02:31 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/15 19:07:01 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	sort_3(t_stacks *stacks, t_arrays *arrs)
{
	if (arrs->numbers_a[2] > arrs->numbers_a[1]
		&& arrs->numbers_a[2] < arrs->numbers_a[0])
		swap_a(stacks, arrs, 1);
	else if (arrs->numbers_a[2] > arrs->numbers_a[1]
		&& arrs->numbers_a[1] > arrs->numbers_a[0])
	{
		swap_a(stacks, arrs, 1);
		reverse_rotate_a(stacks, arrs, 1);
	}
	else if (arrs->numbers_a[2] > arrs->numbers_a[1]
		&& arrs->numbers_a[1] < arrs->numbers_a[2])
		rotate_a(stacks, arrs, 1);
	else if (arrs->numbers_a[2] < arrs->numbers_a[1]
		&& arrs->numbers_a[1] > arrs->numbers_a[0]
		&& arrs->numbers_a[2] < arrs->numbers_a[0])
	{
		swap_a(stacks, arrs, 1);
		rotate_a(stacks, arrs, 1);
	}
	else if (arrs->numbers_a[2] < arrs->numbers_a[1]
		&& arrs->numbers_a[1] > arrs->numbers_a[0]
		&& arrs->numbers_a[2] > arrs->numbers_a[0])
		reverse_rotate_a(stacks, arrs, 1);
}
