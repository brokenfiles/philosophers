/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declarations.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:01:36 by louis             #+#    #+#             */
/*   Updated: 2020/09/23 12:14:08 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECLARATIONS_H
# define DECLARATIONS_H

int			ft_error(const char *error_str);
int			parse_arguments(t_args *args, int ac, char **av);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			init_philosophers(t_args *args, int n);
int			start_philosophers(t_args *args);
int			ft_free_error(const char *error_str, void *mem);
int			clear_philo(t_args *args);
long int	current_time(t_args args);
void		ft_putstr(const char *str);
void		print_line(long int t, t_philo *p, PHILO_STATE state);
void		*start_routine(t_philo *arg);
void		alert(long int t, t_philo *p);
void		ft_putnbr(int nb);
void		ft_usleep(long n);
void		*philo_alive(void *mem);
char		*ft_itoa(int nbr);
#endif
