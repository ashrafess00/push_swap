/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:32:34 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 23:45:27 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	check_leaks(void);

int	count_numbers(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(int c, char **args)
{
	char	**numbers;
	int		numbers_count;
	t_stack	stack_a;
	t_stack	stack_b;
	int		cheaper;

	numbers = get_args(c, args);
	if (!numbers)
	{
		printf("ERROR");
		exit(0);
	}
	numbers_count = count_numbers(numbers);
	initiate_stacks(&stack_a, &stack_b, numbers_count);
	if (fill_a(&stack_a, numbers, numbers_count))
	{
		if (stack_a.top == 2)
			sort_3(&stack_a);
		else
			sort_big(&stack_a, &stack_b);
	}
	free_all(&stack_a, &stack_b, numbers);
	check_leaks();
}
