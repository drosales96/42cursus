/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:21:29 by drosales          #+#    #+#             */
/*   Updated: 2024/12/12 20:29:14 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// #___C LIBRARIES____#

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>

// #____STRUCTURES____#

typedef struct s_philo
{
	pthread_t		threads;
	int				id;
	int				eat;
	int				meals_eaten;
	int				philos_no;
	int				eat_time_needed;
	int				*dead;
	size_t			last_meal;
	size_t			time_to_eat;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			starting_time;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_locl;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_table
{
	int				flag;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	t_philo			*philo;
}					t_table;

// # ------ UTILS ------ # //

int	ft_is_digit(int c);
int	ft_atoi(char *str);

// # ------ ARG HANDLER ------ # //

int	ft_validating_args(char	*av);
int	ft_checking_arguments(char **av);

#endif