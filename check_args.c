/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:26:22 by aessaoud          #+#    #+#             */
/*   Updated: 2022/11/27 21:52:36 by aessaoud         ###   ########.fr       */
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
		if (!ft_isdigit(s[i]))
			return (0);
	}
	return (1);
}

int	check_args(int c, char **args)
{
	int	i;
	int	j;
	
	if (c == 1)
		return (0);
	i = 0;
	while (args[++i])
	{
		if (!is_number(args[i]))
			return (0);
		j = i + 1;
		while (args[j])
		{
			if (ft_strncmp(args[i], args[j], ft_strlen(args[i])) == 0)
				return (0);
			j++;
		}
	}
	return (1);
}