/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:40:54 by drosales          #+#    #+#             */
/*   Updated: 2024/12/14 12:25:28 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_table			table;
	t_philo			*philosophers;
	pthread_mutex_t	*forks;
	
	philosophers = NULL;
	forks = NULL;
	if (ac > 7)
		return (printf("Philosophers: ilogic use of arguments!\n"));
	if (ac != 5 && ac != 6)
		return (printf("Philosophers: philo needs 5 arguments!\n"), 1);
	ft_checking_arguments(av);
	ft_init_table(&table, philosophers);
	ft_init_forks(forks, ft_atoi(av[1]));
	ft_init_philos(philosophers, &table, forks, av);
	return (0);
}
