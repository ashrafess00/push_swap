/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:17:46 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/18 12:29:23 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	write_error(char *s1, char *s2, char **s3, int *nums)
{
	write (2, "ERROR", 5);
	free_elements(s1, s2, s3, nums);
	exit(0);
}
