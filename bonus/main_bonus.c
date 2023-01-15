/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:44:43 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/15 20:03:56 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header_bonus.h"

char	**read_input(int *numbers)
{
	char	*s;
	char	*instructions_string;
	char	**instructions;

	instructions_string = ft_calloc(1, 1);
	while (1)
	{
		s = get_next_line(0);
		if (!s)
			break ;
		if (!is_instruction(s))
			write_error(s, instructions_string, NULL, numbers);
		instructions_string = ft_strjoin(instructions_string, ft_strdup(s));
		free(s);
	}
	if (!s && !instructions_string[0])
	{
		free_elements(instructions_string, NULL, NULL, NULL);
		return (0);
	}
	instructions = ft_split(instructions_string, '\n');
	return (instructions);
}

int	main(int c, char **args)
{
	char		**instructions;
	int			*numbers;
	t_stacks	stacks;
	t_arrays	arrays;
	int			number_count;

	numbers = get_args(c, args);
	instructions = read_input(numbers);
	initiate_stacks(&stacks, &arrays, numbers);
	if (!instructions && is_a_sorted(&arrays))
	{
		ft_printf("OK\n");
	}
	else if (!instructions && !is_a_sorted(&arrays))
		ft_printf("KO\n");
	else
	{
		sort_with_(&stacks, &arrays, instructions);
		if (is_a_sorted(&arrays) && arrays.top_b == -1)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	free_stacks_arrays(&stacks, &arrays);
}
