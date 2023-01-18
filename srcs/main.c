/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:32:34 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/18 12:36:40 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int	main(int c, char **args)
{
	int			*numbers;
	int			numbers_count;
	t_stacks	stacks;
	t_arrays	arrays;

	numbers = get_args(c, args);
	initiate_stacks(&stacks, &arrays, numbers);
	if (stacks.top_a == 1 && (stacks.numbers_a[0] < stacks.numbers_a[1]))
		swap_a(&stacks, &arrays, 1);
	else if (arrays.top_a == 1 && (arrays.numbers_a[0] < arrays.numbers_a[1]))
		swap_a(&stacks, &arrays, 1);
	else if (arrays.top_a == 2)
		sort_3(&stacks, &arrays);
	else
		sort_big(&stacks, &arrays);
	free_stacks_arrays(&stacks, &arrays);
}
