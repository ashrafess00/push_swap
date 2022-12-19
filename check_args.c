/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:26:22 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/19 14:57:49 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"
#include "./libft/libft.h"

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
	}
	return (numbers);
}

// int main(int c, char **args)
// {
// 	char	**s;

// 	s = get_args(c, args);
// 	if(!s)
// 	{
// 		printf("Error");
// 		exit(0);
// 	}
// 	int i = -1;
// 	while (s[++i])
// 	{
// 		printf("%s\n", s[i]);
// 	}
// 	printf("--%d--\n", ft_atoi(s[0]));
// }