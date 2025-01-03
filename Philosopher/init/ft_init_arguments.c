/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:25:00 by drosales          #+#    #+#             */
/*   Updated: 2024/12/16 19:14:49 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init_arguments(t_philo *philos, char **av)
{
	philos->time_to_die = ft_atoi(av[2]);
	philos->time_to_eat = ft_atoi(av[3]);
	philos->time_to_sleep = ft_atoi(av[4]);
	philos->philos_no = ft_atoi(av[1]);
	if (av[5])
		philos->eat_time_needed = ft_atoi(av[5]);
	else
		philos->eat_time_needed = -1;
}
