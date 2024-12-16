/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:21:29 by drosales          #+#    #+#             */
/*   Updated: 2024/12/16 23:42:47 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// # ------ C LIBRARIES ------ # //

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>

// # ------ DEFINES ------ # //

# define TIME_ERROR -1
# define DEAD 1
# define ALIVE 0

// # ------ STRUCTURES ------ # //

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
	pthread_mutex_t	*dead_lock;
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

int		ft_is_digit(int c);
int		ft_atoi(char *str);

// # ------ ARG HANDLER ------ # //

int		ft_validating_args(char	*av);
int		ft_checking_arguments(char **av);

// # ------ INIT ------ # //

void	ft_init_table(t_table *table, t_philo *philo);
void	ft_init_forks(pthread_mutex_t *forks, int philos);
void	ft_init_philos(t_philo *philos, t_table *table,
			pthread_mutex_t *forks, char **av);
void	ft_init_arguments(t_philo *philos, char **av);

// # ------ UTILS ------ # //

size_t	ft_get_times(void);
int		ft_dead_philo_checker(t_philo *philo, size_t dead_time);
int		ft_checking_all_philos(t_philo *philos);
int		ft_eating_checker(t_philo *philos);
void	*ft_checking_routine(void *ptr);
void	ft_destroy_threads(char *str, t_table *table,
			pthread_mutex_t *forks);
int		ft_usleep(size_t miliseconds);
int		ft_dead(t_philo *philo);
void	*ft_routine(void *buffer);
void	ft_print_status(char *str, t_philo *philo, int id);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_eat(t_philo *philo);
int		ft_threads(t_table *table, pthread_mutex_t *forks);

#endif