/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 13:45:57 by louis             #+#    #+#             */
/*   Updated: 2020/09/07 14:54:24 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structures.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

int			init_struct(t_args *args)
{
	args->philo_dead = 0;
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

	philo.lr_forks[LEFT_FORK] = (id + 1 == args->args[N_PHILO]) ? 0 : (id + 1);
	philo.lr_forks[RIGHT_FORK] = id;
	philo.id = id;
	philo.args = args;
	philo.fed = 0;
	philo.eat_count = 0;
	philo.state = THINKING;
	pthread_mutex_init(&philo.eat, NULL);
	pthread_mutex_unlock(&philo.eat);
	philo.timeout = args->args[T_TO_DIE] + current_time(*args);
	return (philo);
}

int			init_mutex(t_args *args)
{
	int	index;

	index = 0;
	while (index < args->args[N_PHILO])
	{
		pthread_mutex_init(&args->forks[index], NULL);
		pthread_mutex_unlock(&args->forks[index]);
		index++;
	}
	pthread_mutex_init(&args->fork_message, NULL);
	pthread_mutex_unlock(&args->fork_message);
	pthread_mutex_init(&args->picking, NULL);
	pthread_mutex_unlock(&args->picking);
	return (EXIT_SUCCESS);
}

int			init_philosophers(t_args *args, int n)
{
	if (!(args->philos = (t_philo *)malloc(sizeof(t_philo) * n)))
		return (EXIT_FAILURE);
	if (!(args->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n)))
		return (EXIT_FAILURE);
	while (n-- > 0)
		args->philos[n] = init_philo(args, n);
	if (init_struct(args) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_mutex(args) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
