/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:27:59 by louis             #+#    #+#             */
/*   Updated: 2020/09/07 16:21:56 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"
#include "../../includes/declarations.h"

t_philo		*philo_state(t_philo *p, PHILO_STATE state)
{
	p->state = state;
	return (p);
}

void		take_forks(t_philo *p)
{
	pthread_mutex_lock(&p->args->forks[(p->lr_forks[RIGHT_FORK])]);
	alert(current_time(*p->args), philo_state(p, FORKING));
	pthread_mutex_lock(&p->args->forks[(p->lr_forks[LEFT_FORK])]);
	alert(current_time(*p->args), philo_state(p, FORKING));
}

void		*start_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&p->args->picking);
		take_forks(p);
		pthread_mutex_unlock(&p->args->picking);
		p->timeout = p->args->args[T_TO_DIE] + current_time(*(p->args));
		alert(current_time(*p->args), philo_state(p, EATING));
		pthread_mutex_lock(&p->eat);
		usleep(p->args->args[T_TO_EAT] * 1000);
		pthread_mutex_unlock(&p->eat);
		pthread_mutex_unlock(&p->args->forks[(p->lr_forks[RIGHT_FORK])]);
		pthread_mutex_unlock(&p->args->forks[(p->lr_forks[LEFT_FORK])]);
		alert(current_time(*p->args), philo_state(p, SLEEPING));
		if (p->args->n_args > 4 &&
			++p->eat_count >= p->args->args[PHILO_MAX_EAT])
			break ;
		usleep(p->args->args[T_TO_SLEEP] * 1000);
		alert(current_time(*p->args), philo_state(p, THINKING));
	}
	p->args->args[CURR_PHILO]--;
	p->fed = 1;
	return (NULL);
}
