/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:58:57 by louis             #+#    #+#             */
/*   Updated: 2020/08/27 16:01:34 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int	ft_error(const char *error_str)
{
	int	index;

	index = 0;
	while (error_str[index]) {
		write(2, &error_str[index], 1);
		index++;
	}
	return (1);
}