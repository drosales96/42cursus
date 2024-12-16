/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:25:04 by drosales          #+#    #+#             */
/*   Updated: 2024/12/16 19:17:59 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init_philos(t_philo *philos, t_table *table, \
				pthread_mutex_t *forks, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].id = i - 1;
		philos[i].eat = 0;
		philos[i].meals_eaten = 0;
		philos[i].time_to_eat = ft_get_times();
		philos[i].time_to_sleep = ft_get_times();
		philos[i].time_to_die = ft_get_times();
		philos[i].last_meal = ft_get_times();
		philos[i].starting_time = ft_get_times();
		philos[i].meal_lock = &table->meal_lock;
		philos[i].dead_lock = &table->dead_lock;
		philos[i].write_lock = &table->write_lock;
		ft_init_arguments(&philos[i], av);
		philos[i].left_fork = &forks[i];
		if (i == 0)
			philos[i].right_fork = &forks[philos[i].philos_no - 1];
		else
			philos[i].right_fork = &forks[i - 1];
	}
}
