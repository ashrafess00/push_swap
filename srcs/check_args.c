/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:26:22 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/23 23:31:27 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

static int	is_min(char	*number)
{
	char	*min;
	int		i;

	min = "-2147483648";
	i = 0;
	while (number[++i])
	{
		if (number[i] > min[i])
			return (1);
		if (number[i] < min[i])
			return (0);
	}
	return (0);
}

static int	is_max(char	*number)
{
	char	*max;
	int		i;

	max = "2147483647";
	i = -1;
	while (number[++i])
	{
		if (number[i] > max[i])
			return (1);
		if (number[i] < max[i])
			return (0);
	}
	return (0);
}

static int	is_big(char **numbers)
{
	int	i;
	int	num_count;
	int	j;

	i = -1;
	while (numbers[++i])
	{
		num_count = ft_strlen(numbers[i]);
		if (num_count > 11 || (num_count == 11 && numbers[i][0] != '-'))
			return (1);
		else if (num_count == 11 && numbers[i][0] == '-')
		{	
			if (is_min(numbers[i]))
				return (1);
		}
		else if (num_count == 10)
		{
			if (is_max(numbers[i]))
				return (1);
		}
	}
	return (0);
}

static int	is_empty(char *arg)
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

char	**get_args(int c, char **args)
{
	char	*numbers_string;
	char	**numbers;
	int		i;

	if (c >= 2)
	{
		numbers_string = ft_calloc(1, 1);
		i = 1;
		while (i < c)
		{
			if (is_empty(args[i]))
				return (0);
			numbers_string = ft_strjoin(numbers_string, ft_strdup(" "));
			numbers_string = ft_strjoin(numbers_string, ft_strdup(args[i]));
			i++;
		}
		free(numbers_string);
		if (!is_number(numbers_string))
			return (0);
		numbers = ft_split(numbers_string, ' ');
		if (is_duplicated(numbers) || is_big(numbers))
			return (0);
	}
	return (numbers);
}
