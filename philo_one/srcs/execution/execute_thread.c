/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 10:27:59 by louis             #+#    #+#             */
/*   Updated: 2020/09/03 18:59:43 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structures.h>
#include <pthread.h>
#include <declarations.h>

t_philo		*philo_state(t_philo *p, PHILO_STATE state)
{
	p->state = state;
	return (p);
}

void		*start_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(&p->args->forks[(p->lr_forks[RIGHT_FORK])]);
		alert(current_time(*p->args), philo_state(p, FORKING));
		pthread_mutex_lock(&p->args->forks[(p->lr_forks[LEFT_FORK])]);
		alert(current_time(*p->args), philo_state(p, FORKING));
		p->timeout = p->args->args[T_TO_DIE] + current_time(*(p->args));
		alert(current_time(*p->args), philo_state(p, EATING));
		pthread_mutex_lock(&p->eat);
		usleep(p->args->args[T_TO_EAT] * 1000);
		p->eat_count++;
		p->args->total_philo_meal++;
		pthread_mutex_unlock(&p->eat);
		pthread_mutex_unlock(&p->args->forks[(p->lr_forks[RIGHT_FORK])]);
		pthread_mutex_unlock(&p->args->forks[(p->lr_forks[LEFT_FORK])]);
		alert(current_time(*p->args), philo_state(p, SLEEPING));
		usleep(p->args->args[T_TO_SLEEP] * 1000);
		alert(current_time(*p->args), philo_state(p, THINKING));
	}
	return (NULL);
}