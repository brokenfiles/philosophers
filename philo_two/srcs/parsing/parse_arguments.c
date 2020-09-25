/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:04:48 by louis             #+#    #+#             */
/*   Updated: 2020/09/25 10:46:53 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"
#include "../../includes/declarations.h"

int	is_str_digit(const char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (0);
		index++;
	}
	return (1);
}

int	check_arguments(t_args *args)
{
	if (args->args[N_PHILO] < 2)
		return (EXIT_FAILURE);
	if (args->n_args > 4 && args->args[PHILO_MAX_EAT] < 1)
		return (EXIT_FAILURE);
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

static int	get_nbr_length(unsigned int nb)
{
	unsigned int index;

	index = 0;
	while (nb >= 10)
	{
		nb /= 10;
		index++;
	}
	return (index + 1);
}

char		*ft_itoa(int nbr)
{
	char			*str;
	unsigned int	nb;
	unsigned int	index;
	unsigned int	size;

	nb = (nbr < 0 ? (unsigned int)(-nbr) : (unsigned int)nbr);
	size = (unsigned int)get_nbr_length(nb);
	index = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + (nbr < 0 ? 2 : 1)))))
		return (0);
	if (nbr < 0)
	{
		str[index] = '-';
		size++;
	}
	index = size - 1;
	while (nb >= 10)
	{
		str[index--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	str[index] = (char)(nb % 10 + 48);
	str[size] = '\0';
	return (str);
}
