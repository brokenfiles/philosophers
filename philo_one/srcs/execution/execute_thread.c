/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:27:59 by louis             #+#    #+#             */
/*   Updated: 2020/09/19 19:33:07 by llaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"
#include "../../includes/declarations.h"

#include <printf.h>

t_philo		*philo_state(t_philo *p, PHILO_STATE state)
{
	p->state = state;
	return (p);
}

void		take_forks(t_philo *p)
{
	t_fork	*fork;
	int		index;

	index = 0;
	fork = (p->id + index) % 2 ? p->lr_forks[LEFT_FORK]
			: p->lr_forks[RIGHT_FORK];
	while (index < 2)
	{
		while (fork->id_last_philo == p->id)
			;
		pthread_mutex_lock(&fork->mutex);
		alert(current_time(*p->args), philo_state(p, FORKING));
		fork->id_last_philo = p->id;
		fork = (p->id + (++index)) % 2 ? p->lr_forks[LEFT_FORK]
				: p->lr_forks[RIGHT_FORK];
	}
}

void		*start_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (1)
	{
		take_forks(p);
		p->timeout = p->args->args[T_TO_DIE] + current_time(*(p->args));
		alert(current_time(*p->args), philo_state(p, EATING));
		pthread_mutex_lock(&p->eat);
		ft_usleep(p->args->args[T_TO_EAT] * 1000);
		pthread_mutex_unlock(&p->eat);
		pthread_mutex_unlock(&p->lr_forks[RIGHT_FORK]->mutex);
		pthread_mutex_unlock(&p->lr_forks[LEFT_FORK]->mutex);
		alert(current_time(*p->args), philo_state(p, SLEEPING));
		if (p->args->n_args > 4 &&
			++p->eat_count >= p->args->args[PHILO_MAX_EAT])
			break ;
		ft_usleep(p->args->args[T_TO_SLEEP] * 1000);
		alert(current_time(*p->args), philo_state(p, THINKING));
	}
	p->args->args[CURR_PHILO]--;
	p->fed = 1;
	return (NULL);
}
