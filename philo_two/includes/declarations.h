/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declarations.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:01:36 by louis             #+#    #+#             */
/*   Updated: 2020/09/25 12:50:47 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECLARATIONS_H
# define DECLARATIONS_H
# if defined(__unix__) || !defined(__APPLE__) && defined(__MACH__)
#  define LINUX 1
# else
#  define LINUX 0
# endif

int			ft_error(const char *error_str);
int			parse_arguments(t_args *args, int ac, char **av);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			init_philosophers(t_args *args, int n);
void		ft_putstr(const char *str);
int			start_philosophers(t_args *args);
void		*start_routine(void *arg);
long int	current_time(t_args args);
void		alert(long int t, t_philo *p);
int			clear_philo(t_args *args);
int			ft_free_error(const char *error_str, void *mem);
char		*ft_itoa(int nbr);
void		ft_putnbr(int nb);
void		ft_usleep(long n);
#endif
