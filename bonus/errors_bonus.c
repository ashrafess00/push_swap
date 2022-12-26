/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:17:46 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/25 20:07:32 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header_bonus.h"

void	write_error_1(char *numbers_string)
{
	write (2, "ERROR", 5);
	free(numbers_string);
	check_leaks();
	exit(0);
}

void	write_error_2(char **numbers)
{
	write (2, "ERROR", 5);
	free_arrs(numbers);
	check_leaks();
	exit(0);
}

void	write_error_3(char *numbers_string, char **numbers)
{
	write (2, "ERROR", 5);
	free_arrs(numbers);
	free(numbers_string);
	check_leaks();
	exit(0);
}

void	write_error_4(char *s1, char *s2, char **numbers)
{
	write (2, "ERROR", 5);
	free_arrs(numbers);
	free(s1);
	free(s2);
	check_leaks();
	exit(0);
}
