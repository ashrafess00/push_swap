/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:55:41 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/15 19:07:12 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	i = 0;
	while (ps1[i] != '\0' || ps2[i] != '\0')
	{
		if (ps1[i] > ps2[i])
			return (1);
		else if (ps1[i] < ps2[i])
			return (-1);
		i++;
	}
	return (0);
}

static int	is_ws(char n)
{
	if (n == '\t' || n == '\n' || n == ' '
		|| n == '\v' || n == '\f' || n == '\r')
		return (1);
	return (0);
}

long long	ft_atoi_long(const char *str)
{
	size_t	sign;
	size_t	i;
	size_t	num;

	sign = 1;
	i = 0;
	num = 0;
	while (is_ws(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	return (num * sign);
}
