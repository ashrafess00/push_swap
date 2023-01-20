/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:26:22 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/15 19:06:08 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int	is_empty(char *arg)
{
	int	i;

	i = -1;
	if (arg[0] == '\0')
		return (1);
	while (arg[++i])
	{
		if (arg[i] != ' ')
			return (0);
	}
	return (1);
}

int	count_numbers(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	*fill_numbers(char *numbers_string)
{
	char		**numbers_strs;
	int			*numbers;
	int			i;
	long long	num;
	int			numbers_count;

	i = -1;
	numbers_strs = ft_split(numbers_string, ' ');
	numbers_count = count_numbers(numbers_strs);
	numbers = (int *) ft_calloc(numbers_count + 1, sizeof(int));
	numbers[0] = numbers_count;
	while (numbers_strs[++i])
	{
		num = ft_atoi_long(numbers_strs[i]);
		if (num > 2147483647 || num < -2147483648)
			write_error(NULL, NULL, numbers_strs, numbers);
		numbers[numbers_count--] = (int) num;
	}
	free_elements(NULL, NULL, numbers_strs, NULL);
	return (numbers);
}

int	*get_args(int c, char **args)
{
	char	*numbers_string;
	int		*numbers;
	int		i;

	if (c == 1)
		exit (0);
	numbers_string = ft_calloc(1, 1);
	i = 1;
	while (i < c)
	{
		if (is_empty(args[i]))
			write_error(numbers_string, NULL, NULL, NULL);
		numbers_string = ft_strjoin(numbers_string, ft_strdup(" "));
		numbers_string = ft_strjoin(numbers_string, ft_strdup(args[i]));
		i++;
	}
	if (!is_number(numbers_string))
		write_error(numbers_string, NULL, NULL, NULL);
	numbers = fill_numbers(numbers_string);
	if (is_duplicated(numbers))
		write_error(NULL, NULL, NULL, numbers);
	return (numbers);
}
