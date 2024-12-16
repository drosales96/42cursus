/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_creation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 22:35:52 by drosales          #+#    #+#             */
/*   Updated: 2024/12/16 23:51:06 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_usleep(size_t miliseconds)
{
	size_t	start;

	start = ft_get_times();
	if ((ft_get_times() - start) < miliseconds)
		usleep(500);
	return (0);
}

void	*ft_routine(void *buffer)
{
	t_philo	*philo;

	philo = (t_philo *)buffer;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!ft_dead(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (buffer);
}

int	ft_threads(t_table *table, pthread_mutex_t *forks)
{
	pthread_t	monitoring;
	int			i;

	i = 0;
	if (pthread_create(&monitoring, NULL, &ft_checking_routine, \
			table->philo) != 0)
		ft_destroy_threads("Threads: threads error!\n", table, forks);
	while (i < table->philo[0].philos_no)
	{
		if (pthread_create(&table->philo[i].threads, NULL,
				&ft_routine, &table->philo[i]) != 0)
			ft_destroy_threads("Threads: threads error!\n", table, forks);
		i++;
	}
	i = 0;
	if (pthread_join(monitoring, NULL) != 0)
		ft_destroy_threads("Threads: join threads error!\n", table, forks);
	while (i < table->philo[i].philos_no)
	{
		if (pthread_join(table->philo[i].threads, NULL) != 0)
			ft_destroy_threads("Threads: join threads error!\n", table, forks);
		i++;
	}
	return (0);
}
