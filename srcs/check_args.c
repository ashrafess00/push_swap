/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:26:22 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/22 19:36:56 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/my_header.h"

static int	is_number(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]) && s[i] != ' ' && !(s[i] == '-' && ft_isdigit(s[i + 1])))
			return (0);
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	
	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	is_duplicated(char **nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
	{
		j = i + 1;
		while (nums[j])
		{
			if (ft_strcmp(nums[i], nums[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

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
	int		j;
	
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
			numbers_string = ft_strjoin(numbers_string, " ");
			numbers_string = ft_strjoin(numbers_string, args[i]);
			i++;
		}
		if (!is_number(numbers_string))
			return (0);
		numbers = ft_split(numbers_string, ' ');
		if (is_duplicated(numbers))
			return (0);
		if (is_big(numbers))
			return (0);
	}
	return (numbers);
}
