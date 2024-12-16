/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eating_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:41:12 by drosales          #+#    #+#             */
/*   Updated: 2024/12/16 19:54:00 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_eating_checker(t_philo *philos)
{
	int	eating_times;
	int	i;

	eating_times = 0;
	i = 0;
	if (philos->eat_time_needed < 0)
		return (0);
	while (i++ < philos[0].philos_no)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].eat_time_needed)
			eating_times++;
		pthread_mutex_unlock(philos[i].meal_lock);
	}
	if (philos[i].eat_time_needed == philos[i].philos_no)
	{
		pthread_mutex_lock(philos[i].dead_lock);
		*(philos)->dead = 1;
		pthread_mutex_unlock(philos[i].dead_lock);
		return (1);
	}
	return (0);
}
