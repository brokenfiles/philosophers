/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 20:36:59 by louis             #+#    #+#             */
/*   Updated: 2020/09/03 17:45:02 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "../includes/structures.h"
#include "../includes/declarations.h"
#include "../libs/printf/includes/printf.h"

void	debug(t_args args)
{
	int index = 0;
	while (index < args.n_args) {
		printf("arg[%d] = %d\n", index, args.args[index]);
		index++;
	}
	printf("\nphilosophers : \n");
	index = 0;
	while (index < args.args[N_PHILO])
	{
		char * state;
		t_philo p = args.philos[index];
		if (p.state == THINKING)
			state = "THINKING";
		else if (p.state == SLEEPING)
			state = "SLEEPING";
		else if (p.state == EATING)
			state = "EATING";
		else
			state = "TG";
		printf("philo #%d : \n id : %d\n state : %s\n right fork : %d, left fork : %d\n", p.id, p.id, state, p.lr_forks[RIGHT_FORK], p.lr_forks[LEFT_FORK]);
		index++;
	}
}

int	main(int ac, char **av)
{
	t_args *args;

	if (!(ac == 5 || ac == 6))
		return (ft_error("Argument number is invalid.\n"));
	if (!(args = (t_args *)malloc(sizeof(t_args))))
		return (EXIT_FAILURE);
	if (parse_arguments(args, ac, av) == EXIT_FAILURE)
		return (ft_error("Arguments invalid.\n"));
	if (init_philosophers(args, args->args[N_PHILO]) == EXIT_FAILURE)
		return (ft_error("Cannot init philosophers.\n"));
//	debug(*args);
	start_philosophers(args);
	return (EXIT_SUCCESS);
}
