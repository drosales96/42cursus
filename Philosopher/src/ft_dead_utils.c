/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dead_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:04:03 by drosales          #+#    #+#             */
/*   Updated: 2024/12/16 19:41:00 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_dead_philo_checker(t_philo *philo, size_t dead_time)
{
	pthread_mutex_lock(philo->meal_lock);
	if (ft_get_times() - philo->last_meal >= philo->time_to_die \
		&& philo->eat == 0)
		return (pthread_mutex_unlock(philo->meal_lock), DEAD);
	return (pthread_mutex_unlock(philo->meal_lock), ALIVE);
}

int	ft_checking_all_philos(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].philos_no)
	{
		if (ft_dead_philo_checker(&philos[i], philos[i].time_to_die) == DEAD)
		{
			printf("Philosopher %d has dead\n", philos->id);
			pthread_mutex_lock(philos[0].dead_lock);
			philos->dead = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (DEAD);
		}
		i++;
	}
	return (ALIVE);
}
