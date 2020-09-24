/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:40:41 by louis             #+#    #+#             */
/*   Updated: 2020/09/24 09:48:11 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <pthread.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>

# define PHILO_STATE int
# define N_PHILO 0
# define T_TO_DIE 1
# define T_TO_EAT 2
# define T_TO_SLEEP 3
# define PHILO_MAX_EAT 4
# define CURR_PHILO 5
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
	pid_t			pid;
	int				state;
	int				eat_count;
	int				fed;
	long int		timeout;
	pthread_t		pthread;
	struct s_args	*args;
	sem_t			*eat;
}				t_philo;
typedef struct	s_args {
	int				n_args;
	int				args[6];
	int				state;
	t_philo			*philos;
	struct timeval	t_start;
	sem_t			*forks;
	sem_t			*messages;
	sem_t			*stop;
	sem_t			*death;
}				t_args;
#endif
