/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:41:12 by drosales          #+#    #+#             */
/*   Updated: 2024/12/17 18:31:21 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_eating_checker(t_philo *philos)
{
	int	i;
	int	eating_times;

	i = 0;
	eating_times = 0;
	if (philos[0].eat_time_needed == -1)
		return (0);
	while (i < philos[0].philos_no)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].eat_time_needed)
			eating_times++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (eating_times == philos[0].philos_no)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (0);
}
