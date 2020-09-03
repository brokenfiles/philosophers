/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:04:48 by louis             #+#    #+#             */
/*   Updated: 2020/08/30 17:21:16 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structures.h>
#include <declarations.h>
#include <libc.h>

int	is_str_digit(const char *str)
{
	int	index;

	index = 0;
	while (str[index]) {
		if (!ft_isdigit(str[index]))
			return (0);
		index++;
	}
	return (1);
}

int	check_arguments(t_args *args)
{
	if (args->args[N_PHILO] < 2) {
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parse_arguments(t_args *args, int ac, char **av)
{
	int	index;
	int	tmp;

	index = 1;
	args->n_args = ac - 1;
	while (index < ac)
	{
		tmp = ft_atoi(av[index]);
		if (tmp < 0 || !is_str_digit(av[index]))
			return (EXIT_FAILURE);
		args->args[index - 1] = tmp;
		index++;
	}
	if (check_arguments(args) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}