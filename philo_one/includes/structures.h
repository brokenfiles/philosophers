/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:40:41 by louis             #+#    #+#             */
/*   Updated: 2020/09/03 19:11:50 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <zconf.h>
# define PHILO_STATE int
# define LEFT_FORK 0
# define RIGHT_FORK 1
# define N_PHILO 0
# define T_TO_DIE 1
# define T_TO_EAT 2
# define T_TO_SLEEP 3
# define PHILO_MAX_EAT 4
# define MAX_EAT_TOTAL 5
# define EATING 0
# define SLEEPING 1
# define THINKING 2
# define FORKING 3
# define DIED 4
# define FED 5
# define TRUE 1
# define FALSE 0

struct s_args;
typedef struct	s_philo {
	int				id;
	int				state;
	int				eat_count;
	long int		timeout;
	pthread_t		pthread;
	struct s_args	*args;
	pthread_mutex_t	eat;
	int				lr_forks[2];
}				t_philo;
typedef struct	s_args {
	int				n_args;
	int				args[6];
	int				total_philo_meal;
	t_philo			*philos;
	struct timeval	t_start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	fork_message;
}				t_args;
#endif
