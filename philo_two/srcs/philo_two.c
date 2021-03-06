/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:36:59 by louis             #+#    #+#             */
/*   Updated: 2020/09/25 12:39:09 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structures.h"
#include "../includes/declarations.h"

void	wait_threads_to_quit(t_args *args)
{
	int		index;
	t_philo	*p;

	while (args->args[CURR_PHILO] > 0)
	{
		index = 0;
		sem_post(args->messages);
		sem_post(args->forks);
		sem_post(args->picking);
		while (index < args->args[N_PHILO])
		{
			p = &args->philos[index++];
			sem_post(p->eat);
		}
	}
}

int		main(int ac, char **av)
{
	t_args *args;

	if (!(ac == 5 || ac == 6))
		return (ft_error("Argument number is invalid.\n"));
	if (!(args = (t_args *)malloc(sizeof(t_args))))
		return (EXIT_FAILURE);
	if (parse_arguments(args, ac, av) == EXIT_FAILURE)
		return (ft_free_error("Arguments invalid.\n", args));
	if (init_philosophers(args, args->args[N_PHILO]) == EXIT_FAILURE)
		return (ft_free_error("Cannot init philosophers.\n", args));
	start_philosophers(args);
	wait_threads_to_quit(args);
	clear_philo(args);
	return (EXIT_SUCCESS);
}
