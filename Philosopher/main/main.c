/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:40:54 by drosales          #+#    #+#             */
/*   Updated: 2024/12/17 18:46:50 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_table			table;
	t_philo			philosophers[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (ac > 7)
		return (printf("Philosophers: ilogic use of arguments!\n"));
	if (ac != 5 && ac != 6)
		return (printf("Philosophers: philo needs 5 arguments!\n"), 1);
	if (ft_checking_arguments(av) == 1)
		return (1);
	ft_init_table(&table, philosophers);
	ft_init_forks(forks, ft_atoi(av[1]));
	ft_init_philos(philosophers, &table, forks, av);
	ft_threads(&table, forks);
	ft_destroy_threads(NULL, &table, forks);
	return (0);
}
