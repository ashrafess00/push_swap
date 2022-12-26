/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:56:47 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/25 17:23:35 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	write_error_1(char *numbers_string)
{
	write (2, "ERROR", 5);
	free(numbers_string);
	exit(0);
}

void	write_error_2(char **numbers)
{
	write (2, "ERROR", 5);
	free_arrs(numbers);
	exit(0);
}
