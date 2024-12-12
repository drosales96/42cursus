/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:40:54 by drosales          #+#    #+#             */
/*   Updated: 2024/12/12 21:09:37 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_table	table;
	t_philo	philosophers;

	(void)table;
	(void)philosophers;
	if (ac > 7)
		return (printf("Philosophers: ilogic use of arguments!\n"));
	if (ac != 5 && ac != 6)
		return (printf("Philosophers: philo needs 5 arguments!\n"), 1);
	if (ft_checking_arguments(av) == 0)
		printf("Argument checker ends with OK\n");
	else
		printf("Arguments checker ends with WRONG\n");
	return (0);
}
