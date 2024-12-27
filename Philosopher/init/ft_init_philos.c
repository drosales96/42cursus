/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:25:04 by drosales          #+#    #+#             */
/*   Updated: 2024/12/17 18:16:23 by drosales         ###   ########.fr       */
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
		philos[i].id = i + 1;
		philos[i].eat = 0;
		philos[i].meals_eaten = 0;
		ft_init_arguments(&philos[i], av);
		philos[i].starting_time = ft_get_times();
		philos[i].last_meal = ft_get_times();
		philos[i].write_lock = &table->write_lock;
		philos[i].dead_lock = &table->dead_lock;
		philos[i].meal_lock = &table->meal_lock;
		philos[i].dead = &table->flag;
		philos[i].left_fork = &forks[i];
		if (i == 0)
			philos[i].right_fork = &forks[philos[i].philos_no - 1];
		else
			philos[i].right_fork = &forks[i - 1];
		i++;
	}
}
