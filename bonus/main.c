/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:44:43 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/26 12:19:24 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header_bonus.h"

char	**read_input(char **numbers)
{
	char	*s;
	char	*instructions_string;
	char	**instructions;

	instructions_string = ft_calloc(1, 1);
	s = get_next_line(0);
	if (!is_instruction(s))
		write_error_4(s, instructions_string, numbers);
	instructions_string = ft_strjoin(instructions_string, ft_strdup(s));
	while (s)
	{
		s = get_next_line(0);
		if (s)
		{
			if (!is_instruction(s))
				write_error_4(s, instructions_string, numbers);
			instructions_string = ft_strjoin(instructions_string, s);
		}
	}
	free (s);
	instructions = ft_split(instructions_string, '\n');
	return (instructions);
}

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
	char	**instructions;
	char	**numbers;
	t_stack	stack_a;
	t_stack	stack_b;
	int		number_count;

	numbers = get_args(c, args);
	instructions = read_input(numbers);
	number_count = count_numbers(numbers);
	initiate_stacks(&stack_a, &stack_b, numbers, number_count);
	sort_with_(&stack_a, &stack_b, instructions);
	if (is_a_sorted(&stack_a) && stack_b.top == -1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(&stack_a, &stack_b);
}
