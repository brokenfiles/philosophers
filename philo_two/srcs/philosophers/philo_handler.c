/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 13:45:57 by louis             #+#    #+#             */
/*   Updated: 2020/09/15 13:24:47 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"

int			init_struct(t_args *args)
{
	args->args[CURR_PHILO] = args->args[N_PHILO];
	gettimeofday(&args->t_start, NULL);
	return (EXIT_SUCCESS);
}

long int	current_time(t_args args)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return ((current.tv_usec - args.t_start.tv_usec) / 1000
			+ (current.tv_sec - args.t_start.tv_sec) * 1000);
}

t_philo		init_philo(t_args *args, int id)
{
	t_philo philo;

	philo.id = id;
	philo.args = args;
	philo.fed = 0;
	philo.eat_count = 0;
	philo.state = THINKING;
	philo.eat = malloc(sizeof(sem_t));
	sem_init(philo.eat, O_CREAT, 1);
	philo.timeout = args->args[T_TO_DIE] + current_time(*args);
	return (philo);
}

int			init_sem(t_args *args)
{
	sem_unlink("/messages");
	if (!(args->messages = sem_open("/messages", O_CREAT, 0664, 1)))
		return (EXIT_FAILURE);
	sem_unlink("/picking");
	if (!(args->picking = sem_open("/picking", O_CREAT, 0644, 1)))
		return (EXIT_FAILURE);
	sem_unlink("/forks");
	if (!(args->forks = sem_open("/forks", O_CREAT, 0644, args->args[N_PHILO])))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			init_philosophers(t_args *args, int n)
{
	if (!(args->philos = (t_philo *)malloc(sizeof(t_philo) * n)))
		return (EXIT_FAILURE);
	if (init_struct(args) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (n-- > 0)
		args->philos[n] = init_philo(args, n);
	if (init_sem(args) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
